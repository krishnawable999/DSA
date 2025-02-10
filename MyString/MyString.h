#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>
using namespace std;

class MyString{
    private:
    int length;
    char* data;

    public:
    // default ctor
    MyString();

    // parameterized ctor
    MyString(const char* str);

    // copy ctor
    MyString(const MyString& other);

    // dtor
    ~MyString();
    int size() const;

    bool empty() const;

    const char* c_str() const;

    char operator[] (int index);
    friend std::ostream&operator<<(std::ostream &os, const MyString&str);

};


#endif