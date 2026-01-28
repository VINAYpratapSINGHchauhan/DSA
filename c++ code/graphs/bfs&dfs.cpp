#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;
template<typename T>
class graph{
    public:
        unordered_map<T,list<pair<T,int>>>nodeToAdjList;
        void addEdge(T u,T v,int wt,bool direction){
            // if direction=0 -> unidrected graph ( u to v & v to u BOTH DIRECTION are taken )
            // if direction=1 -> directed graph ( from u to v direction )
            if(direction==1){
                // u se v ki trf ek edge hai toh u ki adjanceny list mei v ko add krdo 
                nodeToAdjList[u].push_back({v,wt});
            }else{
                // u se v and v se u dono trf ki hme edge lgani hai
                nodeToAdjList[u].push_back({v,wt});
                nodeToAdjList[v].push_back({u,wt});
            }
            // cout<<endl;
            // printgraph();
            return ;
        }
        void printgraph(){
            for(auto & e:nodeToAdjList){
                cout<<e.first<<" -> {";
                for(auto & neighbour:e.second){
                    cout<<" {"<<neighbour.first<<","<<neighbour.second<<"} ";
                }
                cout<<"}"<<endl;
                cout<<endl;
            }
        }
        void bfsTraversel(T source,unordered_map<T,bool>&visited){
            queue<T>q;
            q.push(source);
            visited[source]=true;
            while(!q.empty()){
                T front=q.front();
                q.pop();
                cout<<front<<" ";
                for(auto &nbrPair:nodeToAdjList[front]){
                    T nbr=nbrPair.first;
                    if(!visited[nbr]){
                        visited[nbr]=true;
                        q.push(nbr);
                    }
                }
            }
            return ;
        }
        void dfsTraversel(T source,unordered_map<T,bool>&visited){
            visited[source]=true;
            cout<<source<<" ";
            for(auto &nbrPair:nodeToAdjList[source]){
                T nbr=nbrPair.first;
                if(!visited[nbr]){
                    dfsTraversel(nbr,visited);
                }
            }
            return ;
        }
};

int main(){
    graph<char> g;
    // directed weighted graph 
    g.addEdge('a','b',5,1);
    g.addEdge('a','c',10,1);
    g.addEdge('c','d',15,1);
    g.addEdge('d','e',15,1);
    g.addEdge('c','e',20,1);
    g.addEdge('e','f',20,1);

    //traversing graph through BREADTH FIRST SEARCH 
    //traversing that it will handle also edge cases of disconnected graphs
    unordered_map<char,bool>visited;
    for(char node='a';node<='f';node++){
        if(!visited[node])g.bfsTraversel(node,visited);
    }

    cout<<endl;
    
    //traversing graph through DEPTH FIRST SEARCH 
    //traversing that it will handle also edge cases of disconnected graphs
    unordered_map<char,bool>visited2;
    for(char node='a';node<='f';node++){
        if(!visited2[node])g.dfsTraversel(node,visited2);
    }



    return 0;
}