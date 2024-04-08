#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Student{
    private:
    string crush;
    public:
    int id;
    string name;
    int no_of_sub;
    string dept;

    Student(){
        cout<<"Defalut constructor called"<<endl;
    }

    // parameterized ctor
    Student(int id, string name, int nos, string dept, string crush){
        this->id = id;
        this->name = name;
        this->no_of_sub = nos;
        this->dept = dept;
        this->crush = crush;
        cout<<"Ctor 2 called"<<endl;
    }

    Student(int _id, string _name, int _no_of_sub, string _dept){
        id = _id;
        name = _name;
        no_of_sub = _no_of_sub;
        dept = _dept;
        //crush = _crush;
        cout<<"Parameterized constructor called"<<endl;
    }

    void sleep(){
        cout<<"Sleeping"<<endl;
    }

    void gf(){
        cout<<crush<<endl;
    }

    ~Student(){
        cout<<"Desturctor called"<<endl;
    }

};

int main(){
    // string is a class
    // Student s;
    // // cout<<sizeof(s);
    // // string str;
    // Student s2(1,"Sayali B",5, "ENTC","Krishna");
    // cout<<s2.id<<endl;
    // cout<<s2.name<<endl;
    // s2.gf();
    // cout<<s2.crush<<endl;

    // cout<<sizeof(str);

    // Student s1(1,"Sayali",5,"ENTC");
    // cout<<s1.name<<endl;
    // cout<<s1.id<<endl;

    Student s1(20,"Krishna",6,"IT","Sayali");
    cout<<s1.id<<endl;
    cout<<s1.name<<endl;
    s1.gf();
    // cout<<endl;
//     Student s2 = s1;
//     cout<<s2.id<<endl;
//     cout<<s2.name<<endl;
}