#include<iostream>
#include<queue>
using namespace std;

class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c){
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

class compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }

};

void mergeKsortedArray(int arr[][4], int n,int k ,vector<int> &ans){
    priority_queue<Info*,vector<Info*>,compare> pq;

    for(int row=0 ; row<k ;  row++){
        int element = arr[row][0];
        Info* temp = new Info(element,row,0);
        pq.push(temp);
    }

    while(!pq.empty()){
        Info* temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int toprow = temp->rowIndex;
        int topcol = temp->colIndex;


        // store ans in the vector
        ans.push_back(topData);

        // next element in same row jya row madhun elememt pop kelay
        // tya element la insert karne
        if(topcol+1 < n){
            Info* newInfo = new Info(arr[toprow][topcol+1],toprow,topcol+1);
            pq.push(newInfo);
        }
    }
}

int main(){
    int arr[3][4] = {
        {1,4,7,10},
        {2,3,8,11},
        {5,6,9,12}
    };
    int n = 4;
    int k=3;
    vector<int> ans;
    mergeKsortedArray(arr,n,k,ans);

    cout<<"Printing answer: "<<endl;

    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    } cout<<endl;
}