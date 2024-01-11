#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;
int log_count = 0;
// 스포츠 정보 클래스
class SportsInformation
{
public:
    void KoreaList(); // 한국 선수팀 명단
    void GroupList(); // 조별 리스트
    void GroupPlay(); // 조별 경기
    void Overall();   // 경기 일정 & 개최지
    void Sportspage();
};
void SportsInformation::Sportspage()
{
    cout << "------------------------" << endl;
    cout << "1. 경기 일정 & 개최지" << endl;
    cout << "2. 참가국 및 조별 리스트" << endl;
    cout << "3. 조별 경기 일정" << endl;
    cout << "4. 한국 선수팀 명단" << endl;
    cout << "------------------------" << endl;
}
void SportsInformation::Overall()
{ // 경기 일정 및 개최지 정보
    string line;
    ifstream file("Overall");
    if (file.is_open())
    {
        while (getline(file, line))
            cout << line << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}
void SportsInformation::KoreaList()
{
    string line;
    ifstream file("KoreaList");
    if (file.is_open())
    {
        while (getline(file, line))
            cout << line << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}
void SportsInformation::GroupList()
{
    string line;
    ifstream file("GroupList");
    if (file.is_open())
    {
        while (getline(file, line))
            cout << line << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}
void SportsInformation::GroupPlay()
{
    string line;
    ifstream file("GroupPlay");
    if (file.is_open())
    {
        while (getline(file, line))
            cout << line << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

// 경기 예매 클래스
class MatchReservation
{
public:
    void ReservationPage(int mnum);
    void MatchPlace();
    void MatchDay();
    int Money(string l);
    void LastReservationCheck();
    void FileSave();
    void ReservDu();
    void ReservCHeck(int renum);

private:
    int mnum_;
    int money;
    vector<string> reserv;
    vector<int> money_;
    vector<string> day;
    vector<string> place;
    vector<string> matchday = {"2024.01.15 대한민국 VS 바레인", "2024.01.16 말레이시아 VS 요르단","2024.01.20 요르단 VS 대한민국", "2024.01.20 바레인 VS 말레이시아","2024.01.25 대한민국 VS 말레이시아","2024.01.25 요르단 VS 바레인"};
    vector<string> reservnum;
};
void MatchReservation::ReservCHeck(int renum)
{
    cout << "회원번호로 예매 내역을 확인하겠습니다." << endl;
        ifstream file("reserv.csv");
        if(file.is_open())
        {   string line;
            while(!file.eof()){
                getline(file, line);
                string a;
                int i = 0;

                string s = line; // 한줄씩 string 형식으로 읽어오기 위해서
                stringstream ss(s);
                while(getline(ss, a,','))
                {   
                    if(i==0)
                        day.push_back(a);
                    if(i==1)
                        place.push_back(a);
                    if(i==2)
                    {
                        reservnum.push_back(a);
                        i = 0;
                    }
                    i++;
                }
            }
            file.close();
            for(int i =0; i<reservnum.size();i++)
                {
                    if(stoi(reservnum[i]) == renum)
                    {
                        cout << "현재 예매 내역 " << endl;
                        cout << "경기 일정 : " << matchday[stoi(day[i])-1] << endl;
                        cout << "경기 좌석 : " << place[i] << endl; 
                    }
                }
        }
    else
        cout << "현재 예매내역은 없습니다. " << endl;
    
}

void MatchReservation::MatchDay()
{
    // 파일 입출력
    cout << "원하는 날짜를 고르세요 : " << endl;
    string line;
    ifstream file("MatchDay");
    if (file.is_open())
    {
        while (getline(file, line))
            cout << line << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    cout << "어느 날짜로 하시겠습니까? 숫자로 입력해주세요 : ";
    getline(cin, line);
    reserv.push_back(line);
    day.push_back(line);
    MatchPlace();
}
void MatchReservation::MatchPlace()
{
    // 자리에 따른 차등 금액 설정 필요.
    int num = 0;
    system("clear");
    cout << "원하는 자리를 고르세요 : " << endl;
    string line;
    string l;
    ifstream file("MatchPlace");
    if (file.is_open())
    {
        while (getline(file, line))
            cout << line << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    cout << endl;
    cout << "어느 열로 하시겠습니까? : ";
    getline(cin, line);
    l = line;
    money = Money(l);
    cout << endl;
    cout << "몇 번째 좌석으로 하시겠습니까? : ";
    getline(cin, line);
    l += line;
    reserv.push_back(l);
    cout << endl;

    place.push_back(l);

    cout << "인원수를 결정해주세요 : ";
    getline(cin, line);
    num = stoi(line);

    cout << endl;
    cout << "결제해야 하는 금액은 " << money * num << " 달러 입니다." << endl;
    money_.push_back(money*num);
    sleep(5);
    LastReservationCheck();
}
int MatchReservation::Money(string l)
{
    // cout << "자리마다 등급이 다릅니다. 선택하신 좌석은 " << reserv.back() << " 입니다.";
    // 차등금액에 따라 결제 금액 보여줌
    if (l == "A" || l == "E")
        money = 50;
    else if (l == "B" || l == "F")
        money = 10;
    else if (l == "C" || l == "G")
        money = 7;
    else if (l == "D" || l == "H")
        money = 5;

    return money;
}
void MatchReservation::ReservationPage(int mnum)
{   
    //reservnum.push_back(mnum);
    mnum_ = mnum;
    system("clear");
    cout << "------------------------" << endl;
    cout << "경기 예매를 위해 먼저 경기 일정를 보여드리겠습니다." << endl;
    cout << "------------------------" << endl;
    MatchDay();
}
void MatchReservation::LastReservationCheck()
{
    system("clear");
    string line;
    cout << "선택하신 좌석을 확인하겠습니다." << endl;

    cout << "경기 일정은 " << matchday[stoi(day.back())-1] << ", 좌석은 " << place.back() << "입니다. " << endl;
    //cout << day.back() << ", " << place.back() << ", " << reservnum.back();
    sleep(5);

    FileSave();
}
void MatchReservation::ReservDu()
{
    cout << "whwehla";
    
}
void MatchReservation::FileSave()
{
    string line;
    ofstream file("reserv.csv", std::ios::app);
    if (file.is_open())
    {
        for (int i = 0; i < reserv.size(); i++)
            file << reserv[i] << ","; 
        
        file << mnum_;
        file << endl;
        file.close();
    }
}

// 회원가입과 로그인 클래스
class CreateAccount // 회원 가입 클래스
{
public:
    // CreateAccount() { information = {}; }
    void clear();
    void FirstPage();
    void SignUpPage();
    void CreateAccountPage();
    void PrintLogo();
    void IdInput(string id);
    int IdDu(string id);
    string IdFind(string phonenumber);
    void PwInput(string pw);
    int PwDu(string id, string pw);
    string PwFind(string phonenumber);
    int PwSet(string pw);
    void EmailInput(string email);
    int EmailDu(string email);
    void PhoneNumberInput(string phonenumber);
    int PhoneNumberDu(string phonenumber);
    void FileSave();
    int MemBerNumber();
    vector<int> MemberNumber;
    void Exit();
    // void ShowResult();

private:
    vector<string> information;
    vector<string> Id;
    vector<string> Pw;
    vector<string> Email;
    vector<string> PhoneNumber;
};
void CreateAccount::clear() { information.clear(); }
void CreateAccount::PrintLogo()
{
    string line;
    ifstream file("AsianCupLogo");
    if (file.is_open())
    {
        while (getline(file, line))
            cout << line << endl;
        file.close();
    }
    else
        cout << "Unable to open file";
}
void CreateAccount::Exit() { exit(0); }
void CreateAccount::FirstPage()
{
    // system("clear");
    SportsInformation b;
    PrintLogo();
    cout << "------------------------" << endl;
    cout << "1. 아시안컵 정보 알아보기" << endl;
    cout << "2. 경기 예매하기 / 예매 내역 확인하기" << endl;
    cout << "3. 종료하기" << endl;
    cout << "------------------------" << endl;
    string c;
    // a.FirstPage();
    getline(cin, c);
    if (c == "1") // 스포츠 정보 버튼 눌렀을 때
    {
        b.Sportspage();
        getline(cin, c);
        if (c == "1") // 경기 일정 및 개최지;
        {
            system("clear");
            b.Overall();
            sleep(5);
        }
        else if (c == "2") // 조별 리스트 명단;
        {
            system("clear");
            b.GroupList();
            sleep(5);
        }
        else if (c == "3") // 조별 경기 명단;
        {
            system("clear");
            b.GroupPlay();
            sleep(5);
        }
        else if (c == "4") // 한국 선수 팀 명단;
        {
            system("clear");
            b.KoreaList();
            sleep(5);
        }
    }
    else if (c == "2")
        SignUpPage();
    else if (c == "3")
        Exit();
}
void CreateAccount::SignUpPage()
{   
    MatchReservation d;
    system("clear");
    string line;
    string c;
    PrintLogo();
    cout << "------------------------" << endl;
    cout << "1. 로그인하기" << endl;
    cout << "2. ID 찾기" << endl;
    cout << "3. PW 찾기" << endl;
    cout << "4. 회원가입하기" << endl;
    cout << "5. 예매 내역 확인하기" << endl;
    cout << "------------------------" << endl;
    getline(cin, c);
    if (c == "1") // 1. 로그인하기 눌렀을 때
    {
        if (log_count > 0)
        {
            cout << "이미 로그인 되셨어요🙏 \n";
        }
        // system("clear");
        //  a.clear();
        else{
            cout << "ID를 입력하십시오 : ";
            getline(cin, line);
            while (IdDu(line) == 1)
            {
                cout << "그런 ID는 없으세요🙏 : ";
                getline(cin, line);
            }
            string p_id = line;
            cout << "비밀번호를 입력하십시오 : ";
            getline(cin, line);
            while (PwDu(p_id,line) == 0)
            {
                cout << "입력하신 비밀번호가 ID와 일치하지 않습니다. 다시 부탁드려요🙏 : ";
                getline(cin, line);
            }
            cout << "로그인 되셨습니다!" << endl;
            log_count += 1;
        }
        cout << "경기를 예매하시려면 1, 예매 정보를 확인하시려면 2를, 나가려면 3을 눌러주세요! " << endl;
        string n;
        getline(cin,n);
        
        if(n == "1")
            d.ReservationPage(MemberNumber.back());
        else if(n == "2")
            d.ReservCHeck(MemberNumber.back());
        else if(n == "3")
            FirstPage();

    }
    else if (c == "2") // 2. ID찾기 눌렀을 때
    {
        system("clear");
        PrintLogo();
        cout << "ID를 찾으려면? 어떠한 그런? 전화번호 부탁드려요🙏 ";
        getline(cin, line);
        cout << "찾으시는 ID는 " << IdFind(line) << " 입니다." << endl;

        sleep(5);

        SignUpPage();
    }
    else if (c == "3") // 3. 비밀번호 찾기 눌렀을 때
    {
        system("clear");
        PrintLogo();
        while(1)
        {
            cout << "비밀번호를 찾으려면? 어떠한 그런? ID와 전화번호 부탁드려요🙏 \n";
            cout << "ID : ";
            getline(cin, line);
            cout << "전화번호 : ";
            getline(cin, line);
            if (PwFind(line) == "그런 비밀번호는 없으세요🙏 ")
                continue;
            else
            {
                cout << "찾으시는 비밀번호는 " << PwFind(line) << " 입니다." << endl;\
                break;
            }
                
        }
        sleep(5);

        SignUpPage();
    }
    else if (c == "4") // 4. 회원가입 버튼 눌렀을 때
    {
        system("clear");
        clear();
        cout << "ID를 입력하십시오 : ";
        getline(cin, line);
        while (IdDu(line) == 0)
        {
            cout << "모이치도 구다사이-🙏 : ";
            getline(cin, line);
        }
        IdInput(line);

        cout << "비밀번호를 입력하십시오 : ";
        getline(cin, line);
        while (PwSet(line) == 0)
        {
            cout << "비밀번호는 5자 이상으로 입력해주세요. " << endl;
            getline(cin, line);
        }
        PwInput(line);

        cout << "이메일를 입력하십시오 : ";
        getline(cin, line);
        while (EmailDu(line) == 0)
        {
            cout << "모이치도 구다사이-🙏 : ";
            getline(cin, line);
        }
        EmailInput(line);

        cout << "전화번호를 입력하십시오 : ";
        getline(cin, line);
        while (PhoneNumberDu(line) == 0)
        {
            cout << "모이치도 구다사이-🙏 : ";
            getline(cin, line);
        }
        PhoneNumberInput(line);

        // FileSave();
        cout << MemBerNumber() << "입니다.\n";
        FileSave();
        FirstPage();
    }
    else if(c == "5")
    {
        ifstream file("reserv.csv");
        if(file.is_open())
            d.ReservCHeck(MemberNumber.back());
        else
            {
                cout << "로그인후 경기 예매를 부탁드립니다. " << endl;
                FirstPage();
            }
    }
}

void CreateAccount::CreateAccountPage()
{
    system("clear");
    PrintLogo();
    cout << "------------------------" << endl;
    cout << "회원가입 정보 입력하기" << endl;
    cout << "------------------------" << endl;
}
void CreateAccount::IdInput(string id)
{
    information.push_back(id);
} // ID를 벡터에 넣음.
int CreateAccount::IdDu(string id)
{ // ID 중복검사
    if (Id.size() != 0)
    {
        for (int i = 0; i < Id.size(); i++)
            if (Id[i] == id)
                return 0;
    }
    return 1;
}
string CreateAccount::IdFind(string phonenumber)
{ // 전화번호를 이용해 ID를 찾는 함수
    string s = "그런 ID는 없으세요🙏";
    if (PhoneNumber.size() != 0)
    {
        for (int i = 0; i < PhoneNumber.size(); i++)
            if (PhoneNumber[i] == phonenumber)
                return Id[i];
    }
    return s;
}
void CreateAccount::PwInput(string pw)
{ // 비밀번호를 저장
    information.push_back(pw);
}
int CreateAccount::PwDu(string id, string pw)
{ // Id와 일치하는 비번 찾기
    if (Id.size() != 0)
    {
        for (int i = 0; i < Id.size(); i++)
            if (Pw[i] == pw)
                return 1;
    }
    return 0;
}
string CreateAccount::PwFind(string phonenumber)
{ // 전화번호를 이용해 비밀번호를 찾는 함수
    string s = "그런 비밀번호는 없으세요🙏 ";
    if (PhoneNumber.size() != 0)
    {
        for (int i = 0; i < PhoneNumber.size(); i++)
            if (PhoneNumber[i] == phonenumber)
                return Pw[i];
    }
    return s;
}
int CreateAccount::PwSet(string pw) // 비밀번호를 처음 설정할 때 기준에 맞춰야한다.(5글자 이상)                                  //맞추어 해야한다(5글자 이상).
{
    if (pw.size() < 5)
        return 0;
    return 1;
}
void CreateAccount::EmailInput(string email)
{
    information.push_back(email);
} // 이메일을 벡터에 저장
int CreateAccount::EmailDu(string email) // 이메일 중복 검사.
{
    if (Email.size() != 0)
    {
        for (int i = 0; i < Email.size(); i++)
            if (Email[i] == email)
                return 0;
    }
    return 1;
}
void CreateAccount::PhoneNumberInput(string phonenumber)
{
    information.push_back(phonenumber);
}
int CreateAccount::PhoneNumberDu(string phonenumber)
{
    if (PhoneNumber.size() != 0)
    {
        for (int i = 0; i < PhoneNumber.size(); i++)
            if (PhoneNumber[i] == phonenumber)
                return 0;
    }
    return 1;
}
int CreateAccount::MemBerNumber()
{
    int Mnumber = rand() % 1000;
    cout << "고유한 회원 번호를 부여합니다." << endl;
    MemberNumber.push_back(Mnumber); // 형 변환해서 회원정보 vector 마지막 부분에 넣기
    information.push_back(to_string(Mnumber));
    return Mnumber;
}
void CreateAccount::FileSave()
{
    string line;
    ofstream file("ex.csv", std::ios::app);
    if (file.is_open())
    {
        for (int i = 0; i < information.size(); i++)
            file << information[i] << ",";
        file << endl;
        Id.push_back(information[0]);
        Pw.push_back(information[1]);
        Email.push_back(information[2]);
        PhoneNumber.push_back(information[3]);
        file.close();
    }
}

int main()
{
    CreateAccount a;
    while (1)
    {
        a.FirstPage();
    }
}