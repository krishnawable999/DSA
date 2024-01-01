#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a = "baaccddefghh";
    map<char,int> mp;

    for(auto it:a){
        mp[it]++;
    }
    for(auto it : mp){
        cout <<it.first <<" "<<it.second;
    }
}