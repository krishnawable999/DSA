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

    Student(int _id, string _name, int _no_of_sub, string _dept, string _crush){
        id = _id;
        name = _name;
        no_of_sub = _no_of_sub;
        dept = _dept;
        crush = _crush;
        cout<<"Parameterized constructor called"<<endl;
    }

    void sleep(){
        cout<<"Sleeping"<<endl;
    }

    void gf(){
        cout<<crush;
    }

};

int main(){
    // string is a class
    Student s;
    // cout<<sizeof(s);
    // string str;
    Student s2(1,"Sayali B",5, "ENTC","Krishna");
    cout<<s2.id<<endl;
    cout<<s2.name<<endl;
    s2.gf();
    // cout<<s2.crush<<endl;

    // cout<<sizeof(str);
}