#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    int weight;

};
class Human: public Animal{
    public:
    string type;

    void print(){
        cout<<type<<endl;
    }

};

class male : public Human{
    public:
    string beard;

    void malechar(){
        cout<<beard<<endl;
    }
};

int main(){
    male m;
    m.age=21;
    m.weight=55;
    m.type="handsome";
    m.beard = "full";
    cout<<m.age<<endl;
    cout<<m.weight<<endl;
    cout<<m.type<<endl;
    cout<<m.weight<<endl;
}