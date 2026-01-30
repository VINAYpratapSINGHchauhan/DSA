#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T, int>>> nodeToAdjList;
    void addEdge(T u, T v, int wt, bool direction)
    {
        // if direction=0 -> unidrected graph ( u to v & v to u BOTH DIRECTION are taken )
        // if direction=1 -> directed graph ( from u to v direction )
        if (direction == 1)
        {
            // u se v ki trf ek edge hai toh u ki adjanceny list mei v ko add krdo
            nodeToAdjList[u].push_back({v, wt});
        }
        else
        {
            // u se v and v se u dono trf ki hme edge lgani hai
            nodeToAdjList[u].push_back({v, wt});
            nodeToAdjList[v].push_back({u, wt});
        }
        // cout<<endl;
        // printgraph();
        return;
    }
    void printgraph()
    {
        for (auto &e : nodeToAdjList)
        {
            cout << e.first << " -> {";
            for (auto &neighbour : e.second)
            {
                cout << " {" << neighbour.first << "," << neighbour.second << "} ";
            }
            cout << "}" << endl;
            cout << endl;
        }
    }
    void bfsTraversel(T source, unordered_map<T, bool> &visited)
    {
        queue<T> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            T front = q.front();
            q.pop();
            cout << front << " ";
            for (auto &nbrPair : nodeToAdjList[front])
            {
                T nbr = nbrPair.first;
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return;
    }
    void dfsTraversel(T source, unordered_map<T, bool> &visited)
    {
        visited[source] = true;
        cout << source << " ";
        for (auto &nbrPair : nodeToAdjList[source])
        {
            T nbr = nbrPair.first;
            if (!visited[nbr])
            {
                dfsTraversel(nbr, visited);
            }
        }
        return;
    }
    bool checkCycleUndirectedBFS(T sourceNode){
        T src=sourceNode;
        queue<T>q;
        unordered_map<T,bool>visited;
        unordered_map<T,T>parent;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty()){
            T frontNode=q.front();
            q.pop();
            for(auto &nbr:nodeToAdjList[frontNode]){
                T nbrval=nbr.first;
                if(!visited[nbrval]){
                    visited[nbrval]=true;
                    parent[nbrval]=frontNode;
                    q.push(nbrval);
                }
                else if(visited[nbrval]&&nbrval!=parent[frontNode]){
                    cout<<frontNode<<nbrval<<parent[nbrval];
                    return true;
                }
            }
        }
        return false;
    }
    /* check cycle in undirected graph through DFS
        check cylce in direted BFS
        check cycle in directed DFS
        */ 
    // - these all are done in gfg question and in the notebook
};

int main()
{
    graph<int> g;
    // undirected weighted graph
    g.addEdge(0, 1, 5, 0);
    g.addEdge(1, 2, 10, 0);
    g.addEdge(2, 3, 15, 0);
    g.addEdge(3, 4, 20, 0);
    bool iscycle=g.checkCycleUndirectedBFS(0);
    if(iscycle)cout<<"Cycle Present "<<endl;
    else cout<<"Cycle Absent "<<endl;
    return 0;
}