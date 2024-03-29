#include "bits/stdc++.h"
using namespace std;
regex standard("[+-]?[0-9]*");
void stringwsign(string &s1,string &s2) // in this function we remove sign from the string
{
    bool first=(s1[0]=='+' || s1[0]=='-'),second=(s2[0]=='+' || s2[0]=='-');
    s1=s1.substr(first,s1.size()-first);
    s2=s2.substr(second,s2.size()-second);
}
//-----------------------------------------------------------------------------------------------------------------------------
void equalstrings(string &s1,string &s2) // in this function we add zeros to the end of the smallest string
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
string samesign(string str1,string str2,int first) // this is an algorithm to add or substract two strings if they have the same sign
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
string diffsign(string str1,string str2,int first) // this is an algorithm to add or substract two strings if they have diffrent sign
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
    // this is the variable that will contain the data
    string strBigDecimalInt;
public:
    BigDecimalInt (string decStr) //here i made a constractor and i added regex to it
    { 
        while(!regex_match(decStr, standard))
        {
            cin.clear();
            cout << '(' << decStr << ')' << " is not valid as a BigDecimalInt" << endl;
            cout << "enter another one:" << endl;
            cin >> decStr;
        }
        strBigDecimalInt = decStr;
    }
    BigDecimalInt (int decInt) : strBigDecimalInt(to_string(decInt)){}
    BigDecimalInt operator+(BigDecimalInt anotherDec) // i overloded '+' to add two big decimal numbers
    {
        
        string str1 = strBigDecimalInt, str2 = anotherDec.strBigDecimalInt, str3{""};
        char first_sign = (str1[0] == '+' || str1[0] == '-') ? str1[0] : '+';
        char second_sign = (str2[0] == '+' || str2[0] == '-') ? str2[0] : '+';
        stringwsign(str1, str2);
        equalstrings(str1, str2);
        if(first_sign == second_sign)
        {
            int remaining = 0;
            char ch;
            for (int i = str1.length()-1; i >= 0; i--)
            {
                int indexstr1 = str1[i] - '0';
                int indexstr2 = str2[i] - '0';
                ch = (indexstr1+indexstr2+remaining) % 10 + 48;
                str3 = ch + str3;
                remaining = (indexstr1+indexstr2+remaining)/10;
            }
            if(remaining!=0){
                ch=remaining+48;
                str3=ch+str3;
            }
            if(first_sign == '-'){
                str3 = '-' + str3;
            }
        }
        
        else
        {
            if(str2 > str1)
            {
                swap(str1, str2);
                swap(first_sign, second_sign);
            }
            int first = (first_sign == '-') ? -1 : 1;
            str3 = diffsign(str1, str2, first);
        }

        BigDecimalInt result(str3);
        return result;
    }
    BigDecimalInt operator-(BigDecimalInt anotherDec)
    {
        //eslam
        int first=0,second=0;
        // here where we store the same data from our variables to ease ability to use it by using short name
        string str1=strBigDecimalInt,str2=anotherDec.strBigDecimalInt,str3="";
        // here we find the signs of two numbers to check on later
        first=(str1[0]!='-'? 1:-1),second=(str2[0]!='-'? -1:1);
        // this function used to make two numbers without the character of + or -
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
        //eslam
        string str1=strBigDecimalInt,str2=anotherDec.strBigDecimalInt;
        int first,second;
        first=(str1[0]!='-'? 1:-1),second=(str2[0]!='-'? 1:-1);
        stringwsign(str1,str2);
        equalstrings(str1,str2);
        // here I compare by both signs of them and if they equaled i compared by its value
        if(first<second || (first==second && first==-1 && str1>str2) || ((first==second && first==1 && str1<str2))){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator>(BigDecimalInt anotherDec)
    {
        //youssef
        string str1=strBigDecimalInt,str2=anotherDec.strBigDecimalInt;
        int first,second;
        first=(str1[0]!='-'? 1:-1),second=(str2[0]!='-'? 1:-1);
        stringwsign(str1,str2);
        equalstrings(str1,str2);
        if(first>second || (first==second && second==-1 && str1<str2) || ((first==second && second==1 && str1>str2))){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator==(BigDecimalInt anotherDec)
    {
        //youssef
        if (strBigDecimalInt == anotherDec.strBigDecimalInt)
            return true;
        else
            return false;
    }
    BigDecimalInt operator=(BigDecimalInt anotherDec)
    {
        //youssef
        strBigDecimalInt = anotherDec.strBigDecimalInt;
    }
    int size()
    {
        //youssef
        int size = strBigDecimalInt.length();
        return size;
    }
    int sign()
    {
        //youssef
        int sign = (strBigDecimalInt[0] != '-'? 1 : -1);
        return sign;
    }
    friend ostream& operator << (ostream& out, BigDecimalInt b);
};
//overloading the cout operator
ostream& operator << (ostream& out, BigDecimalInt b)
{
    out<<b.strBigDecimalInt;
    return out;
}
//------------------------------------------------------------------------------------------------------------------------------
int main()
{
    // our examples for this project
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num4(23497);
//    BigDecimalInt num4 = num3 + num1;
//    BigDecimalInt num5 = num3 - num1;
//    cout << "num1 = " << num1 << endl;
//    cout << "num2 = " << num2 << endl;
////Next statement will print 236913578023691357802369135780
//    cout << "num2 + num1 = " << num4 << endl;
////Next statement will print -010000000001000000000100000000
//    cout << "num2 - num1 = " << num5 << endl;
//    if(num2>num1){
//        cout<<"second number is greater than first number"<<endl;
//    }
//    else if(num2<num1){
//        cout<<"second number is smaller than first number"<<endl;
//    }
//    else{
//        cout<<"both are equal"<<endl;
//    }
//    num3=num2;
//    cout<<num3<<endl;
//    cout<<num4.size()<<endl;
}
