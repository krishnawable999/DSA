#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class graph{
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
            cout<<it.first<<" : {";
            for(auto nbr:it.second){
                cout<<nbr<<" ,";
            }
            cout<<"}"<<endl;
        }
    }

    void topoSortDFS(int src, unordered_map<int, bool> &vis, stack<int> &st){
        vis[src] = true;

        for(auto nbr:adjList[src]){
            if(!vis[nbr]){
                vis[nbr] = true;
                topoSortDFS(nbr, vis, st);
            }
        }
        st.push(src);
    }

    void topoSortBFS(int n){
        unordered_map<int, int> indegree;
        queue<int> q;

        for(auto it:adjList){
            for(auto nbr:it.second){
                indegree[nbr]++;
            }
        }

        for(int node=0 ; node<n ; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }
        
        while(!q.empty()){
            int frontnode = q.front();
            q.pop();
            cout<<frontnode<<" ";

            for(auto nbr:adjList[frontnode]){
                indegree[nbr]--;

                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }

    void shortestPathBFS(int src, int dest , queue<int> &q){
        
        unordered_map<int, int> parent;
        unordered_map<int, bool> vis;
        vector<int> ans;
        q.push(src);
        parent[src] = -1;
        vis[src] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto nbr : adjList[frontNode]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
        }

        while(dest != -1){
            ans.push_back(dest);
            dest = parent[dest];
        }

        reverse(ans.begin(), ans.end());
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int main(){
    graph g;
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,1);
    // g.addEdge(3,5,1);
    // g.addEdge(4,6,1);
    // g.addEdge(5,6,1);
    // g.addEdge(6,7,1);


    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    // g.addEdge(2,4,1);
    // g.addEdge(3,4,1);
    // g.addEdge(4,5,1);
    // g.addEdge(5,6,1);
    // g.addEdge(5,7,1);

    g.addEdge(0,4,0);
    g.addEdge(0,3,0);
    g.addEdge(0,6,0);
    g.addEdge(4,1,0);
    g.addEdge(3,5,0);
    g.addEdge(6,2,0);
    g.addEdge(1,5,0);
    g.addEdge(2,5,0);
    g.print();

    queue<int> q;
    g.shortestPathBFS(0,5, q);
    // int n = 8;
    // g.topoSortBFS(n);
    // unordered_map<int, bool> vis;
    // unordered_map<int, int> indegree;
    // stack<int> st;
    // g.topoSortDFS(0, vis, st);
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

}