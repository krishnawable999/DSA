#include<bits/stdc++.h>
using namespace std;

bool find(int arr[][4] , int target, int n ,int m)
{
     for(int i=0 ;i<n ; i++)
    {
        for(int j=0; j<m ; j++)
        {
           if(arr[i][j] == target)
           {
            return 1;
           }
        }
    }
    return 0;
}

// void rowsum(int arr[][4])
// {
//       for(int i=0 ;i<n ; i++)
//     {
//         for(int j=0; j<m ; j++)
//         {
//            if(arr[i][j] == target)
//            {
//             return 1;
//            }
//         }
//     }
// }

int maxindex(int arr[][3] , int n ,int m)
{
    int maxi=INT_MIN;
    int sum = 0;
    int index = -1;
    for(int i=0 ;i<3 ; i++)
    {
        for(int j=0; j<3 ; j++)
        {
            sum += arr[i][j];
        }
        if(maxi > sum)
        {
            maxi = sum;
            index = i;
        }
       
    }

    cout<<"Max rowsum is : "<<maxi;
    return index;

    
}

int main()
{
    int arr[3][3];

    cout<<"Enter array elements"<<endl;
    for(int i=0 ;i<3 ; i++)
    {
        for(int j=0; j<3 ; j++)
        {
            cin>> arr[i][j];
        }
    }

    cout<<"Array elements are : "<<endl;
    for(int i=0 ;i<3 ; i++)
    {
        for(int j=0; j<3 ; j++)
        {
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }

  /*/  cout<<"Enter target elements : "<<endl;
    int target;
    cin>>target;

   cout<<"Element is present or not"<< find(arr[][], target);*/

   int num = maxindex(arr,3,3);
   cout<<"index is : "<<num<<endl;
}