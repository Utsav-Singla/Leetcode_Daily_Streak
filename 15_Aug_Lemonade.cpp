#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    static bool lemonadeChange(vector<int>& bills) {
        int cnt5=0, cnt10=0;
        for(int b: bills){
            switch(b){
                case 5: 
                    cnt5++; 
                    break;
                case 10: 
                    if (cnt5>0) cnt5--, cnt10++;
                    else return 0;
                    break;
                case 20:
                    if (cnt10>0 && cnt5>0) cnt10--, cnt5--;
                    else if (cnt5>2) cnt5-=3;
                    else return 0;
                    break;
            }
        }
        return 1;
    }

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main()
{
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i = 0 ; i < n ; i++)
  cin>>arr[i];
  
  cout<<lemonadeChange(arr)<<endl;
}