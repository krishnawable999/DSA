#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;


    //creating array
    int **arr = new int*[n];
    //allocating blocks to array
    for(int i=0;i<n;i++)
    {
        cout<<"Enter size"<<endl;
        int s;
        cin>>s;
        arr[i] = new int [s];
    }
    //taking inputs
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n ; j++)
        {
            cin>>arr[i][j];
        }
    }
    //output
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n ; j++)
        {
            cout<<arr[i][j]<<" ";
        } cout<<endl;
    }
}