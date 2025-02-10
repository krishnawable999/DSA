#include<iostream>
using namespace std;

class Human{
    protected:
    int weight;
    public:
    int height;
    int age;
    string name;

    void setWeight(int w){
        this->weight = w;
    }
    int getweight(){
        return this->weight;
    }

    void print(){
        cout<<"Height"<<this->height<<endl;
        cout<<"Age: "<<this->age<<endl;
        cout<<"Name:"<<this->name<<endl;
    }



};

class Male: public Human{
    public:
    string gender;

    

    void sleep(){
        cout<<"Sleeping"<<endl;
    }


};

int main(){
    Male m1;
    // cout<<m1.weight()<<endl;
    // cout<<m1.age<<endl;
    // cout<<m1.getweight()<<endl;
    // cout<<m1.sleep()<<endl;
    // m1.name = "krishna"<<endl;
    // cout<<m1.age<<endl;
    m1.name="Krishna";
    m1.setWeight(21);
    cout<<m1.getweight()<<endl;
    m1.print();

}