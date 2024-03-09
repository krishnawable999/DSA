#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> mp;

    // ways to insrt value to the map
    pair<string,int> p = make_pair("Krishna",20);

    pair<string,int> q("Pratik",20);

    pair<string,int> r;
    r.first = "Krishnaraj";
    r.second = 21;

    mp.insert(p);
    mp.insert(q);
    mp.insert(r);

    cout<<"Map Created successfully"<<endl;

    cout << "size" << mp.size();

    cout << "Value at" <<mp.at("Krishna");



}