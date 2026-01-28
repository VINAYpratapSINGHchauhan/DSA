#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

//graph creation
// class graph{
//     public:
//         unordered_map<int,list<int>>nodeToAdjList;
//         void addEdge(int u,int v,bool direction){
//             // if direction=0 -> unidrected graph ( u to v & v to u BOTH DIRECTION are taken )
//             // if direction=1 -> directed graph ( from u to v direction )
//             if(direction==1){
//                 // u se v ki trf ek edge hai toh u ki adjanceny list mei v ko add krdo 
//                 nodeToAdjList[u].push_back(v);
//             }else{
//                 // u se v and v se u dono trf ki hme edge lgani hai
//                 nodeToAdjList[u].push_back(v);
//                 nodeToAdjList[v].push_back(u);
//             }
//             cout<<endl;
//             printgraph();
//             return ;
//         }
//         void printgraph(){
//             for(auto & e:nodeToAdjList){
//                 cout<<e.first<<" -> {";
//                 for(auto & neighbour:e.second){
//                     cout<<neighbour<<",";
//                 }
//                 cout<<"} "<<endl;
//                 cout<<endl;
//             }
//         }
// };

// graph code that handles also weighted graphs
// class graph{
//     public:
//         unordered_map<int,list<pair<int,int>>>nodeToAdjList;
//         void addEdge(int u,int v,int wt,bool direction){
//             // if direction=0 -> unidrected graph ( u to v & v to u BOTH DIRECTION are taken )
//             // if direction=1 -> directed graph ( from u to v direction )
//             if(direction==1){
//                 // u se v ki trf ek edge hai toh u ki adjanceny list mei v ko add krdo 
//                 nodeToAdjList[u].push_back({v,wt});
//             }else{
//                 // u se v and v se u dono trf ki hme edge lgani hai
//                 nodeToAdjList[u].push_back({v,wt});
//                 nodeToAdjList[v].push_back({u,wt});
//             }
//             cout<<endl;
//             printgraph();
//             return ;
//         }
//         void printgraph(){
//             for(auto & e:nodeToAdjList){
//                 cout<<e.first<<" -> {";
//                 for(auto & neighbour:e.second){
//                     cout<<" {"<<neighbour.first<<","<<neighbour.second<<"} ";
//                 }
//                 cout<<"}"<<endl;
//                 cout<<endl;
//             }
//         }
// };

// graph code that handles also generalise node datatype
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
            cout<<endl;
            printgraph();
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
};

int main(){
    // graph g;
    // directed edge graph 
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    // g.addEdge(1,3,1);
    // undirected edge graph
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(2,3,0);
    // g.addEdge(1,3,0);

    // graph code that handles also weighted graphs
    // graph g;
    // directed weighted graph 
    // g.addEdge(0,1,5,1);
    // g.addEdge(1,2,10,1);
    // g.addEdge(2,3,15,1);
    // g.addEdge(1,3,20,1);
    // undirected weighted graph
    // g.addEdge(0,1,5,0);
    // g.addEdge(1,2,10,0);
    // g.addEdge(2,3,15,0);
    // g.addEdge(1,3,20,0);

    // graph code that handles also generalise node datatype by using template typename
    graph<char> g;
    // directed weighted graph 
    // g.addEdge('a','b',5,1);
    // g.addEdge('b','c',10,1);
    // g.addEdge('c','a',15,1);
    // g.addEdge('a','c',20,1);
    // undirected weighted graph
    g.addEdge('a','b',5,0);
    g.addEdge('b','c',10,0);
    g.addEdge('c','a',15,0);
    g.addEdge('a','c',20,0);

    return 0;
}