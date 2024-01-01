#include<iostream>
#include<vector>
using namespace std;

void printSubarr(vector<int>& v,int s, int e)
{
    //base case
    if(e == v.size())
    {
        return;
    }

    //main case
    for(int i=s ; i <= e ; i++)
    {
        cout<<v[i]<<" ";
    } cout<<endl;
    //R.E call
    printSubarr(v,s,e+1);
}

void print(vector<int>& v)
{
    for(int start=0 ; start<v.size() ; start++)
    {
        int e = start;
        printSubarr(v,start,e);
    }
}

int main()
{
    vector<int> v{1,2,3,4,5};
    int s = 0;
    int e = s;
    print(v);

}