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

    bool isCyclicUndirectedBFS(int src){
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;

        queue<int> q;
        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto nbr:adjlist[frontNode]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = frontNode;
                }

                else if(vis[nbr] == true && nbr != parent[frontNode]){
                    // cycle is present 
                    return true;
                }
            }
        }

        // cycle is not present
        return false;
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    g.addEdge(3,4,0);
    g.addEdge(2,5,0);

    bool isCyclic = g.isCyclicUndirectedBFS(0);
    if(isCyclic){
        cout<<"Cycle is Present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }


}
