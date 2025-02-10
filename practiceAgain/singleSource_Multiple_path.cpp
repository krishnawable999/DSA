#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v, int wt, bool directed)
    {
        if (directed == 1)
        {
            adj[u].push_back({v, wt});
        }
        else
        {
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }

    void print()
    {
        for (auto it : adj)
        {
            cout << it.first << " : -> {";
            for (auto nbr : it.second)
            {
                cout << "{" << nbr.first << " ," << nbr.second << "},";
            }
            cout << "}" << endl;
        }

        cout << endl;
    }

    void topoOrderDFS(int src, stack<int> &st, unordered_map<int, bool> &vis)
    {
        vis[src] = true;

        for (auto nbr : adj[src])
        {
            int nbrData = nbr.first;
            int nbrWeight = nbr.second;

            if (!vis[nbrData])
            {
                vis[nbrData] = true;
                topoOrderDFS(nbrData, st, vis);
            }
        }

        st.push(src);
    }

    void shortestPathDFS(stack<int> &topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if (dist[src] + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        while (!topoOrder.empty())
        {
           int  src = topoOrder.top();
            topoOrder.pop();

            for (auto nbrPair : adj[src])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (dist[src] + nbrDist < dist[nbrNode])
                {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }

        for(auto it:dist){
            cout<<it<<" ";
        }
    }

    void dijkstraShortestPath(int n, int src, int dest){
        vector<int> dist(n+1, INT_MAX);
        set<pair<int,int>> st;

        st.insert({0,src});
        dist[src] = 0;

        while(!st.empty()){
            auto topElement = st.begin();
            pair<int, int> topPair = *topElement;
            int topDist = topPair.first;
            int topNode = topPair.second;
            st.erase(st.begin());

            // update the distance 
            for(auto nbrPair: adj[topNode]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if(topDist + nbrDist < dist[nbrNode]){
                    // new dist found
                    // now update the distance
                    // first erase entry from the set and then add new entry
                    auto previousEntry =  st.find({dist[nbrNode], nbrNode});
                    if(previousEntry != st.end()){
                        st.erase(previousEntry);
                    }

                    dist[nbrNode] = topDist + nbrDist;

                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        cout<<"Shortest distance from node "<<src<<" to node"<<" dest "<<dest<<" is "<<dist[dest]<<endl;
    }
};

int main()
{
    graph g;
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(0, 2, 3, 1);
    // g.addEdge(1, 3, 3, 1);
    // g.addEdge(2, 1, 2, 1);
    // g.addEdge(2, 3, 5, 1);
    // g.addEdge(2, 4, 6, 1);
    // g.addEdge(4, 3, 1, 1);
    // g.print();

    // stack<int> st;
    // unordered_map<int, bool> vis;
    // int src = 0;
    // g.topoOrderDFS(src, st, vis);
    // g.shortestPathDFS(st, 5);

     g.addEdge(1, 6, 14, 0);
     g.addEdge(1, 2, 7, 0);
     g.addEdge(1, 3, 9, 0);
     g.addEdge(2, 3, 10, 0);
     g.addEdge(2, 4, 15, 0);
     g.addEdge(3, 4, 11, 0);
     g.addEdge(4, 5, 6, 0);
     g.addEdge(5, 6, 9, 0);
     g.addEdge(6, 3, 2, 0);


    int n= 6;
    int src = 6;
    int dest = 4;
    g.dijkstraShortestPath(n, src, dest);

}