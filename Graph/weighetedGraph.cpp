#include<bits/stdc++.h>
using namespace std;

// class Graph{
//     public:
//     unordered_map<int, list<pair<int, int>>> adjList;

//     void addEdge(int u, int v, bool direction, int weight){
//         if(direction == 1){
//             adjList[u].push_back({v, weight});
//         }else{
//             adjList[u].push_back({v, weight});
//             adjList[v].push_back({u, weight});
//         }
//     }


//     void print(){
//         for(auto it:adjList){
//             cout<<it.first<<": {";
//             for(auto nbrPair: it.second){
//                 cout<<"{";
//                 cout<<nbrPair.first<<", ";
//                 cout<<nbrPair.second<<" }, ";
//             }
//             cout<<"}";
//             cout<<endl;
//         }
//     }

//     void bfs(int src){
//         unordered_map<int, bool> vis;
//         queue<int > q;
//         q.push(src);
//         vis[src] = true;

//         while(!q.empty()){
//             int frontNode = q.front();
//             q.pop();
//             cout<<frontNode<<" ";
//             // goto the neighbour of the node
//             for(auto nbr:adjList[frontNode]){
//                 int nbrdata = nbr.first;
//                 if(!vis[nbrdata]){
//                     q.push(nbrdata);
//                     vis[nbrdata] = true;
//                 }
//             }
//         }
//     }

//     void dfs(int src, unordered_map<int, bool> &vis){
//         vis[src] = true;
//         cout<<src<< " ";

//         for(auto nbr:adjList[src]){
//             int nbrdata = nbr.first;
//             if(!vis[nbrdata]){
//                 // vis[nbrdata] = true;
//                 dfs(nbrdata, vis);
//             }
//         }
//     }
// };

class Graph{
    public:
    unordered_map<int, list<int>> adjList;


    void addEdge(int u, int v, bool direction){
        if(direction == 1){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void print(){
        for(auto it:adjList){
            cout<<it.first<<": {";
            for(auto nbrPair: it.second){
                cout<<"{";
                cout<<nbrPair<<", ";
                cout<<" }";
            }
            cout<<"}";
            cout<<endl;
        }
    }

    bool isCyclePresentUndirectedBFS(int src){
        unordered_map<int, bool> vis;
        unordered_map<int ,int> parent;
        vis[src] = true;
        parent[src] = -1;

        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int frontnode = q.front();
            q.pop();
            for(auto nbr:adjList[frontnode]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = frontnode;
                }
                else if(vis[nbr] == true && nbr != parent[frontnode]){
                    // in this case cycle is present
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Graph g;
    // g.addEdge(0,1,1, 12);
    // g.addEdge(1,2,1, 10);
    // g.addEdge(1,2,1, 17);
    // g.addEdge(2,3,1, 18);
    // // g.print();
    // // g.bfs(0);
    // unordered_map<int, bool> vis;
    // g.dfs(0, vis);

    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(0,3,0);
    g.addEdge(1,2,0);
    g.addEdge(3,4,0);
    // g.print();
    bool flag = g.isCyclePresentUndirectedBFS(0);
    if(flag){
        cout<<"Cycle is Present"<<endl;

    }else{
        cout<<"Cycle is not Present"<<endl;
    }
    
}