#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int > max;


    priority_queue<int , vector<int>, greater<int>> min;

    max.push(1);
    max.push(3);
    max.push(5);
    max.push(6);

    
    min.push(1);
    min.push(3);
    min.push(5);
    min.push(6);
    min.push(10);

    int m = min.size();

    for(int i=0 ; i<m ; i++)
    {
        cout<<min.top();

        min.pop();
    } cout<<endl;

    // int n= max.size();
    // cout<<n<<endl;
    // for(int i=0 ; i< n ; i++)
    // {
    //     cout<<max.top();

    //     max.pop();
    // } cout<<endl;

    // cout<<" size is" << max.size();
}