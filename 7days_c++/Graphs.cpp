// 46:NB2:89: Graphs

/*//*1: Graphs : (Important Chapter):
- Graph is Network of Nodes.
- in graph no parent and child only neighbours :
- graph is all about neighbours and Connections :
- single node know as "vertex" and multiple nodes "verteces"
  and and connections binded within the edges(N1--------N2).
*/
/*//*2: edges: i) Uni-Directional - A<-------->B
            ii) Un Directional - A-------B
            iii) Bi-directional - a) A ---------->B
                                  b) A <---------B
            iv) wighted(supposed as root toll tax of Highway(tree root to end which values are available on each edge))
            v) unweighted : tree map without val's
            vi) disjoint/disconnected: some cases the edges are not connected but that also known as single graph
*/
/*//*3: List in C++ STL : #include <list>
    i: doubliy link list :
    ii: push_front(); push_back()
    iii:  pop_front(); pop_back();
    iv: front(); back(); size();

4: STORINT A graph:
 i : queue ---> vector & stack
 ii: graph ---> matrix,  List, class Edge using we can Implement:

5: draw graph using two ways :
     i: Adjacency List
     ii: Adjacency matrix :
     iii: Edge List : (0)
                        \    (2)
                       e1\  /e2 \e4
                         (1)----(3)
                             e3

*/

/*
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int>* l; // store list of integer ka starting point :

    public :
    Graph(int V){this->V = V;
    this->V  = V;
    l = new list<int> [V];
    }

    // add edge :

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for(int u=0; u<V; u++){
            list<int>neighbors = l[u];
            cout << u << " : ";
            for(int v : neighbors){
                 cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    graph.print();
    return 0;
}
*/
/*

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* l; // List of pairs to store neighbors and weights

public:
    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    // Add edge with weight
    void addEdge(int u, int v, int weight) {
        l[u].push_back(make_pair(v, weight));
        l[v].push_back(make_pair(u, weight)); // For undirected graph
    }

    void print() {
        for (int u = 0; u < V; u++) {
            list<pair<int, int>> neighbors = l[u];
            cout << u << " : ";
            for (auto neighbor : neighbors) {
                cout << "[" << neighbor.first << ", " << neighbor.second << "] ";
            }
            cout << endl;
        }
    }
};


int main() {
    Graph graph(5);

    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 2);

    graph.print();
    return 0;
}
*/

// Q.6:  Graph Traversal : 
#include <iostream>
#include <vector>
#include <list>
#include <queue> 
using namespace std;

class Graph
{
    int V;
    list<int> *l; // store list of integer ka starting point :

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    // add edge :

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for(int u=0; u<V; u++){ 
            list<int> neighbors = l[u]; 
            cout << u << " : "; 
            for(int v: neighbors){
                cout << v << " "; 
            }
            cout << endl; 
        }
    }

    void bfs(){  // O(V * E)
        queue<int> q; 
        vector<bool> vis(V, false); // (size_V, intialize with_false)
        q.push(0); 
        vis[0] = true; 

        while(q.size() > 0){
            int u = q.front(); //curr vertex
            q.pop(); 
            cout << u << " "; 

            list<int>neighbors = l[u];  // u -se--तक --- v 
            for(int v : neighbors){
                if(!vis[v]){//  if v नोट विजिट 
                    vis[v] = true; 
                    q.push(v); 
                }
            }
        }

        cout << endl; 
    }

//Q.6: Depth First Search(DFS) 
    void dfs(int u, vector<bool> &vis){
        vis[u] = true; 
        cout << u << " "; 

        list<int> neighbors = l[u]; 
        for(int v : neighbors){
            if(!vis[v]){
                dfs(v, vis);
            }
        }
    }


   bool pathHelper(int src, int dest, vector<bool> &vis) {
        if (src == dest) {
            return true;
        }

        vis[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors) {
            if (!vis[v]) {
                if (pathHelper(v, dest, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src, int dest){ //  O(V + E)
        vector<bool> vis(V, false);
        return pathHelper(src, dest, vis);
    }
};

int main (){
    Graph graph(7); 

    graph.addEdge(0, 1) ;
    graph.addEdge(0, 2) ;
    graph.addEdge(1, 3) ;
    graph.addEdge(2, 4) ;
    graph.addEdge(3, 4) ;
    graph.addEdge(3, 5) ;
    graph.addEdge(4, 5) ;
    graph.addEdge(5, 6) ;
 

    // vector<bool> vis(7, false); 
   cout << graph.hasPath(0, 5) << endl; 
   return 0; 
}  


