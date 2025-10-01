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


    void shortestPathBFS(int src, int dest){
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;
        queue<int> q;

        q.push(src);
        vis[src]= true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr:adjList[frontNode]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
        }

        vector<int> v;
        while(dest != -1){
            v.push_back(dest);
            dest = parent[dest];
        }

        reverse(v.begin(), v.end());

        for(auto it:v){
            cout<<it<<" ";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0,4,0);
    g.addEdge(0,3,0);
    g.addEdge(0,6,0);
    g.addEdge(4,1,0);
    g.addEdge(3,5,0);
    g.addEdge(6,2,0);
    g.addEdge(1,5,0);
    g.addEdge(2,5,0);
    g.shortestPathBFS(0,5);
}