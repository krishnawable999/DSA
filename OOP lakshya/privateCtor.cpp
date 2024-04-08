#include<iostream>
using namespace std;
//  Interview question
// Can constructor made private => Yes, Construector  can be made private by adding it under the private scope

class Box{
    private:
    int width;

    Box(int width){
        this->width = width;
    }
    public:
    

    int getwidth(){
        return width;
    }

    void setWidth(int width){
        this->width = width;
    }
    friend class BoxFriend;
};

class BoxFriend{
    private:
    int cnt;

    public:
    Box getABox(int width){
        return Box(width);
    }
};

int main(){
    // Box b(10);
    // cout<<b.getwidth()<<endl;
    BoxFriend bfact;

    Box b = bfact.getABox(10);
    cout<<b.getwidth()<<endl;

}