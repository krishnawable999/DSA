#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "We promptly judged antique ivory buckles for the next prize";
    unordered_map<char,int> mp;

    for(int i=0 ; i<str.length() ; i++){
        char ch = str[i];
        mp[ch]++;
    }
    int count=0;
    for(auto it:mp){
        if(it.first) count++;
    }

    cout<<count;
}