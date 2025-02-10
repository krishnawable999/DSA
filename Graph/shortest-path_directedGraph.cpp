#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, bool directed, int weight)
    {
        // if direction u-> v, directed == 0
        if (directed == 0)
        {
            // u -> v
            adj[u].push_back({v, weight});

            // v -> u
            adj[v].push_back({u, weight});
        }

        else if (directed == 1)
        {
            // u -> v
            // directed graph
            adj[u].push_back({v, weight});
        }
    }

    void printAdjlist()
    {
        cout << "Printing Adj List" << endl;

        for (auto it : adj)
        {
            cout << it.first << "-> {";
            for (auto nbr : it.second)
            {
                cout << "(" << nbr.first << "," << nbr.second << ")";
            }

            cout << "}" << endl;
        }
    }

    void topoOrderDfs(int src, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[src] = true;

        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;

            if (!visited[nbrNode])
            {
                topoOrderDfs(nbrNode, visited, topo);
            }
        }

        topo.push(src);
    }

    void shortestPathDfs(stack<int> &topoOrder, int n)
    {
        // initially
        vector<int> dist(n, INT_MAX);
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        //
        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;

            if (dist[src] + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        // do this for all the nodes

        while (!topoOrder.empty())
        {
            int src = topoOrder.top();
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

        cout << "Printing DFS array" << endl;

        for (auto it : dist)
        {
            cout << it << " ";
        }
    }

    void dijkstraShortestPath(int n ,int src, int dest){
        set<pair<int, int>> st;
        vector<int> dist(n+1, INT_MAX);

        st.insert({0,src});
        dist[src] = 0;

        while(!st.empty()){
            auto topElement = st.begin();
            pair<int, int> topPair = *topElement;
            int topNode = topPair.first;
            int topDist = topPair.second;
            // remove the topNode;
            st.erase(st.begin());

            // update the nbr distance

            for(pair<int, int> nbrPair : adj[topNode]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if(topDist + nbrDist < dist[nbrNode]){
                    // found a shorter node
                    // update all entries
                    auto nbrEntry = st.find({dist[nbrNode], nbrNode});
                    if(nbrEntry != st.end()){
                        // if new entry found delete the previous entry
                        st.erase(nbrEntry);
                    }

                    
                }
            }

        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1, 5);
    g.addEdge(0, 2, 1, 3);
    g.addEdge(2, 1, 1, 2);
    g.addEdge(1, 3, 1, 3);
    g.addEdge(2, 3, 1, 5);
    g.addEdge(2, 4, 1, 6);
    g.addEdge(4, 3, 1, 1);

    // g.printAdjlist();

    unordered_map<int, bool> visited;
    stack<int> topo;
    int src=0;
    g.topoOrderDfs(src, visited, topo);

    // while (!topo.empty())
    // {
    //     cout<<topo.top()<< " ";
    //     topo.pop();
    // }

    // cout<<endl;
    int n = 5;
    g.shortestPathDfs(topo, n);
}