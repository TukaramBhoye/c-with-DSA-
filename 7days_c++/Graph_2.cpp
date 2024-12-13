// 47:NB:95: Graphs Part 2:
// 1  : Disconnected Graphs
/*
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *l; // adjacency list

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    //* Add edge
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    //* Print adjacency list
    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << " : ";
            for (int v : l[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    //* BFS
    void bfsHelper(int st, vector<bool> &vis) {
        queue<int> q;
        q.push(st);
        vis[st] = true; // Corrected this line

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int neigh : l[curr]) {
                if (!vis[neigh]) {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout << endl;
    }

    void bfs() {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bfsHelper(i, vis);
            }
        }
    }

    // DFS
    void dfsHelper(int u, vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;

        for (int v : l[u]) {
            if (!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsHelper(i, vis);
                cout << endl;
            }
        }
    }

    // Path Finding
    bool pathHelper(int src, int dest, vector<bool> &vis) {
        if (src == dest) {
            return true;
        }

        vis[src] = true;

        for (int v : l[src]) {
            if (!vis[v]) {
                if (pathHelper(v, dest, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src, int dest) {
        vector<bool> vis(V, false);
        return pathHelper(src, dest, vis);
    }
};

int main() {
    Graph graph(10); // Increase the number of vertices to accommodate all nodes (0-9)

    // Component 1
    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 3);
    graph.addEdge(4, 9);
    graph.addEdge(3, 7);
    graph.addEdge(3, 8);

    // Component 2
    graph.addEdge(2, 0);
    graph.addEdge(2, 5);
    graph.addEdge(0, 5);

    cout << "Adjacency List:" << endl;
    graph.print();

    cout << "BFS Traversal:" << endl;
    graph.bfs();

    cout << "DFS Traversal:" << endl;
    graph.dfs();

    return 0;
}
*/

// 3:  Cycle Detection : Undirected Graph - DFS
/*
#include <vector>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Graph {
    int V ;
    list <int> *l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){ //u--v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0; u<V;  u++){
            list<int>neighbors = l[u];
            cout << u << " : ";
            for(int v : neighbors){
                cout << v << " ";
            }

            cout << endl ;
        }
    }

    bool undirCycleHelper(int src, int par, vector<bool>&vis){
          vis[src] = true;
          list<int> neighbors = l[src];

          for(int v : neighbors){
            if(!vis[v]){
                if(undirCycleHelper(v, src, vis)){
                    return true;
                }
            }else{
                if(v != par){
                    return true;
                }
            }
          }
        return false;
    }
    bool isCycleUndir(){
        vector<bool> vis(V, false);
        return undirCycleHelper(0,  -1, vis);
    }
};


int main (){
    int V = 5;
    Graph graph(V);

    // undirected graph
    graph.addEdge(0, 1);
    // graph.addEdge(0, 2); // detect cycle here:
    graph.addEdge(0, 3);

    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

   cout <<  graph.isCycleUndir() << endl;
    return 0;
}*/

// 5: Cycle Detection with -> Directed graph :
/*
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){ // u---->v
        l[u].push_back(v);
        if (isUndir){
            l[v].push_back(u);
        }
    }

    void print(){
        for (int u = 0; u < V; u++){
            list<int> neighbors = l[u];
            cout << u << " : ";
            for (int v : neighbors)
            {
                cout << v << " ";
            }

            cout << endl;
        }
    }

    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool>&recPath){
            vis[src] = true;
            recPath[src] = true; 
            list<int> neighbors = l[src]; 

            for(int v : neighbors){
                if(!vis[v]){
                    if(dirCycleHelper(v, vis, recPath)){
                        return true; 
                    }
                }else{
                    if(recPath[v]){
                        return true; 
                    }
                }
            }
            recPath[src] = false; 

            return false; 
    }

    bool isCycleDir(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false); 

        for (int i = 0; i < V; i++){
            if (!vis[i]){
                if(dirCycleHelper(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false; 
    }
};
int main()
{
    // directed graph :
    Graph graph(4, false);
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    cout << graph.isCycleDir() << endl; 
    return 0;
}
*/

/*6: Cycle Detection : 
Directed graph - DFS : Dry Run

0----->1<------2------>3------4---->(coonect edge with 2) */ 

/*Bipartite Graph : No edge connects vertices of same set: 
Bia(2) Partite(Parts). 

*//*

#include <iostream>
#include <vector>
#include <list>
#include <queue> 
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){ // Add edge u --> v
        l[u].push_back(v);
        if (isUndir){
            l[v].push_back(u); // For undirected graph, add edge v --> u
        }
    }

    void print(){
        for (int u = 0; u < V; u++){
            list<int> neighbors = l[u];
            cout << u << " : ";
            for (int v : neighbors)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool isPartite(){
        queue<int> q; 
    // vector<bool> vis(V, false); // also work done using one vec  
        vector<int> color (V, -1); 

        q.push(0); 
        color[0] = 0; 

        while(!q.empty()){
            int curr = q.front(); 
            q.pop(); 
            list<int> neighbors = l[curr]; 

            for(int v : neighbors){
            // if(!vis[v])
                if(color[v] == -1){ // If unvisited
                  // vis[v] = true; 
                color[v] = !color[curr];  
                    q.push(v); 
                } else if(color[v] == color[curr]){
                    return false; // If adjacent nodes have the same color, graph is not bipartite
                }
            }
        }
        return true; 
    }
}; 

int main(){
    Graph graph(5); // Adjusted number of vertices
    graph.addEdge(0, 1); 
    graph.addEdge(0, 2); 
    graph.addEdge(1, 3); 
    graph.addEdge(3, 4); 
    graph.addEdge(4, 2);

    graph.print(); // Print graph edges
    cout << "Is the graph bipartite? " << (graph.isPartite() ? "Yes" : "No") << endl; 

    return 0; 
}

*/ 
// 10: All Path problem. 
// print all paths fromm src to dest for a directed graph 

#include <iostream>
#include <vector>
#include <list>
#include <queue> 
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){ // Add edge u --> v
        l[u].push_back(v);
        if (isUndir){
            l[v].push_back(u); // For undirected graph, add edge v --> u
        }
    }

    void print(){
        for (int u = 0; u < V; u++){
            list<int> neighbors = l[u];
            cout << u << " : ";
            for (int v : neighbors)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void pathHelper(int src, int dest, vector<bool> &vis, string &path){
        if(src == dest){
            cout << path << dest << endl; 
            return ; 
        }

        vis[src] = true; // string will consider ascii val : 
        path += to_string(src);  // त्यामुळे src convert in string
        list<int> neighbors = l[src]; 

        for(int v : neighbors){
            if(vis[v]){
                pathHelper(v, dest, vis, path); 
            }
        }

        path = path.substr(0, path.size()-1); 
        vis[src] = false; 
    }
    void printAllPaths(int src, int dest){
        vector<bool> vis(V, false); 
        string path = ""; 
        pathHelper(src, dest, vis, path);

     }
};

int main(){
    Graph graph(6, false); 

    graph.addEdge(0, 3);
    graph.addEdge(2, 3);    
    graph.addEdge(3, 1);    
    graph.addEdge(4, 0);    
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.printAllPaths(5, 1);
    return 0 ;
  
}