#include<iostream>
using namespace std;

class abc{

    int x;
    int *y;
    int  z;

    public:

    abc(int _x, int _y, int _z=0){
        x = _x;
        y = new int(_y);
        z = _z;
    }
    void setX(int val){
        x = val;
    }

    int getX() const {
        return x;
    }

    void setY(){
        *y = val;
    }

    int getY(int val) const {
       return *y;
    }

    void setZ(int val){
        z = val;
    }

    int getZ() const{
        return z;
    }
};

void print(const abc &a){
    cout<<a.getX();
}

int main(){
    abc a(1,2);
    print(a);
}