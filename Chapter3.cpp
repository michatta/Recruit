// #include <iostream>
// int main()
// {
//     using namespace std;
//     int chest = 42;
//     int waist = 0x42;
//     int inseam = 042;

//     cout << "손님 몸매는 한마디로 끝내 줍니다!\n";
//     cout << "가슴 둘레 " << chest << "\n";
//     cout << "허리 둘레 " << waist << "\n";
//     cout << "인심 길이 " << inseam << "\n";
//     return 0;
// }
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int chest = 42;
//     int waist = 42;
//     int inseam = 42;

//     cout << "손님 몸매는 한마디로 끝내 줍니다!" << endl;
//     cout << "가슴 둘레 " << chest << " (10진수)" << endl;

//     cout << hex; // cout이 정수를 디스플레이하는 방식을 변경한다.식별자 hex는 std 이.름 공간의 일부.
//     cout << "허리 둘레 " << waist << " (16진수)" << endl;
    
//     cout << oct;
//     cout << "인심 길이 " << inseam << " (8진수)" << endl;
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     char ch;

//     cout << "원하는 문자 하나를 입력하시오: " << endl;
//     cin >> ch;
//     cout << "감사합니다. ";
//     cout << "당신이 입력한 문자는 " << ch << "입니다." << endl;
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     char ch = 'M';
//     int i = ch;
//     cout << ch << "의 ASCII 코드는 " << i << " 입니다." << endl;

//     cout << "이 문자 코드에 1을 더해보겠습니다." << endl;
//     ch = ch + 1;
//     i = ch;
//     cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

//     cout << "cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
//     cout.put(ch);

//     cout.put('!');

//     cout << endl << "종료" << endl;
//     return 0;
// }


// #include <iostream>
// #include <limits.h>

// int main()
// {
//     using namespace std;
//     long n_long = LONG_MAX;
//     long long n_llong = LLONG_MAX;

//     cout << "long은 " << sizeof n_long << " 바이트이다. " << endl << endl;
//     cout << "long long은 " << sizeof n_llong << " 바이트이다. " << endl;

// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "\a암호명 \"화려한 외출 \" 작전이 방금 개시되었습니다!\n";
//     cout << "8자리 비밀번호를 입력하십시오 : ________\b\b\b\b\b\b\b\b"; //백스페이스 문자 개수만큼 커서를 앞으로 이동시킴.
//     long code;
//     cin >> code;
//     cout << "\a입력하신 비밀번호는 " << code << "입니다.\n";
//     cout << "\a비밀번호가 맞습니다! z3 계획을 진행하십시오!\n";
//     //cout << "Let them eat g\u00E2teau.\n";
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout.setf(ios_base::fixed, ios_base::floatfield);

//     float tub = 10.0 / 3.0;
//     double mint = 10.0 / 3.0;
//     const float million = 1.0e6;
    
//     cout << "tub = " << tub;
//     cout << ", a million tubs = " << million *tub;
//     cout << ", \nten million tubs = ";
//     cout << 10 * million *tub << endl;

//     cout << "mint = " << mint << " and a million mints = ";
//     cout << million * mint << endl;
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     float a = 2.34E+22f;
//     float b = a + 1.0f;

//     cout << "a = " << a << endl; // 소수점 위로 23개의 숫자를 가지는 큰 수이기 때문에 문제가 발생한다. float형은 처음 6개 혹은 7개의 숫자까지만 나타낼 수 있으므로 효과를 갖지 X
//     cout << "b - a = " << b-a << endl;
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     float hats, heads;

//     cout.setf(ios_base::fixed , ios_base::floatfield);
//     cout << "수를 하나 입력하시오: ";
//     cin >> hats;
//     cout << "다른 수를 입력하시오: ";
//     cin >> heads;

//     cout << "hats = " << hats << "; heads = " << heads << endl;
//     cout << "hats + heads = " << hats + heads << endl;
//     cout << "hats - heads = " << hats - heads << endl;
//     cout << "hats * heads = " << hats * heads << endl;
//     cout << "hats / heads = " << hats / heads << endl;
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout.setf(ios_base::fixed , ios_base::floatfield);
//     cout << "정수 나눗셈 : 9/5 = " << 9/5 << endl;
//     cout << "부동 소수점수 나눗셈: 9.0 / 5.0 = " ;
//     cout << 9.0 / 5.0 << endl;
//     cout << "혼합 나눗셈 : 9.0/5 = "<< 9.0/5 << endl;
//     cout << "double형 상수: 1e7/9.0 = ";
//     cout << 1.e7 / 9.0 << endl;
//     cout << "float형 상수 : 1e7f/9.0f = ";
//     cout << 1.e7f / 9.0f << endl;
//     return 0; 
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     const int Lbs_per_stn = 14;
//     int lbs;

