#include "bits/stdc++.h"
using namespace std;
void sign(string s1,string s2,int &first,int &second)
{
    int firstnum=(s1[0]!='-'? 1:-1),secondnum=(s2[0]!='-'? -1:1);
}
void stringwsing(string &s1,string &s2)
{
    bool first=(s1[0]=='+' || s1[0]=='-'),second=(s2[0]=='+' || s2[0]=='-');
    s1=s1.substr(first,s1.size()-first);
    s2=s2.substr(second,s2.size()-second);
}
class BigDecimalInt
{
private:
    string strBigDecimalInt;
public:
    BigDecimalInt (string decStr)
    {
        cout<<"remon"<<endl;
    }
    BigDecimalInt (int decInt)
    {
        cout<<"remon"<<endl;
    }
    BigDecimalInt operator+(BigDecimalInt anotherDec)
    {
        cout<<"remon"<<endl;
    }
    BigDecimalInt operator-(BigDecimalInt anotherDec)
    {
        cout<<"eslam"<<endl;
    }
    bool operator<(BigDecimalInt anotherDec)
    {
        cout<<"eslam"<<endl;
    }
    bool operator>(BigDecimalInt anotherDec)
    {
        cout<<"youssef"<<endl;
    }
    bool operator==(BigDecimalInt anotherDec)
    {
        cout<<"youssef"<<endl;
    }
    BigDecimalInt operator=(BigDecimalInt anotherDec)
    {
        cout<<"youssef"<<endl;
    }
    int size()
    {
        cout<<"youssef"<<endl;
    }
    int sign()
    {
        cout<<"youssef"<<endl;
    }
    friend ostream& operator << (ostream& out, BigDecimalInt b);
};
ostream& operator << (ostream& out, BigDecimalInt b)
{
    cout<<"youssef"<<endl;
}
int main()
{
//    BigDecimalInt num1("123456789012345678901234567890");
//    BigDecimalInt num2("+113456789011345678901134567890");
//    BigDecimalInt num3("-200000000000000000000000000000");
//    BigDecimalInt num4 = num2 + num1;
//    BigDecimalInt num5 = num2 - num1;
//    cout << "num1 = " << num1 << endl;
//    cout << "num2 = " << num2 << endl;
//    //Next statement will print 236913578023691357802369135780
//    cout << "num2 + num1 = " << num4 << endl;
//    //Next statement will print -313456789011345678901134567890
//    cout << "num2 - num1 = " << num5 << endl;
}
