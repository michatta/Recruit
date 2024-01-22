#ifndef RECRUIT_H
#define RECRUIT_H

#include <sqlite3.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

using namespace std;

class Listup
{
public:
    void RandomListup(); // 무작위로 3개의 기업 공고를 추출하고 callback함수를 통해 print한다. 
    static int callback(void *NotUsed,int argc,char **argv, char **azColName); //안에 column값을 프린트해주는 함수
    void BasicSearch();
    void DetailSearch();
    void ShowDetail(string Snum);
    void ShowCorporate(string Snum);
    void ShowOpening(string Snum);
};
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
#endif