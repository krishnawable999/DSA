#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int *arr, int k, int n)
{
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        int ele = arr[i];
        if (ele < 0)
        {
            dq.push_back(i);
        }
    }

    for (int i = k; i < n; i++)
    {
       // cout << dq.front() << " ";
        if (dq.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            cout << arr[dq.front()] << " ";
        }
        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }

        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // last window ka answer
    if (dq.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << arr[dq.front()] << " ";
    }
}

int main()
{
    int arr[] = {2,-5,4,-1,-2,0,5};
    int  k =3;
    int n = 7;
    solve(arr,k,n);
}