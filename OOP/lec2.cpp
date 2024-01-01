//Love Babbar lecture-2 OOP

#include<iostream>
using namespace std;

class Animal{
    //delaring private variables
    private:
    int height;
    int weight;
    int type;
//public variables
    public:
    void eat(){
        cout<<"Eating Food"<<endl;
    }
    void bark(){
        cout<<"meoww At Night"<<endl;
    }
    void sleep(){
        cout<<"Sleeps a lot"<<endl;
    }
    void heightt(){
        cout<<"Height" << height<<endl;
    }
    
    //getters and Setters for private varisbles
    //using this keyword
    int getvalue(){
        return this->height;
    }
    void setvalue(int height){
        this -> height = height;
    }
};
//child class of parent class animal
class cat: public Animal{

};
int main(){
    //accessing Parent class via child class
    cat c;
    c.eat();
    c.sleep();
    c.bark();

    //Calling grtter and setter using child class
    c.setvalue(20);
    c.heightt();
}