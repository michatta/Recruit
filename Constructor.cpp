// #include <iostream>
// using namespace std;

// class SimpleClass
// {
// private:
//     int num1;
//     int num2;
// public:
//     SimpleClass()
//     {
//         num1 = 0;
//         num2 = 0;
//     }
//     SimpleClass(int n)
//     {
//         num1 = n;
//         num2 = 0;
//     }
//     SimpleClass(int n1, int n2)
//     {
//         num1 = n1;
//         num2 = n2;
//     }

//     void Show() const
//     {
//         cout << num1 << ' ' << num2 << endl;
//     }
// };

// int main(void)
// {
//     SimpleClass sc1;
//     sc1.Show();

//     SimpleClass sc2(100);
//     sc2.Show();

//     SimpleClass sc3(100,200);
//     sc3.Show();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class SimpleClass
// {
// private:
//     int num1;
//     int num2;
// public:
//     SimpleClass()
//     {
//         num1 = 0;
//         num2 = 0;
//     }
//     SimpleClass(int n)
//     {
//         num1 = n;
//         num2 = 0;
//     }
//     SimpleClass(int n1, int n2)
//     {
//         num1 = n1;
//         num2 = n2;
//     }
//     SimpleClass(int n1 = 0, int n2 = 0) //디폴트 값으로 0,0 적용
//     {
//         num1 = n1;
//         num2 = n2;
//     }

//     void Show() const
//     {
//         cout << num1 << ' ' << num2 << endl;
//     }
// };

// int main(void)
// {
//     SimpleClass sc1;
//     sc1.Show();

//     SimpleClass sc2(100);
//     sc2.Show();

//     SimpleClass sc3(100,200);
//     sc3.Show();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class SimpleClass
// {
// private:
//     int num1;
//     int num2;
// public:
//     SimpleClass(int n1 = 0, int n2 = 0) //디폴트 값으로 0,0 적용
//     {
//         num1 = n1;
//         num2 = n2;
//     }

//     void Show() const
//     {
//         cout << num1 << ' ' << num2 << endl;
//     }
// };

// int main(void)
// {
//     SimpleClass* psc1 = new SimpleClass;
//     psc1 -> Show();

//     SimpleClass* psc2 = new SimpleClass(100);
//     psc2 -> Show();

//     SimpleClass* psc3 = new SimpleClass(100,200);
//     psc3 -> Show();

//     delete psc1, psc2, psc3;

// }

// #include <iostream>
// using namespace std;

// class SimpleClass
// {
// private:
//     int num1;
//     int num2;
// public:
//     SimpleClass(int n1 = 0, int n2 = 0) //디폴트 값으로 0,0 적용
//     {
//         num1 = n1;
//         num2 = n2;
//     }

//     void Show() const
//     {
//         cout << num1 << ' ' << num2 << endl;
//     }
// };

// int main(void)
// {
//     SimpleClass sc1();
//     SimpleClass mysc = sc1();
//     mysc.Show();
// }

// SimpleClass sc1()
// {
//     SimpleClass sc(20,39);
//     return sc;
// }

// #include <iostream>
// using namespace std;

// class AAA
// {
// public:
//     AAA()
//     {
//         cout << "empty object" << endl;
//     }
//     void ShowYourName()
//     {
//         cout << "I'm class AAA!" << endl;
//     }
// };

// class BBB
// {
// private:
//     AAA& ref;
//     const int& num;
// public:
//     BBB(AAA& r, const int& n)
//     :ref(r), num(n)
//     {}
//     void ShowYourName()
//     {
//         ref.ShowYourName();
//         cout << "and" << endl;
//         cout << "I refer num" << num << endl;
//     }
// };

// int main(void)
// {
//     AAA obj1;
//     BBB obj2(obj1, 20);
//     obj2.ShowYourName();

//     return 0;
// }

#include <iostream>
template <typename T>
void Swap(T &a, T &b);

template <typename T>
void Swap(T*a, T*b, int n);

void show(int a[]);
const int Lim = 8;
int main()
{
    using namespace std;
    int i =10, j = 20;
    cout << "i,j = " << i << ", " << j << ".\n";
    cout << "컴파일러가 생성한 int형 교환기 사용\n";
    Swap(i,j);
    cout << "i,j = " << i << ", " << j << ".\n";

    int d1[Lim] = {0,7,0,4,1,7,7,6};
    int d2[Lim] = {0,6,2,0,1,9,6,9};
    cout << "원본 배열:\n";
    show(d1);
    show(d2);
    Swap(d1,d2,Lim);
    cout << "교환된 배열:\n";
    show(d1);
    show(d2);
    return 0;
}
template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T a[], T b[], int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
void show(int a[])
{
    using namespace std;
    cout<< a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim; i++)
    {
        cout << a[i];
    }
    cout << endl;
}