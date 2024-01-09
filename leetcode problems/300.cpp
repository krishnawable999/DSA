#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &v){
    int ans=0;
    vector<int> vec;
    for(int i=0 ; i<v.size() ; i++){
        if(v[i] < v[i+1]){
            vec.push_back(v[i]);
        }
        // else{
        //     if()
        // }
    }
    return vec.size();
}

int main(){
    vector<int> v={0,1,0,3,2,3};
    cout <<solve(v)<<endl;
}