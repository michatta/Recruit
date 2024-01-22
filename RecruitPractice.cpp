#include "Recruit.h"

int count = 0;
//로그인, 회원가입을 수행하는 함수

void Listup::RandomListup()
{
    system("clear");
    cout <<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

    sqlite3* db;
    char *err_msg = 0;

    int rc = sqlite3_open("job.db", &db);

    string sql = "SELECT 회사코드,공고명,필요스킬, 근무지역, 담당업무 FROM Recruit ORDER BY RANDOM() LIMIT 3;";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &err_msg);

    sqlite3_close(db);
    sleep(3);

    BasicSearch();

}
int Listup::callback(void *NotUsed,int argc,char **argv, char **azColName)
{   
    NotUsed = 0;
    cout << "[회사 코드]";

    for (int i = 0; i < argc; i++)
    {
        cout <<  "  |  " <<  argv[i];

    }
    cout << endl << endl;
    return 0;
}
void Listup::BasicSearch()
{   //asd 1234
    Membership a;
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt * res;
    
    system("clear");
    int rc = sqlite3_open("job.db", &db);
    string count;
    string sch;
    string ch;
    cout <<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "단어를 검색하면 관련있는 취업 정보를 안내해드립니다. 1. 기본 검색 2. 상세 검색 0. 뒤로 가기 : ";
    getline(cin,sch);
    sleep(2);

    if(sch == "0")
        a.page1();
    else if(sch == "2")
        DetailSearch();
        
    //system("clear");
    string sql = "SELECT 회사코드, 회사명, 공고명, 담당업무, 필요스킬, 우대사항, 산업 FROM Recruit WHERE 필요스킬 LIKE '%"+sch+"%' OR 담당업무 LIKE '%"+sch+"%' OR 우대사항 LIKE '%"+sch+"%' OR 학력 LIKE '%"+sch+"%' OR 경력 LIKE '%"+sch+"%' OR 고용형태 LIKE '%"+sch+"%' OR  공고명 LIKE '%"+sch+"%';";
    string sql2 = "SELECT COUNT(공고명) FROM Recruit WHERE 필요스킬 LIKE '%"+sch+"%' OR 담당업무 LIKE '%"+sch+"%' OR 우대사항 LIKE '%"+sch+"%' OR 학력 LIKE '%"+sch+"%' OR 경력 LIKE '%"+sch+"%' OR 고용형태 LIKE '%"+sch+"%';";
    cout << endl << "< " << sch + " > 단어 관련 기업 공고 \n\n";
    
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &err_msg);
    rc=sqlite3_prepare_v2(db,sql2.c_str(),-1,&res,nullptr);

    while((rc=sqlite3_step(res))==SQLITE_ROW)
    {
        count = reinterpret_cast<const char*>(sqlite3_column_text(res,0));
        cout << "현재 관련 공고의 검색 수는 " << count << "건입니다. \n"; 
    }
    sqlite3_finalize(res);
    sqlite3_close(db);

    if (count == "0")
    {
        cout << "검색어와 관련 있는 공고가 존재하지 않습니다. 다시 입력해주세요. 0. 뒤로가기 \n";
        BasicSearch();
    }

    cout << "더 자세한 정보를 알고 싶으시면 회사 코드를 입력해주세요 : ";
    string code;
    getline(cin,ch);
    ShowDetail(ch);

}
void Listup::DetailSearch()
{   
    sqlite3 *db;
    char *err_msg = 0;
    string h, c, p;
    int rc = sqlite3_open("job.db", &db);
    cout << "상세 검색을 시작하겄습니다." << endl;
    cout << "1. 학력 [학력무관 | 대졸 | 초대졸 | 고졸] : ";
    getline(cin, h);

    cout << "\n2. 경력 [신입 | 경력] : ";
    getline(cin, c);

    cout << "\n3. 근무지 [서울 | 경기 | 충남 | 대구 | 부산 | 인천 | 광주] : ";
    getline(cin, p);

    string sql = "SELECT 회사코드, 회사명, 공고명, 담당업무, 필요스킬, 우대사항, 산업 FROM Recruit WHERE 학력 LIKE '%"+h+"%' AND 경력 LIKE '%"+c+"%' AND 근무지역 LIKE '%"+p+"%';";
    
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &err_msg);

    sqlite3_close(db);

    cout << "더 자세한 정보를 알고 싶으시면 회사 코드를 입력해주세요. 0. 뒤로가기 : ";
    string a;
    getline(cin, a);

    if(a=="0")
        BasicSearch();
    else
        ShowDetail(a);
    
}
void Listup::ShowDetail(string num)
{   
    cout << "현재 입력된 회사 코드는 " << num << " 입니다." << endl;
    int ch;
    cout << "\n1. 공고 상세 보기 2. 기업 정보 상세 보기 0. 뒤로 가기 : ";
    cin >> ch;

    if(ch == 1)
        ShowOpening(num);
    else if(ch == 2)
        ShowCorporate(num);
    else if(ch == 0)
        BasicSearch();
    sleep(3);
}
void Listup::ShowOpening(string Snum) // 공고 상세 정보 보여주기
{
    system("clear");

    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt * res;

    int rc = sqlite3_open("job.db", &db);
    string sql = "SELECT 공고명, 경력, 학력, 고용형태, 담당업무, 필요스킬, 우대사항 FROM Recruit WHERE 회사코드 = '"+Snum+"';";
    string notice, career, education, work, skill, prio;
    rc=sqlite3_prepare_v2(db,sql.c_str(),-1,&res,nullptr);

    while((rc=sqlite3_step(res))==SQLITE_ROW)
    {   cout <<"=================공고 상세 정보================="<< endl;
        notice=reinterpret_cast<const char*>(sqlite3_column_text(res,0));
        career=reinterpret_cast<const char*>(sqlite3_column_text(res,1));
        education=reinterpret_cast<const char*>(sqlite3_column_text(res,2));
        work=reinterpret_cast<const char*>(sqlite3_column_text(res,3));
        skill=reinterpret_cast<const char*>(sqlite3_column_text(res,4));
        prio=reinterpret_cast<const char*>(sqlite3_column_text(res,5));
        cout << "공고명 : " << notice << endl;
        cout << "경력 : " << career << endl;
        cout << "학력 : " << education << endl;
        cout << "담당업무 : " << work << endl;
        cout << "필요스킬 : " << skill << endl;
        cout << "우대사항 : " << prio << endl;
    }
    cout << "==================================================" << endl;
    sqlite3_finalize(res);
    sqlite3_close(db);

    cout << "1. 기업 상세 정보 보기 0. 뒤로 가기 : ";
    int a;
    cin >> a;
    cin.ignore();

    if (a == 1)
        ShowCorporate(Snum);
    else if(a == 0)
        BasicSearch();

}
void Listup::ShowCorporate(string Snum) // 기업 상세 정보 보여주기
{
    system("clear");
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt * res;

    int rc = sqlite3_open("job.db", &db);
    string sql = "SELECT 회사명, 근무지역, 산업, 기업형태, 설립년도, 사원수, 홈페이지 FROM Recruit WHERE 회사코드 = '"+Snum+"';";
    string company, place, industry, form, year, people, homepage;
    rc=sqlite3_prepare_v2(db,sql.c_str(),-1,&res,nullptr);

    while((rc=sqlite3_step(res))==SQLITE_ROW)
    {   cout <<"=================기업 상세 정보================="<< endl;
        company=reinterpret_cast<const char*>(sqlite3_column_text(res,0));
        place=reinterpret_cast<const char*>(sqlite3_column_text(res,1));
        industry=reinterpret_cast<const char*>(sqlite3_column_text(res,2));
        form=reinterpret_cast<const char*>(sqlite3_column_text(res,3));
        year=reinterpret_cast<const char*>(sqlite3_column_text(res,4));
        people=reinterpret_cast<const char*>(sqlite3_column_text(res,5));
        homepage=reinterpret_cast<const char*>(sqlite3_column_text(res,6));
        cout << "회사명 : " << company << endl;
        cout << "근무지역 : " << place << endl;
        cout << "산업 : " << industry << endl;
        cout << "기업형태 : " << form << endl;
        cout << "설립년도 : " << year << endl;
        cout << "사원 수 : " << people << endl;
        cout << "홈페이지 : " << homepage << endl;
    }
    cout << "==================================================" << endl;
    sqlite3_finalize(res);
    sqlite3_close(db);

    cout << "1. 공고 상세 정보 보기 0. 뒤로 가기 : ";
    int a;
    cin >> a;
    cin.ignore();

    if (a == 1)
        ShowOpening(Snum);
    else if(a == 0)
        BasicSearch();
        
}


