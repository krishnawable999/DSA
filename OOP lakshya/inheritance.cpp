#include<iostream>
#include<string>
using namespace std;

class Bird{
    public:
    int age;
    int weight;
    string color;

    void eat(){
        cout<<"Eating"<<endl;
    }
    void fly(){
        cout<<"Flying"<<endl;
    }
};

class Sparrow:private Bird{
    public:
    Sparrow(int age, int weight, string color){
        this->age = age;
        this->weight = weight;
        this->color = color;
    }

    string GetX(){
        return this->color;
    }
    void Grassing(){
        cout<<"Grassing"<<endl;
    }
};

class Piegon : public Bird{
    public:

    void Gittering(){
        cout<<"Gittering"<<endl;
    }
};

int main(){
    Sparrow s(2,5,"Brown");
    cout<<s.GetX();
    // cout<<s.age<<endl;
    // cout<<s.color<<endl;
    // s.Grassing();
    // Piegon p;
    // p.Gittering();
}