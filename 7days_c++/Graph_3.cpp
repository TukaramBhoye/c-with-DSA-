// 48:NB2:103: Graph part III: 

/*Q.1 : Topological Sorting:
- Topological is an ordering of the vertices in a directed acyclic graph(DAG) 
  such that every directed graph edge u--> v, vertex u comes before v 
  in the ordering : 
*/
/*
#include <iostream> 
#include <vector> 
#include <queue> 
#include <list> 
#include <stack> 
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

    void addEdge(int u, int v){
        l[u].push_back(v); 
        if(isUndir){
            l[u].push_back(u); 
        }
    }
    void topoHelper(int src, vector<bool> &vis, stack<int> &s){
        vis[src] = true; 

        list<int> neighbors = l[src]; 

        for(int v : neighbors){
            if(!vis[v]){
                topoHelper(v, vis, s);
            }
        }
        s.push(src); 
    }
    void topoSort(){
        vector<bool> vis(V, false); 
        stack<int> s; 

        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoHelper(i, vis, s); 
            }
        }

    // print Topological Order: 
    while(s.size()){
        cout << s.top() << " "; 
        s.pop(); 
    }
    cout << endl; 
    }
};

int main (){
    // DAG 
    Graph graph(6, false); 
    graph.addEdge(2, 3); 
    graph.addEdge(3, 1);

    graph.addEdge(4, 0); 
    graph.addEdge(4, 1); 

    graph.addEdge(5, 0); 
    graph.addEdge(5, 2); 

    graph. topoSort(); 
    return 0; 
}

//* OP= in stack : 5 4 2 3 1 0 
*/ 

// Q.3: request of mam: 
// Q.NO.leet Code:207: schedule I 
//first to all: check On leat Code there are several question which are topological sorting 
/*
 leet Q.207: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
 You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you 
 must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

*/

/*
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &rec, vector<vector<int>>& graph) {
        vis[src] = true;
        rec[src] = true;  // This should be here to mark it as part of the current recursion stack

        for (const auto& edge : graph) {
            int u = edge[0];
            int v = edge[1];

            if (u == src) {
                if (!vis[v]) {
                    if (isCycle(v, vis, rec, graph)) {
                        return true;
                    }
                } else if (rec[v]) {
                    return true;
                }
            }
        }

        rec[src] = false;  // Mark it as not part of the current recursion stack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int V = numCourses;
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                if (isCycle(i, vis, rec, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    //* Example graph: [v, u] means u -> v
    vector<vector<int>> graph = {{1, 0}, {0, 1}};
    int numCourses = 2;

    if (sol.canFinish(numCourses, graph)) {
        cout << "No cycle detected, can finish all courses." << endl;
    } else {
        cout << "Cycle detected, cannot finish all courses." << endl;
    }

    return 0;
}
*/ 


//Q.4:leet code:210: : Schedule II: 
/*There are a total of numCourses courses you have to take, labeled from 
0 to numCourses - 1. You are given an array prerequisites where 
prerequisites[i] = [ai, bi] indicates that you must take course bi first if 
you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to 
first take course 1.
Return the ordering of courses you should take to finish all courses. If 
there are many valid answers, return any of them. If it is impossible to 
finish all courses, return an empty array.*/
/*
class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool>&rec, vector<vector<int>>& graph){
        vis[src] = true; 
        rec[src] = true; 

        for(int i=0; i<graph.size(); i++){
            int u = graph[i][1]; 
            int v = graph[i][0]; 

            if(u == src){
                if(!vis[v]){
                    if(isCycle(v, vis, rec, graph)){
                        return true; 
                    }
                }else{
                    if(rec[v]){
                        return true; 
                    }
                }
            }
        }
        rec[src] = false;
        return false; 
    }

    void topoSort(int src, vector<bool>&vis, stack<int>&s, vector<vector<int>>&graph){
        vis[src] = true; 

        for(int i=0; i<graph.size(); i++){
            int u = graph[i][1]; 
            int v = graph[i][0]; 
            if(u == src){
                if(!vis[v]){
                    topoSort(v, vis, s, graph); 
                }
            }
        }

        s.push(src); 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        int V =  numCourses; // [v, u] v <----- u
        vector <bool> vis(V, false);
        vector <bool> rec(V, false);    
        vector<int> ans; 

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i, vis, rec, graph)){
                    return ans; 
                }
            }
        } 
        //* topoLogical Sorting
        vector<bool> vis2(V, false); 
        stack<int> s; 

        for(int i=0; i<V; i++){
            if(!vis2[i]){
                topoSort(i, vis2, s, graph); 
            }
        }

        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
*/ 


/* Q.5: Topological Sorting: Using BFS (Kahan's Algorithm) 
   -  in Kahan's we Use inDegree:incoming Edges toward curr Node &  OutDegree : OutGoing edges From Curr Node.
   - In This Code We Use InDegree : 
*/ 
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (isUndir) {
            l[v].push_back(u);  
        }
    }

    void calcIndegree(vector<int>& indeg) {
        for (int u = 0; u < V; u++) {
            for (int v : l[u]) {
                indeg[v]++;
            }
        }
    }

    void topoSort2() { // Kahn's Algorithm
        vector<int> indeg(V, 0);
        calcIndegree(indeg);
        queue<int> q;

        // Push nodes with 0 indegree
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (q.size() > 0) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int v : l[curr]) {
                indeg[v]--;
                if (indeg[v] == 0) { // No pending dependencies
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph(6, false);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topoSort2();
    return 0;
}