//     cout << "당신의 체중을 파운드 단위로 입력하십시오: ";
//     cin >> lbs;
//     int stone = lbs / Lbs_per_stn;   //몫은 스톤으로
//     int pounds = lbs % Lbs_per_stn;  //나머지는 파운드로
//     cout << lbs << " 파운드는 " << stone 
//             << " 스톤, " << pounds << " 파운드입니다. \n"; // 두 연산자가 모두 int형이므로 정수 나눗셈을 수행한다.
        
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     float tree = 3;
//     int guess = 3.9832;
//     int debt = 7.2E12;

//     cout << "tree = " << tree << endl;
//     cout << "guess = "<< guess << endl;
//     cout << "debt = "<< debt << endl;
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     int auks, bats, coots;

//     auks = 19.99 + 11.99;

//     bats = (int) 19.99 + (int) 11.99;
//     coots = int (19.99) + int (11.99);
//     cout << "바다오리 = " << auks << " , 박쥐 = " << bats;
//     cout << ", 검둥오리 " << coots << endl;

//     char ch = 'Z';
//     cout << "코드 " << ch << " 의 값은 ";
//     cout << int(ch) << endl;
//     cout << "네, 코드 z의 값은 ";
//     cout << static_cast<int>(ch) << endl;
// }


//Chapter 3 프로그래밍 연습

//1
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int centi;
//     cout << "키를 정수형 센티미터 단위로 입력하시오 : ___\b\b\b\b";
//     cin >> centi;

//     const double meter = centi/100.0;
//     const int centimeter = centi;
//     cout << "미터와 센티미터로 변환하면? " << meter << "미터에, " << centimeter << "센티미터 입니다." << endl;
// }


//2
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "키를 피트와 인치 단위로 적으시오: ";
//     int feet;
//     cin >> feet;
//     const int inch = feet * 12;
//     cout << "몸무게를 파운드 단위로 적으시오: ";
//     int pound;
//     cin >> pound;

//     const double bmi = (pound * 2.2)/(inch * 0.0254);
//     cout << "bmi는 " << bmi << "입니다." << endl;

// }

//3
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "위도를 도, 분, 초 단위로 입력하시오: " << endl;
//     cout << "먼저, 도각을 입력하시오: ";
//     int doo;
//     cin >> doo;
//     cout << "다음에, 분각을 입력하시오: ";
//     int min;
//     cin >> min;
//     cout << "끝으로, 초각을 입력하시오: ";
//     int sec;
//     cin >> sec;
//     const double we = doo + min / 60.0 + sec / 3600.0;
//     cout << doo <<"도, " << min << "분, " << sec << "초 = " << we << "도";
//     return 0;
// }


//4
// #include <iostream>
// int main()
// {
//     using namespace std;
//     long int second;

//     cout << "초 수를 입력하시오: ";
//     cin >> second;
//     const long int se = second;
//     const int day = second/(3600*24); //second를 일로 환산해서 나누어서 day 출력
//     second = second - day*3600*24;
//     const int hour = second / 3600;
//     second = second - hour*3600;
//     const int min = second / 60;
//     const int sec = second % 60;


//     cout << se << "초 = " << day << "일, " << hour << "시간, " << min << "분, " << sec << "초";

// }

//5
// #include <iostream>
// int main()
// {
//     using namespace std;
//     long double world;
//     long double want;

//     cout << "세계 인구 수를 입력하시오 : ";
//     cin >> world;

//     cout << "미국의 인구수를 입력하시오 : ";\
//     cin >> want;

//     long double per = want/world*10;
//     cout << "세계 인구수에서 미국이 차지하는 비중은 " << per << "% 이다.";

// }


//6
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "주행한 거리를 마일 단위로 입력하시오 : ";
//     int mile;
//     cin >> mile;

//     cout << "소비한 휘발유 양을 갤런 단위로 입력하시오 : ";
//     int gal;
//     cin >> gal;

//     cout << "갤런당 마일 수는 ? " << mile/gal << "입니다." << endl;
// }


//7
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "휘발유 소비량을 유럽 스타일로 입력하시오 : ";
//     double liter;
//     cin >> liter; //100키로미터당 리터 수

//     //1갤런은 3.875리터
//     //100키로미터는 62.14마일

//     double gal = liter / 3.875;
//     int mpg = 62.14/gal;

//     cout << "휘발유 소비량을 미국 스타일로 변환하면 : "<<  mpg << "mpg 입니다. \n"; 

// }