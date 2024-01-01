#include<bits/stdc++.h>
#include<vector>
using namespace std;

void findmaxprofit(vector<int> &vec, int n){
   int peak = vec[0];
   int valley = vec[0];
   int ans=0;
   int i=0;
   while(i<n-1){
    //peak
   while(i<n-1 && vec[i]<=vec[i+1]){
    i++;
   }
   peak = vec[i];

   //valley

   while(i<n-1 && vec[i] >= vec[i+1]){
    i++;
   }
   valley = vec[i];

    ans = ans +(peak - valley);

   }
  cout<<"The max profit is "<<ans<<endl;
}

int main(){

    // cout<<"hello";
    vector<int> vec={7,2,5,3,4,6};
    int n=6;
    findmaxprofit(vec,n);
    // cout<<ans<<endl;
}