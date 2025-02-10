#include<iostream>
using namespace std;

class Student{
    protected:
    int rno;
    public:

    void setrno(int rno){
        this->rno = rno;
    }

    void getrno(){
        cout<<"The roll number is: "<<rno<<endl;
    }
};

class Test: virtual public Student{
    protected:
    float math;
    float phy;
    public:

    void setMarks(float math, float phy){
        this->math = math;
        this->phy = phy;
    }

    void getMarks(){
        cout<<"Physics: "<<phy<<endl
            <<"Math: "<<math<<endl;
    }
};

class Sport: virtual public Student{
    protected:
    int score;
    public:
    void setScore(int score){
        this->score = score;
    }

    void getScore(){
        cout<<"Your Score is: "<<score<<endl;
    }
};

class Result: public Sport, public Test{
    public:
    void display(){
        int total = math + phy + score;
        getrno();
        getMarks();
        getScore();
        cout<<"The Total marks are: "<<total<<endl;
    }
};


int main(){
    Result r;
    r.setrno(16);
    r.setMarks(94,97);
    r.setScore(45);
    r.display();
}