#include<iostream>
#include<string>
#include<queue>
using namespace std;


int main(){
    string str = "ababc";
    int freq[26] = {0};
    queue<char> q;
    for(int i=0 ; i<str.length() ; i++){
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);


        while(!q.empty()){
            char frontch = q.front();
            if(freq[q.front()-'a'] > 1){
                q.pop();
            }
            else{
                cout<<frontch <<" ";
                break;
            } 
        }
        if(q.empty()){
            cout <<"#"<<" ";
        }
    }
}