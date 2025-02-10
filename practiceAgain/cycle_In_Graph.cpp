#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    public:
    unordered_map<T, list<T>> adjList;
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

    bool isCycleBFS(int src, unordered_map<int, int> &parent, unordered_map<int, bool> &vis){
        queue<T> q;
        q.push(src);
        vis[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            T frontNode = q.front();
            q.pop();
            // cout<<frontNode<<" ";

            for(auto nbr: adjList[frontNode]){
                T nbrdata = nbr;
                if(!vis[nbrdata]){
                    q.push(nbrdata);
                    vis[nbrdata] = true;
                    parent[nbrdata] = frontNode;
                }
                else if(vis[nbrdata] == true && nbrdata != parent[frontNode]){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS(int src, unordered_map<int, bool> &vis, int parent){
        vis[src] = true;

        for(auto nbr:adjList[src]){
            if(!vis[nbr]){
                // vis[nbr] = true;
                // parent = src;
                bool ans = isCyclicDFS(nbr, vis, src);
                if(ans == true){
                    return true;
                }
            }
            else if (vis[nbr] == true && nbr != parent){
                return true;
            }
        }
        return false;
    }


};

int main(){
    graph<int> g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,4,1);
    g.addEdge(3,4,1);
    g.addEdge(2,5,1);
    // unordered_map<int, int> parent;
    unordered_map<int, bool> vis;
    // g.isCycle(0, parent, vis);
    // bool ans = g.isCycle( 0, parent, vis);
    int parent = -1;
    bool ans = g.isCyclicDFS( 0, vis, parent);

    if(ans == true){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

}