#include<iostream>
#include<bits/stdc++.h>
using namespace std;


  int countPairsWithinDistance(vector<int>& numbers, int targetDistance) {
        int count = 0, left = 0;
        for (int right = 1; right < numbers.size(); ++right) {
            while (numbers[right] - numbers[left] > targetDistance) {
                ++left;
            }
            count += right - left;
        }
        return count;
    }

    
int smallestDistancePair(vector<int>& numbers, int k) {
        std::sort(numbers.begin(), numbers.end());
        int minDistance = 0, maxDistance = numbers.back() - numbers.front();
        
        while (minDistance < maxDistance) {
            int midDistance = minDistance + (maxDistance - minDistance) / 2;
            if (countPairsWithinDistance(numbers, midDistance) < k) {
                minDistance = midDistance + 1;
            } else {
                maxDistance = midDistance;
            }
        }
        
        return minDistance;
    }

  
int main()
{
  int n,td;
  cin>>n>>td;
  
  vector<int>arr(n);
  for(int i = 0 ; i< n ; i++)
  cin>>arr[i];

  cout<<countPairsWithinDistance(arr,td);
}