#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph{
    public:
    unordered_map<char, list<pair<char, int>>> adjList;

    void addEdge(char u, char v, int weight, bool directed){
        if(directed == true){
            adjList[u].push_back({v, weight});
        }
        else{
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
    }

    void print(){
        for(auto it:adjList){
            cout<<it.first<<"->";
            for(auto j:it.second){
                cout<<"{"<<j.first<<" , "<<j.second<<"}";
            }
            cout<<endl;
        }
    }

    void bellmanford(int n, char src){
        // set initial state
        vector<int> dist(n,INT_MAX);
        dist[src-'A'] = 0;

        // loop through n-1 
        // first relaxation
        for(int i=1 ; i<n ; i++){
            for(auto a:adjList){
                for(auto b:a.second){
                    char u = a.first;
                    char v = b.first;
                    int wt = b.second;

                    if(dist[u-'A'] != INT_MAX && dist[u-'A']+wt < dist[v-'A']){
                        dist[v-'A'] = dist[u-'A'] + wt;
                    }
                }
            }
        }

        // second relexation
        bool flag = false;

        
            for(auto a:adjList){
                for(auto b:a.second){
                    char u = a.first;
                    char v = b.first;
                    int wt = b.second;

                    if(dist[u-'A'] != INT_MAX && dist[u-'A']+wt < dist[v-'A']){
                        flag = true;
                        break;
                        dist[v-'A'] = dist[u-'A'] + wt;
                    }
                }
            }
        


        if(flag == true){
            cout<<"-ve cycle present"<<endl;
        }
        else{
            cout<<"No -ve cycle present"<<endl;
        }

        cout<<"Printing distance array"<<endl;

        for(int i=0 ; i<dist.size() ; i++){
            cout<<dist[i]<<" ";
        }
    }
};

int main(){
    Graph g;
    g.addEdge('A','B',-1, 1);
    g.addEdge('B','C', 2, 1);
    g.addEdge('C','D',-3, 1);
    g.addEdge('D','E',5, 1);
    g.addEdge('A','E',-4, 1);
    g.addEdge('B','E',-3, 1);
    g.addEdge('B','D',2, 1);
    g.addEdge('D','B',1, 1);
    g.addEdge('E','D',-3, 1);

    g.print();

    g.bellmanford(5,'A');

}