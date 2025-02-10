#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    public:
    unordered_map<T, list<pair<T,int>>> adjlist;

    void addedge(T u, T v, bool direction, int weight){
        if(direction == 1){
            adjlist[u].push_back({v,weight});
        }
        else{
            // if undirected graph
            // u->v
            adjlist[u].push_back({v,weight});
            // v -> u
            adjlist[v].push_back({u,weight});
        }

        // cout<<"printting the graph"<<endl;
        // print();
        // cout<<endl;
    }


    void print(){
        for(auto it:adjlist){
            cout<<it.first<<"->"<<"{";
            for(pair<T, int> p: it.second){
                cout<<"{"<<p.first<<", "<<p.second<<"}";
            }
            cout<<"}"<<endl;
        }
    }


    void bfs(T src, unordered_map<char, bool> &vis){
        
        queue<T> q;
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            T frontnode = q.front();
            cout<<frontnode<<" ";
            q.pop();

            //  goto nbr
            for(auto nbr: adjlist[frontnode]){
                T nbrdata = nbr.first;
                if(!vis[nbrdata]){
                    q.push(nbrdata);
                    vis[nbrdata] = true;
                }

            }

        }
    }

    void dfs(T src, unordered_map<T, bool> &vis){
        vis[src] = true;
        cout<<src<<" ";

        for(auto nbr: adjlist[src]){
            T nbrdata = nbr.first;
            if(!vis[nbrdata]){
                dfs(nbrdata, vis);
            }
        }
    }
};

int main(){
    Graph<char> g;
    unordered_map<char, bool> vis;
    g.addedge('a','b',0,10);
    g.addedge('b','c',0,20);
    g.addedge('b','d',0,22);
    g.addedge('b','e',0,21);
    g.addedge('e','h',0,21);
    g.addedge('e','i',0,21);

    g.dfs('a', vis);
    // for(char node = 'a' ; node<='x' ; node++){
    //     if(!vis[node]){
    //         g.bfs(node, vis);
    //     }
    // }
}