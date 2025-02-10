#include<iostream>
using namespace std;

class b;
class a{
    int x;
    friend void swap(a &, b &);
    public:
    void setVal(int x){
        this->x = x;
    }
    void display(void){
        cout<<"The val of x is: "<<x<<endl;
    }
};

class b{
    int y;
    friend void swap(a &, b &);
    public:
    void setVal(int y){
        this->y = y;
    }

    void display(void){
        cout<<"The val of y is: "<<y<<endl;
    }
};


void swap(a &o1, b&o2){
    int temp = o1.x;
    o1.x = o2.y;
    o2.y = temp;
}

int main(){
    a o1;
    o1.setVal(12);
    b o2;
    o2.setVal(23);

    o1.display();
    o2.display();

    cout<<"After Swapping"<<endl;
    swap(o1, o2);
    o1.display();
    o2.display();

    
}