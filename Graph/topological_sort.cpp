#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adjList;

    void addEdge(int u, int v, bool direction){
        if(direction == 1){
            adjList[u].push_back(v);
        }
        else{
            // u -> v
            adjList[u].push_back(v);

            // v->u
            adjList[v].push_back(u);
        }
        // print();
    }

    void print(){
        for(auto it:adjList){
            cout<<it.first << "-> "<<"{";
            for(auto nbr:it.second){
                cout<<nbr<<",";
            }
            cout<<"}"<<endl;
        }
    }

    void topoSort(int src, unordered_map<int, bool> &vis, stack<int> &st){
        vis[src] = true;
        for(auto nbr:adjList[src]){
            if(!vis[nbr]){
                topoSort(nbr, vis, st);
            }
        }

        st.push(src);
    }

    void topoSortBsf(int n){
        queue<int> q;
        map<int, int> ind;

        for(auto it:adjList){
            for(auto nbr : it.second){
                ind[nbr]++;
            }
        }

        for(int node=0 ; node < n ; node++){
            if(ind[node] == 0){
                q.push(node);
            }
        }

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout<<frontNode << " ,";
            

            for(auto nbr:adjList[frontNode]){
                ind[nbr]--;

                if(ind[nbr] == 0){
                    q.push(nbr);
                }
            }

        }

        
    }

    void shortestPathBsf(int src, int dest){
        queue<int> q;
        map<int, bool> visited;
        map<int, int> parent;

        parent[src] = -1;
        visited[src] = true;
        q.push(src);
        while(!q.empty()){

            int frontNode = q.front();
            q.pop();

            for(auto nbr: adjList[frontNode]){
                if(!visited[nbr]){

                    q.push(nbr);
                    parent[nbr] = frontNode;
                    visited[nbr] = true;

                }
            }
        }

        vector<int> ans;
        while(dest != -1){
            ans.push_back(dest);
            dest = parent[dest];
        }

        // printing the shortest path
        reverse(ans.begin(), ans.end());
        for(auto it : ans){
            cout << it<< "->";
        }


    }
};

int main(){
    Graph g;

    g.addEdge(0,5,0);
    g.addEdge(5,4,0);
    g.addEdge(4,3,0);
    g.addEdge(0,6,0);
    g.addEdge(6,3,0);
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    
    // g.print();
    // int n = 8;
    // g.topoSortBsf(n);
    
    g.shortestPathBsf(0,3);

    // unordered_map<int, bool> vis;
    // stack<int> st;

    // for(int node=0 ; node < n; node++){
    //     if(!vis[node]){
    //         g.topoSort(node, vis, st);
    //     }
    // }
    // g.topoSort(0, vis, st);

    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

}