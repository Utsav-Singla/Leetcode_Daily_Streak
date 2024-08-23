#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    string fractionAddition(string expression) {
        int numerator=0,denominator=1;
        int i=0;
        int n=expression.size();

        while(i<n){
            int sign=1;
            if(expression[i]=='+' || expression[i]=='-'){
                if(expression[i]=='-') sign=-1;
                i++;
            }

            int num=0;
            while(i<n && isdigit(expression[i])){
                num=num*10+(expression[i]-'0');
                i++;
            }
            num*=sign;
            i++;
            int den=0;
            while(i<n && isdigit(expression[i])){
                den=den*10+(expression[i]-'0');
                i++;
            }
            numerator=numerator*den+num*denominator;
            denominator*=den;

            int gcdVal=0;
            numerator/=gcdVal;
            denominator/=gcdVal;

        }
        return to_string(numerator)+'/'+to_string(denominator);

    }


int main()
{
  string exp;
  cin>>exp;

  cout<<fractionAddition(exp)<<endl;

}