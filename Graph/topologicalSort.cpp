#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction){
        if(direction == 1){
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void print(){
        for(auto it:adjList){
            cout<<it.first<<": {";
            for(auto nbr:it.second){
                cout<<nbr<<" ,";
            }
            cout<<"}"<<endl;
        }
    }

    void toposort(int src, unordered_map<int, bool> &vis, vector<int> &v){
        vis[src] = true;

        for(auto nbr:adjList[src]){
            if(!vis[nbr]){
                toposort(nbr, vis, v);
            }

        }

        v.push_back(src);
    }

    void toposortBFS(int n){
        unordered_map<int, int> indegree;
        queue<int> q;

        // initialize the indegree
        for(auto it:adjList){
            for(auto nbr:it.second){
                indegree[nbr]++;
            }
        }

        // initialize the queue

        for(int node=0 ; node<n ; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        while(!q.empty()){
            int frontnode = q.front();
            q.pop();

            cout<<frontnode<<", ";
            for(auto nbr:adjList[frontnode]){
                indegree[nbr]--;

                // check if value of indegree in not less than zero
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        // for(auto it:indegree){
        //     cout<<it.first<<" :"<<it.second<<endl;
        // }
    }
};


int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);

    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    // g.addEdge(2,4,1);
    // g.addEdge(3,5,1);
    // g.addEdge(4,5,1);
    // g.addEdge(5,6,1);
    // g.addEdge(5,7,1);

    g.toposortBFS(8);
    // unordered_map<int, bool> vis;
    // vector<int> v;
    // g.toposort(0, vis, v);
    // for(auto it:v){
    //     cout<<it<<" ";
    // }
}