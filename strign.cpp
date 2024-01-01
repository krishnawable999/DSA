#include<iostream>
#include<string>
using namespace std;
bool check(char ch[] , int n)
{
   
    int s=0;
    int e=n-1;

    while(s < e)
    {
        if(tolower(ch[s++]) != tolower(ch[e--])){
            return 0;
        }
        else{
            s++;
            e--;
            
        }
    }
    return 1;
}

char tolower(char ch)
{
    if(ch >='a' && ch <='z')
    {
        return ch;
    }
   
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
   
}

void reverse(char ch[], int n)
{
    int s=0;
    int e=n-1;

    while(s <= e)
    {
        swap(ch[s++] , ch[e--]);

    }
}

bool valid(char ch[] , int n)
{
    for(int i=0;i<n;i++)
    {
        if((ch[i]>='a' && ch[i]<='z') || (ch[i]>='A' && ch[i]<='Z') || (ch[i]>='0' && ch[i]<='9'))
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    cout<<"Enter size";
    cin>>n;
    char ch[n];
    cout<<"Enter a string"<<endl;
    cin>>ch;
    cout<<"String is palindrome or Not:  "<< check(ch , n);

    // cout<<"Reversed string is:  "<<endl;
    // reverse(ch,n);

   cout<<"Check for valid: "<< valid(ch, n);
   // cout<<"Check for lower to upper: " <<tolower('A');
   

   
}
   