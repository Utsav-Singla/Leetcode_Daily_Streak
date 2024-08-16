#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    int maxDistance(vector<vector<int>>& arr) {
        int ans = 0;

        pair<int, int> m1;
        pair<int, int> m2;

        m1.first = INT_MAX;
        m2.first = INT_MAX;

        for (int i = 0; i < arr.size(); i++) {
            if (m1.first >= arr[i][0])
                m1 = {arr[i][0], i};
        }
        for (int i = 0; i < arr.size(); i++) {
            if (i != m1.second && m2.first >= arr[i][0])
                m2 = {arr[i][0], i};
        }

        pair<int, int> m;
        pair<int, int> M;

        m.first = INT_MIN;
        M.first = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            int u = arr[i].size() - 1;
            if (m.first <= arr[i][u])
                m = {arr[i][u], i};
        }

        for (int i = 0; i < arr.size(); i++) {
            int u = arr[i].size() - 1;
            if (i != m.second && M.first <= arr[i][u])
                M = {arr[i][u], i};
        }
        // cout<<m1.first<<" "<<m1.second<<endl;
        // cout<<m2.first<<" "<<m2.second<<endl;
        // cout<<m.first<<" "<<m.second<<endl;
        // cout<<M.first<<" "<<M.second<<endl;

        if (m1.second != m.second)
            ans = m.first - m1.first;
        else
            ans = max(m.first - m2.first, M.first - m1.first);

        return ans;
    }
   
   int main()
   {
    int n;
    cin>>n;

    vector<vector<int>>arr(n);

    for(int i = 0 ; i < arr.size() ; i++)
    {
      int size;
      cin>>size;
      arr[i].resize(size);

      for(int j = 0 ; j < size ; j++)
      cin>>arr[i][j];
    }

    cout<<maxDistance(arr);
   }