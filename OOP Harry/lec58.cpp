#include<iostream>
using namespace std;

class CWH{
    protected:
    string name;
    float rating;
    public:
    CWH(string name, float rating){
        this->name = name;
        this->rating = rating;
    }

    virtual void display(){}
};

class videoLen: public CWH{
    float length;
    public:
    videoLen(string name, float rating, float length):CWH(name, rating){
        this->length = length;
    }

    void display(){
        cout<<"The length of the video is "<<length<<endl;
        cout<<"The name of the video is "<<name<<endl;
        cout<<"The rating of the video is "<<rating<<endl;

    }
};

class videoText: public CWH{
    int text;
    public:
    videoText(string name, float rating, int text): CWH(name, rating){
        this->text = text;
    }

    void display(){
        cout<<"The name of the video is "<<name<<endl;
        cout<<"The Rating of the video is "<<rating<<endl;
        cout<<"The Text Count of the video is "<<text<<endl;

    }
};


int main(){
    string name="Code with harry";
    float rating = 4.5;
    int len = 4.05;
    videoLen v(name, rating, len);
    v.display();

    int textlen = 423;
    videoText vt(name, rating, textlen);

    CWH *arr[2];
    arr[0] = &v;
    arr[1] = &vt;

    arr[0]->display();
    arr[1]->display();

}