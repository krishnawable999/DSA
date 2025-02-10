#include<iostream>
using namespace std;

class Hero{
    private:
    int health;
    public:
    // string name;
    string behaviour;
    char *name;

    Hero(){
        cout<<"Default ctor Called"<<endl;
        name = new char[7];
    }

    // paramertrized Ctor
    Hero(int health, char name[], string behaviour){
        
        this->name = name; 
        this->health = health;
        this->behaviour = behaviour;
        // this->name = name;
    }
    // Copy Constrctor
    // if we used pass by value then it will stuck inside the infinite loop, for that we use pass by reference method
    Hero(Hero &temp){
        cout<<"Copy Ctor Called"<<endl;
        this->health = temp.health;
        this->name = temp.name;
        this->behaviour = temp.behaviour;
    }



    int gethealth(){
        return health;
    }

    void sethealth(int h){
        health = h;
    }

    void print(){
        // cout<<"Char name :" <<this->
        cout<<"The health is: "<<this->health<<endl;
        cout<<"Behaviour"<<this->behaviour<<endl;
        cout<<"Name : "<<this->name<<endl;
    }

};
int main(){

    // Deep vs Shalow Copy
    char name[8]="Krishna";
    Hero h1(70, name, "Polite");
    h1.print();

    // Hero h2(h1);
    // h2.print();






    // // Copy Ctor
    // Hero h1(70, "Ishita","Angry");
    // // h1.print();

    // Hero h2(h1);
    // h2.print();












    // Hero h1(50, "krishna", "Polite");
    // cout<<h1.gethealth()<<endl;
    // cout<<h1.name<<endl;
    // cout<<h1.behaviour<<endl;
    // cout<<h1.behaviour;
    // cout<<"Size :"<<sizeof(h1)<<endl;
    // h1.name={'K','r','i','s','h','n','a'};
    // h1.name="Krishna";
    // h1.behaviour="Angry";
    // cout<<h1.behaviour<<endl;
    // cout<<h1.name<<endl;
    // h1.sethealth(70);
    // cout<<h1.gethealth()<<endl;

    // Dynamic Allocation

    // Hero *h = new Hero(50, "Krishna", "Polite");
    // h->behaviour="Polite";
    // cout<<h->behaviour<<endl;
    // // h->sethealth(80);
    // cout<<h->gethealth()<<endl;
    // // h->name = "Wable";
    // cout<<h->name<<endl;



}