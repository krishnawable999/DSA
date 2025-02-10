#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class graph{
    public:
    unordered_map<char,list<pair<char,int>>> adj;

    void addEdge(char u, char v, bool direction, int wt){
        if(direction == 1){
            adj[u].push_back({v,wt});
        }
        else{
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }

    void print(){
        for(auto it:adj){
            cout<<it.first<<" : {";
            for(auto nbr:it.second){
                cout<<"{ "<<nbr.first<< " ,"<<nbr.second<<" }, ";
            }
            cout<<" }"<<endl;
        }
    }

    void bellmonFord(vector<int> &dist, int n, char src){
        dist[src-'A'] = 0; 

        for(int i=1 ; i<n ; i++){
            for(auto a : adj){
                for(auto nbr : a.second){
                    char u = a.first;
                    char v = nbr.first;
                    int wt = nbr.second;
                    if(dist[u-'A'] != INT_MAX && dist[u-'A'] + wt < dist[v-'A']){
                        dist[v-'A'] = dist[u-'A'] + wt;
                    }
                }
            }
        }
        // shortest path is ready till here
        // check for -ve cycle
        // run a loop one more time to check for -ve cycle
        bool flag = false;
        for(auto a : adj){
                for(auto nbr : a.second){
                    char u = a.first;
                    char v = nbr.first;
                    int wt = nbr.second;
                    if(dist[u-'A'] != INT_MAX && dist[u-'A'] + wt < dist[v-'A']){
                        dist[v-'A'] = dist[u-'A'] + wt;
                        flag = true;
                        break;
                    }
                }
            }

            if(flag == true){
                cout<<"-ve cycle present"<<endl;
            }
            else{
                cout<<"No -ve cycle present"<<endl;
                for(auto it:dist){
                    cout<<it<<" ";
                }
                cout<<endl;
            }

    }
};

int main(){
    graph g;
    // g.addEdge(0,1,1,10);
    // g.addEdge(1,2,1,5);
    // g.addEdge(1,3,1,4);
    // g.addEdge(2,3,1,7);
    // g.addEdge(4,5,1,6);
    // g.addEdge(5,6,1,5);

    g.addEdge('A','B',1, -1);
    g.addEdge('B','C',1, 2);
    g.addEdge('C','D',1, -3);
    g.addEdge('D','E',1, 4);
    g.addEdge('A','E',1, 4);
    g.addEdge('B','E',1, 3);
    g.addEdge('B','D',1, 2);
    g.addEdge('D','B',1, 1);
    int n = 5;
    vector<int> dist(n,INT_MAX);
    g.bellmonFord(dist, n, 'A');
    g.print();
}