#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adjlist;

    void addEdge(int u, int v, bool directed){
        // direction - 0- undirecred graph;
        // direction- 1 - directed graph;
        
        if(directed == 1){
            // directed graph
            // means that the edge is between u to v direction
            adjlist[u].push_back(v);
        }else{
            // undirected graph
            // u to v ek edge hain
            adjlist[u].push_back(v);

            // v to u bhi ek edge hain
             adjlist[v].push_back(u);
        }

        cout<<"Printing the graph values"<<endl;
        print();
        cout<<endl;
    }

    void print(){
        for(auto it: adjlist){
            cout<<it.first<<"->"<< "{";
            for(auto neighbour: it.second){
                cout<<neighbour<<",";
            }
            cout<<"}"<<endl;
        }
    } 
};

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,3,0);
}
