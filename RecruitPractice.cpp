#include <sqlite3.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

using namespace std;
int count = 0;
//로그인, 회원가입을 수행하는 함수
class Membership
{
public:
    void page1(); //로고 보여주는 함수
    void JoinMember();  //DB에 입력받고 중복검사를 하는 함수
    void LoginMember(); //로그인하는 함수
    void Exit(); // 종료하는 함수
private:
    string ID;
    string PW;
    string EMAIL;
    string PHONE;
    int SNUMBER;

};
void Membership::page1() //시작 화면
{
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

}
void Membership::LoginMember() //로그인하는 함수
{
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
}
void Membership::Exit()
{
    exit (0);
}











//기업 공고 list를 랜덤하게 보여주는 클래스
class Listup
{
public:
    void RandomListup(); // 무작위로 3개의 기업 공고를 추출하고 callback함수를 통해 print한다. 
    static int callback(void *NotUsed,int argc,char **argv, char **azColName); //안에 column값을 프린트해주는 함수
    void BasicSearch();
    //void DetailSearch();
    void ShowDetail(string Snum);
    void ShowCorporate(string Snum);
    void ShowOpening(string Snum);
};
void Listup::RandomListup()
{
    system("clear");
    cout <<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";


    sqlite3* db;
    char *err_msg = 0;

    int rc = sqlite3_open("job.db", &db);

    string sql = "SELECT 공고명,필요스킬, 근무지역, 담당업무 FROM Recruit ORDER BY RANDOM() LIMIT 3;";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &err_msg);

    sqlite3_close(db);
    sleep(3);

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
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt * res;

    int rc = sqlite3_open("job.db", &db);
    string count;
    string sch;
    string ch;
    cout <<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "단어를 검색하면 관련있는 취업 정보를 안내해드립니다. ";
    getline(cin,sch);
    sleep(2);

    //system("clear");
    string sql = "SELECT 회사코드, 회사명, 공고명, 담당업무, 필요스킬, 우대사항, 산업 FROM Recruit WHERE 필요스킬 LIKE '%"+sch+"%' OR 담당업무 LIKE '%"+sch+"%' OR 우대사항 LIKE '%"+sch+"%' OR 학력 LIKE '%"+sch+"%' OR 경력 LIKE '%"+sch+"%' OR 고용형태 LIKE '%"+sch+"%';";
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

    cout << "더 자세한 정보를 알고 싶으시면 회사 코드를 입력해주세요 : ";
    string code;
    getline(cin,ch);
    ShowDetail(ch);

}
void Listup::ShowDetail(string num)
{   
    cout << "현재 입력된 회사 코드는 " << num << " 입니다." << endl;
    int ch;
    cout << "\n1. 공고 상세 보기 2. 기업 정보 상세 보기 3. 뒤로 가기 : ";
    cin >> ch;

    if(ch == 1)
        ShowOpening(num);
    else if(ch == 2)
        ShowCorporate(num);
    else if(ch == 3)
        BasicSearch();
    sleep(3);
}
void Listup::ShowOpening(string Snum) // 공고 상세 정보 보여주기
{
    system("clear");
    //cout << "공고 상세 정보" << endl;

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

    cout << "1. 기업 상세 정보 보기 2. 뒤로 가기";
    int a;
    cin >> a;
    cin.ignore();

    if (a == 1)
        ShowCorporate(Snum);
    else if(a == 2)
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

    cout << "1. 공고 상세 정보 보기 2. 뒤로 가기";
    int a;
    cin >> a;
    cin.ignore();

    if (a == 1)
        ShowCorporate(Snum);
    else if(a == 2)
        BasicSearch();
}
// void Listup::DetailSearch()
// {
//     string s;
//     cout << "현재 결과에서 상세 검색하시겠습니까?" << endl;
//     cout << "[1. 학력] [2. 필요스킬] [3. 근무지]" << endl;

//     while(1)
//     {
//         cout << "학력 : " << endl;
//         cout << "필요스킬 : " << endl;
//         cout << "근무지 : " << endl;
//     }
// }






int main(void)
{
    int ch;
    Membership a;
    Listup b;

    a.page1();

    cin >> ch;
    cin.ignore();

    if (ch == 1) // 로그인하기를 눌렀을 때
    {
        a.LoginMember();
        b.RandomListup();
        b.BasicSearch();
    }

    else if(ch==2) // 회원가입하기를 눌렀을 때
    {
        a.JoinMember();
    }

    else if(ch==3) // 종료하기를 눌렀을 때
        a.Exit();

}

// void test() //공고출력
// {
//     sqlite3 *db; //핸들, 파일디스크립터같은
//     char *err_msg = 0; // 오류메시지
//     sqlite3_stmt* res;
//     int rc = sqlite3_open("/home/aiot11/Downloads/worknet", &db); //열고
//     std::string name, career, Type, Members, Sales, Sectors, education, Boss, Address, Job;
//     // std::string sql="SELECT * FROM resume;";
//     std::string sql = "SELECT 회사명, 경력, 학력 FROM resume ORDER BY RANDOM();";

//     rc=sqlite3_prepare_v2(db,sql.c_str(),-1,&res,nullptr);

//     while((rc=sqlite3_step(res))==SQLITE_ROW)
//     {
//         name = reinterpret_cast<const char*>(sqlite3_column_text(res,0));
//         career=reinterpret_cast<const char*>(sqlite3_column_text(res,1));
//         education=reinterpret_cast<const char*>(sqlite3_column_text(res,2));
//         // Members=reinterpret_cast<const char*>(sqlite3_column_text(res,3));
//         // Sales=reinterpret_cast<const char*>(sqlite3_column_text(res,4));
//         // Sectors=reinterpret_cast<const char*>(sqlite3_column_text(res,5));
//         // education=reinterpret_cast<const char*>(sqlite3_column_text(res,6));
//         // Boss=reinterpret_cast<const char*>(sqlite3_column_text(res,7));
//         // Address=reinterpret_cast<const char*>(sqlite3_column_text(res,8));
//         // Job=reinterpret_cast<const char*>(sqlite3_column_text(res,9));
//         system("clear");
//         std::cout<< "회사명: "<< name << std::endl;
//         std::cout<< "경력: " << career<< std::endl;
//         std::cout<< "학력: " << education << std::endl;
//     }
//     sqlite3_finalize(res); //SQL 쿼리 핸들 정리
//     sqlite3_close(db); //DB 닫기
// }