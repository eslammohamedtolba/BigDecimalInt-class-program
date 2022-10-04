#include "bits/stdc++.h"
using namespace std;
void stringwsign(string &s1,string &s2)
{
    bool first=(s1[0]=='+' || s1[0]=='-'),second=(s2[0]=='+' || s2[0]=='-');
    s1=s1.substr(first,s1.size()-first);
    s2=s2.substr(second,s2.size()-second);
}
//-----------------------------------------------------------------------------------------------------------------------------
void equalstrings(string &s1,string &s2)
{
    int size1=s1.size(),size2=s2.size();
    string s3(abs(size1-size2),'0');
    if(s1.size()>s2.size()){
        s2=s3+s2;
    }
    else{
        s1=s3+s1;
    }
}
//-----------------------------------------------------------------------------------------------------------------------------
string samesign(string str1,string str2,int first)
{
    int remaining=0,indexstr1=0,indexstr2=0;char ch;string str3="";
    for(int i=str1.size()-1;i>=0;i--){
        indexstr1=str1[i]-'0';indexstr2=str2[i]-'0';
        ch=(indexstr1+indexstr2+remaining)%10+48;
        str3=ch+str3;
        remaining=(indexstr1+indexstr2+remaining)/10;
    }
    if(remaining!=0){
        ch=remaining+48;
        str3=ch+str3;
    }
    if(first==-1){
        str3='-'+str3;
    }
    return str3;
}
//----------------------------------------------------------------------------------------------------------------------------
string diffsign(string str1,string str2,int first)
{
    int indexstr1=0,indexstr2=0;char ch;string str3="";
    for(int i=str1.size()-1;i>=0;i--){
        if(str1[i]>=str2[i]){
            indexstr1=str1[i]-'0';indexstr2=str2[i]-'0';
            ch=(indexstr1-indexstr2)%10+48;
            str3=ch+str3;
        }
        else{
            int j=i-1;
            while(str1[j]=='0'){
                str1[j]='9';
                j--;
            }
            str1[j]--;
            indexstr1=str1[i]-'0';indexstr2=str2[i]-'0';
            ch=(indexstr1+10-indexstr2)%10+48;
            str3=ch+str3;
        }
    }
    if(first==-1){
        str3='-'+str3;
    }
    return str3;
}
//----------------------------------------------------------------------------------------------------------------------------
class BigDecimalInt
{
private:
    string strBigDecimalInt;
public:
    BigDecimalInt (string decStr)
    {
        strBigDecimalInt=decStr;
    }
    BigDecimalInt (int decInt)
    {
        strBigDecimalInt=to_string(decInt);
    }
    BigDecimalInt operator+(BigDecimalInt anotherDec)
    {
        int first=0,second=0;
        string str1=strBigDecimalInt,str2=anotherDec.strBigDecimalInt,str3="";
        first=(str1[0]!='-'? 1:-1),second=(str2[0]!='-'? 1:-1);
        stringwsign(str1,str2);
        equalstrings(str1,str2);
        if(first==second){
            str3=samesign(str1,str2,first);
        }
        else{
            if(str1<str2){
                swap(str1,str2);
                swap(first,second);
            }
            str3=diffsign(str1,str2,first);
        }
        BigDecimalInt num3(str3);
        return num3;
    }
    BigDecimalInt operator-(BigDecimalInt anotherDec)
    {
        int first=0,second=0;
        string str1=strBigDecimalInt,str2=anotherDec.strBigDecimalInt,str3="";
        first=(str1[0]!='-'? 1:-1),second=(str2[0]!='-'? -1:1);
        stringwsign(str1,str2);
        equalstrings(str1,str2);
        if(first==second){
            str3=samesign(str1,str2,first);
        }
        else{
            if(str1<str2){
                swap(str1,str2);
                swap(first,second);
            }
            str3=diffsign(str1,str2,first);
        }
        BigDecimalInt num3(str3);
        return num3;
    }
    bool operator<(BigDecimalInt anotherDec)
    {
        string str1=strBigDecimalInt,str2=anotherDec.strBigDecimalInt;
        int first,second;
        first=(str1[0]!='-'? 1:-1),second=(str2[0]!='-'? 1:-1);
        stringwsign(str1,str2);
        equalstrings(str1,str2);
        if(first<second || (first==second && first==-1 && str1>str2) || ((first==second && first==1 && str1<str2))){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator>(BigDecimalInt anotherDec)
    {
        string str1=strBigDecimalInt,str2=anotherDec.strBigDecimalInt;
        int first,second;
        first=(str1[0]!='-'? 1:-1),second=(str2[0]!='-'? 1:-1);
        stringwsign(str1,str2);
        equalstrings(str1,str2);
        if(first>second || (first==second && first==-1 && str1<str2) || ((first==second && first==1 && str1>str2))){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator==(BigDecimalInt anotherDec)
    {
        if(strBigDecimalInt==anotherDec.strBigDecimalInt){
            return true;
        }
        else{
            return false;
        }
    }
    BigDecimalInt operator=(BigDecimalInt anotherDec)
    {
        strBigDecimalInt=anotherDec.strBigDecimalInt;
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
    out<<b.strBigDecimalInt;
    return out;
}
//------------------------------------------------------------------------------------------------------------------------------
int main()
{
    BigDecimalInt num1("-123414");
    BigDecimalInt num2("123189");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num4 = num2 + num1;
    num4=num3;
    cout<<num4<<endl;
//    BigDecimalInt num5 = num2 - num1;
//    cout << "num1 = " << num1 << endl;
//    cout << "num2 = " << num2 << endl;
//Next statement will print 236913578023691357802369135780
//Next statement will print -313456789011345678901134567890
//    cout << "num2 - num1 = " << num5 << endl;
}