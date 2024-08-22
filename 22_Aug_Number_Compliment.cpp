#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    int findComplement(int num) {
        if (num == 0) return 1;
        
        unsigned int mask = ~0;
        
        while (num & mask) {
            mask <<= 1;
        }
        
        return ~mask & ~num;
    }

    int main()
    {
      int n;
      cin>>n;

      cout<<findComplement(n)<<endl;
    }