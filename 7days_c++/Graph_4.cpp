// 49:NB2:Graph-4:
// 1:Dijkstra Algorithm : shortest path from src to all weighted graph :

// TC ((V + E)*Log V): bcz of PQ
/*
#include<iostream>
#include<vector>
#include<queue>
#include <climits>
using namespace std;

class Edge {
public:
    int V;
    int wt;

    Edge(int V, int wt) {
        this->V = V;
        this->wt = wt;
    }
};

void dijkstra(int src, vector<vector<Edge>> graph, int V) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        vector<Edge> edges = graph[u];
        for(Edge e : edges) { // e.V, e.wt
            if(dist[e.V] > dist[u] + e.wt) {
                dist[e.V] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.V], e.V));
            }
        }
    }

    for(int d: dist) {
        cout << d << " ";
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));
    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(5, 5));

    dijkstra(0, graph, V);
    return 0;
}
*/

// 3: Bellman Ford Algorithm:
/*shortest Path from from src to all verticess for weighted graph with
negative wt
- Perform this operation V-1 times:
- doesn't worked with negative overall negative work : bcz loop iterate infinite time
*/
/*
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Edge{
  public:
  int v;
  int wt;
  Edge(int v, int wt){
      this->v = v;
      this->wt = wt;
  }
};

void bellmanFord(vector<vector<Edge>> graph,  int V, int src){ // O(V.E)
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;

  for(int i=0; i<V-1; i++){
      for(int u=0; u<V; u++){
          for(Edge e: graph[u]){
              if(dist[e.v] > dist[u] + e.wt){
                  dist[e.v] = dist[u] + e.wt;
              }
          }
      }
  }

  for(int i=0; i<V; i++){
      cout << dist[i] << " ";
  }
  cout << endl;
}

int main(){
  int V = 5;
  vector<vector<Edge>> graph(V);

  graph[0].push_back(Edge(1, 2));
  graph[0].push_back(Edge(2, 4));

  graph[1].push_back(Edge(2, -4));

  graph[2].push_back(Edge(3, 2));

  graph[3].push_back(Edge(4, 4));

  graph[4].push_back(Edge(1, -1));

  bellmanFord(graph, V, 0);
  return 0;
}*/

/*Q.4: Minimum Spanning Tree (MST)
MST is a subset of the edges of a connected, edge-wieghted undirected graph
that connects all the vertices together, without any cycles and with the
minimum possible total edge weight.
*//*
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt)
    {
        l[u].push_back(make_pair(v, wt));
        if (isUndir)
            l[v].push_back(make_pair(u, wt));
    }

    void primsAlgo(int src)
    {
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //(wt, u) -> minHeap
        vector<bool> mst(V, false);

        pq.push(make_pair(0, src));
        int ans = 0;

        while (pq.size() > 0)
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (!mst[u])
            {
                mst[u] = true;
                ans += wt;

                list<pair<int, int>> neighbors = l[u];
                for (pair<int, int> n : neighbors)
                {
                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt, v));
                }
            }
        }
        cout << "final cost of MST: " << ans << endl; 
    }
};

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);

    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.primsAlgo(0); 
    return 0;
}*/ 


/*Question 5: leetCode Question no: 1584
- You are given an array points representing integer coordinates of some points
  on a 2D-plane, where points[i] = [Xi, Yi]. 

  The cost of connecting two points [Xi, Yi] and  [Xj, Yj] is the manhattan 
  distance betweem them:  [Xi, Xj] +  [Yi, Yj]. where 
  val denotes the absolute value of val. 

  Return the minimum cost to make all points connected. All points are 
  connected if there is exactly one somple path between any two points.
  
*/ 

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // wt, u

        int src = 0;
        vector<bool> mst(V, false);
        pq.push(make_pair(0, src));
        int minCost = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if (!mst[u]) {
                mst[u] = true;
                minCost += cost;

                for (int v = 0; v < V; v++) {
                    if (u != v) { // src not equal to destination
                        int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                        pq.push(make_pair(wt, v));
                    }
                }
            }
        }
        return minCost;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};
    cout << "Minimum Cost to Connect Points: " << solution.minCostConnectPoints(points) << endl;
    return 0;
}
