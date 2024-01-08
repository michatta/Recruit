#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class CreateAccount //회원 가입 클래스
{
public:
    //CreateAccount() { information = {};}
    void FirstPage();
    void SignUpPage();
    void CreateAccountPage();
    void PrintLogo();
    void IdInput(string id);
    void PwInput(string pw);
    void EmailInput(string email);
    void PhoneNumberInput(string phonenumber);
    void FileSave();
    int MemberNumber();
    void ShowResult();
private:
    vector<string> information;
    int MemNumber;
};
void CreateAccount::PrintLogo()
{
    string line;
    ifstream file("AsianCupLogo");
    if(file.is_open())
    {
        while(getline(file,line))
            cout << line << endl;
        file.close();
    }
    else{
        cout << "Unable to open file";
    }
}
void CreateAccount::FirstPage()
{
    PrintLogo();
    cout << "-------------------"<< endl;
    cout << "1. 아시안컵 정보 알아보기" << endl;
    cout << "2. 경기 예매하기" << endl;
    cout << "-------------------"<< endl;
}
void CreateAccount::SignUpPage()
{
    system("clear");
    PrintLogo();
    cout << "-------------------"<< endl;
    cout << "1. ID 입력" << endl;
    cout << "2. PW 입력" << endl;
    cout << "3. ID 찾기" << endl;
    cout << "4. PW 찾기" << endl;
    cout << "5. 회원가입하기" << endl;
    cout << "-------------------"<< endl;
}
void CreateAccount::CreateAccountPage()
{
    system("clear");
    PrintLogo();
    cout << "-------------------"<< endl;
    cout << "회원가입 정보 입력하기" << endl;
    cout << "-------------------"<< endl;
}
void CreateAccount::IdInput(string id)
{
    information.push_back(id);
}
void CreateAccount::PwInput(string pw)
{
    information.push_back(pw);
}
void CreateAccount::EmailInput(string email)
{
   information.push_back(email);
} 
void CreateAccount::PhoneNumberInput(string phonenumber)
{
    information.push_back(phonenumber);
}
int CreateAccount::MemberNumber()
{
    int Mnumber = rand()%100;
    cout << "고유한 회원 번호를 부여합니다." << endl;
    //information.push_back(Mnumber); //형 변환해서 회원정보 vector 마지막 부분에 넣기
    return Mnumber;
}
void CreateAccount::ShowResult()
{
    for(int i=0;i<4;i++)
        cout << information[i] << endl;
}
void CreateAccount::FileSave()
{
    string line;
    ofstream file("ex.csv", std::ios::app);
    ifstream file1("ex.csv");
    if(file.is_open()){
        for(int i=information.size()-4;i<information.size();i++)
            file << information[i] << ",";
        file << "\n";
        file.close();
    }
}
// class SignUp  //로그인 클래스
// {
// public:
//     SignUp();
//     void IdInput(vector<string> id); //id를 입력하는 함수
//     void PwInput(vector<string> pw); //pw를 입력하는 함수
//     string FindId(vector<string> email, vector<string> phonenumber); // id를 찾아주는 함수
//     string FindPw(vector<string> id,vector<string> email, vector<string> phonenumber); // 비밀번호를 찾아주는 함수
// private:
//     string Id;
//     string Pw;
//     string Email;
//     string PhoneNumber;
// };

int main()
{
    CreateAccount a;
    string line;
    while(1)
    {   
        string c;
        a.FirstPage();
        getline(cin,c);
        if(c == "2") // 경기 예매 버튼 눌렀을 때
        {   
            a.SignUpPage();
            
            getline(cin,c);
            if(c == "5") // 회원가입 버튼 눌렀을 때
            {  
                system("clear");
                cout << "ID를 입력하십시오 : ";
                getline(cin,line);
                a.IdInput(line);

                cout << "비밀번호를 입력하십시오 : ";
                getline(cin,line);
                a.PwInput(line);

                cout << "이메일를 입력하십시오 : ";
                getline(cin,line);
                a.EmailInput(line);

                cout << "전화번호를 입력하십시오 : ";
                getline(cin,line);
                a.PhoneNumberInput(line);

                a.FileSave();
                a.FirstPage();
            }
        }
    }
    // string line;
    // ifstream file("ex.txt");
    // if(file.is_open())
    // {
    //     while(getline(file,line))
    //         cout << line << endl;
    //     file.close();
    // }
    // else{
    //     cout << "Unable to open file";
    //     return 1;
    // }
    // return 0;

    //string line;
	// return 0;
}