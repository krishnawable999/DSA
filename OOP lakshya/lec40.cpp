#include<iostream>
using namespace std;

class Student{
    protected:
    int rno;
    public:
    void setrno(int);
    void getrno(void);
};

void Student::setrno(int rno){
    this->rno = rno;
}

void Student::getrno(void){
    cout<<"The Roll No. is: "<<rno<<endl;
}

class Exam : public Student{
    protected:
    float phy;
    float math;
    public:
    void setMarks(float, float);
    void getMarks(void);
};

void Exam ::setMarks(float phy, float math){
    this->phy = phy;
    this->math = math;
}

void Exam::getMarks(){
    cout<<"Physics Marks is: "<<phy<<endl;
    cout<<"Math makrs is : "<<math<<endl;
}

class Result: public Exam{
    public:
    void getResult(){
        cout<<"The marks are : "<<((phy+math)/2)<<endl;
    }
};

int main(){
    // Exam e1;
    // e1.setrno(16);
    // e1.getrno();
    // e1.setMarks(99,99);
    // e1.getMarks();
    Result krish;
    krish.setMarks(92, 97);
    krish.setrno(16);
    krish.getResult();

}