void Membership::page1() //시작 화면
{
    system("clear");
    string ch;
    string line;
    ifstream file("RecruitLogo");
    if (file.is_open())
    {
        while (getline(file, line))
            cout << line << endl;
        file.close();
    }
    else
        cout << "Unable to open file";

    cout << "|| 1. 로그인\n  |";
    cout << "| 2. 회원가입\n|";
    cout << "| 3. 종료\n    \n";
    cout << "|| 번호 입력 : ";
    getline(cin,ch);

    if(ch == "1")
        LoginMember();
    else if(ch == "2")
        JoinMember();
    else if(ch == "3")
        Exit();
}
void Membership::JoinMember() //회원가입하는 함수 + 중복검사를 수행한다. 중복검사가 끝나면 database에 insert한다.
{
    srand((unsigned int)time(NULL));
    sqlite3 *db;
    char *err_msg = 0;
    //sqlite3_stmt* res;
    
    int rc = sqlite3_open("job.db", &db);
    while(1)
    {
        sqlite3_stmt* res;
        cout << "ID를 입력해주세요!: ";
        getline(cin,ID);
        string sql = "SELECT ID FROM Login WHERE ID ='"+ID+"';";

        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);
        rc = sqlite3_step(res);

        if(rc == SQLITE_ROW)
        {
            cout << "중복된 ID입니다." << endl;
            sqlite3_finalize(res);
            //sqlite3_close(db);
            continue;
        }
        break;
    }

    cout << endl;
    cout << "비밀번호를 입력해주세요! : ";
    while(1)
    {
        getline(cin,PW);
        if(PW.size() != 4)
            cout << "비밀번호는 핀 4자리로 입력하시는게 어떠한 그런? ";
        else
            break;
    }
    
    cout << endl;
    while(1)
    {
        sqlite3_stmt* res;
        cout << "이메일을 입력해주세요! : ";
        getline(cin,EMAIL);
        string sql = "SELECT EMAIL FROM Login WHERE EMAIL ='"+EMAIL+"';";

        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);
        rc = sqlite3_step(res);

        if(rc == SQLITE_ROW)
        {
            cout << "중복된 이메일입니다." << endl;
            sqlite3_finalize(res);
            //sqlite3_close(db);
            continue;
        }
        break;
    }

    cout << endl;
    while(1)
    {
        sqlite3_stmt* res;
        cout << "전화번호를 입력해주세요! : ";
        getline(cin,PHONE);
        string sql = "SELECT PHONE FROM Login WHERE PHONE ='"+PHONE+"';";

        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);
        rc = sqlite3_step(res);

        if(rc == SQLITE_ROW)
        {
            cout << "중복된 전화번호입니다." << endl;
            sqlite3_finalize(res);
            continue;
        }
        break;
    }
    cout << "\n회원가입이 완료되었습니다!\n";
    SNUMBER = rand()%1000;

    string sql = "INSERT INTO Login (ID,PW,EMAIL,PHONE,SNUMBER) VALUES('"+ID+"',"+PW+",'"+EMAIL+"','"+PHONE+"','"+to_string(SNUMBER)+"');";
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg);
    sqlite3_close(db);

    sleep(3);
    page1();

}
void Membership::LoginMember() //로그인하는 함수
{
    Listup b;
    cout << "\nID를 입력하세요 : ";
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt* res;
    
    int rc = sqlite3_open("job.db", &db);
    //cin.ignore();
    while(1)
    {
        getline(cin,ID);
        string sql = "SELECT ID FROM Login WHERE ID ='"+ID+"';";

        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);
        rc = sqlite3_step(res);

        if(rc == SQLITE_ROW)
        {
            cout << "ID 확인되셨습니다." << endl;
            sqlite3_finalize(res);
            //sqlite3_close(db);
            break;
        }
        cout << "없는 ID입니다. 재입력구다사이- : ";
    }
    cout << endl;
    cout << "비밀번호를 입력하세요 : ";
    while(1)
    {
        getline(cin,PW);
        string sql = "SELECT PW FROM Login WHERE ID = '"+ID+"' AND PW ='"+PW+"';";

        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);
        rc = sqlite3_step(res);

        if(rc == SQLITE_ROW)
        {   
            cout << "비밀번호 확인되셨습니다." << endl;
            sqlite3_finalize(res);
            //sqlite3_close(db);
            break;
        }
        cout << "없는 비밀번호 또는 입력하신 아이디와 일치하지 않습니다. 재입력구다사이- : ";
    }
    cout << endl;
    cout << "로그인 되셨습니다! " << endl;
    sqlite3_close(db);
    sleep(3);

    b.RandomListup();
}
void Membership::Exit()
{
    exit (0);
}
