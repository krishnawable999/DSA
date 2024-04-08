#include<iostream>
using namespace std;

class abc{
    public:
    static int x,y;

    // abc(int _x, int _y){
    //     x = _x;
    //     y = _y;
    // }

    void print() const{
        cout<<x<<" "<<y<<endl;
    }
};

int main(){
    abc a;
    a.x = 10;
    a.y = 20;
    a.print();
    // b.print();

}