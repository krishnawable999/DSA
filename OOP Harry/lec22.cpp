#include<iostream>
#include<string>
using namespace std;

// Nesting of member functions 

class binary{
    private:
    string bin;
    public:
    void setData(string s){
        bin = s;
    }
    void isBin(void);
    void complement(void);
    void print(void);

};

void binary ::isBin(){
    for(int i=0 ; i<bin.length() ; i++){
        if(bin[i] != '0' && bin[i] != '1'){
            cout<<"String is not Binary"<<endl;
            return;
        }
    }
    cout<<"String is Binary"<<endl;
}

void binary ::complement(){
    for(int i=0 ; i<bin.length() ; i++){
        if(bin[i] == '0'){
            bin[i] = '1';
        }
        else{
            bin[i] = '0';
        }
    }
}

void binary::print(void){
    for(int i=0 ; i<bin.length() ; i++){
        cout<<bin[i];
    }
    cout<<endl;
}

int main(){
    binary b;
    string s;
    cout<<"Enter a binary String"<<endl;
    cin>>s;
    b.setData(s);
    b.print();
    b.isBin();
    b.complement();
    b.print();
    return 0;
}