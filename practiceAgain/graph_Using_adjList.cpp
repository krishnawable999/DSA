#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    public:
    unordered_map<T, list<T>> adjList;
    unordered_map<T, list<pair<T, int>>> adjListwt;

    void addEdge(T u, T v, bool direction){
        if(direction == 1){
            // directed graph
            adjList[u].push_back(v);
        }
        else{
            // undirected graph
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void weightedEdgeadd(T u, T v, bool direction, int wt){
        if(direction == 1){
            // directed graph
            adjListwt[u].push_back({v, wt});
        }
        else{
            adjListwt[u].push_back({v, wt});
            adjListwt[v].push_back({u, wt});
        }
        cout<<endl;
        printWtList();
        cout<<endl;
    }

    void printWtList(){
        for(auto it:adjListwt){
            cout<<it.first<<" : {";
            for(auto nbr:it.second){
                cout<<"{"<<nbr.first<<" ,"<<nbr.second<<"}";
            }
            cout<<"}"<<endl;
        }
    }

    void print(){
        for(auto it:adjList){
            cout<<it.first<<"{";
            for(auto nbr: it.second){
                cout<<nbr<<" ";
            }
            cout<<"}"<<endl;
        }
    }

    void bfs(T src){
        queue<T> q;
        unordered_map<T, bool> vis;
        q.push(src);

        while (!q.empty()){
            T frontNode = q.front();
            cout<<frontNode<<" ";
            q.pop();
            
            // goto neighbour
            for(auto nbr: adjListwt[frontNode]){
                T nbrdata = nbr.first;
                if(vis[nbrdata] == false){
                    q.push(nbrdata);
                    vis[nbrdata] = true;
                }
            }
        }
        
    }

    void dfs(T src, unordered_map<T, bool> &vis){
        vis[src] = true;
        cout<<src<<" ";

        for(auto nbr: adjListwt[src]){
            T nbrdata = nbr.first;
            if(vis[nbrdata] == false){
                dfs(nbrdata, vis);
            }
        }
    }
};

int main(){
    graph<char> g;
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,1);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,1);
    // g.addEdge(4,5,1);
    // g.addEdge(5,3,1);

    // g.weightedEdgeadd(0,1,1,5);
    // g.weightedEdgeadd(1,2,1,4);
    // g.weightedEdgeadd(1,3,1,2);
    // g.weightedEdgeadd(2,3,1,1);
    // g.weightedEdgeadd(3,4,1,4);
    // g.weightedEdgeadd(5,3,1,5);
    // g.weightedEdgeadd(4,5,1,7);
    unordered_map<char, bool> vis;
    g.weightedEdgeadd('a','b',0,5);
    g.weightedEdgeadd('a','c',0,10);
    g.weightedEdgeadd('b','c',0,20);
    g.weightedEdgeadd('c','d',0,50);
    g.weightedEdgeadd('c','e',0,50);
    g.weightedEdgeadd('e','f',0,50);

    g.dfs('a', vis);
    // g.bfs('a');
    // g.weightedEdgeadd(0,1,0,5);
    // g.weightedEdgeadd(1,2,0,4);
    // g.weightedEdgeadd(1,3,0,2);
    // g.weightedEdgeadd(2,3,0,1);
    // g.weightedEdgeadd(3,4,0,4);
    // g.weightedEdgeadd(5,3,0,5);
    // g.weightedEdgeadd(4,5,0,7);


    // g.printWtList();
    // g.print();

}