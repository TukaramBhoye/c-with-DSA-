// 50:NB:112: Graph Part 5:

/*1: There are n cities connected by some number of flights. You are given
an array flights where flights[i] = [fromi, toi, pricei] indicates that
there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest
price from src to dst with at most k stops. If there is no such route,
return -1. */
/*
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Solution {
public:
class info{
    public:
    int u;
    int cost;
    int stops; // src to u

    info(int u, int cost, int stops){
        this-> u = u;
        this->cost = cost;
        this->stops = stops;
    }
};
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<info> q;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;

        q.push(info(src, 0, -1));

        while(q.size() > 0){
            info curr = q.front();
            q.pop();

            for(int i=0; i<flights.size(); i++){
                if(flights[i][0] == curr.u){
                    int v = flights[i][1];
                    int wt = flights[i][2];

                    if(dist[v] > curr.cost + wt && curr.stops+1 <= k){
                        dist[v] = curr.cost + wt;
                        q.push(info(v, dist[v], curr.stops+1));
                    }
                }
            }
        }
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};

int main() {
    Solution solution;
    // Number of vertices (airports)
    int V = 4;
    vector<vector<int>> flights = {
        {0, 1, 100}, // Flight from 0 to 1 with cost 100
        {1, 2, 100}, // Flight from 1 to 2 with cost 100
        {2, 3, 100},
        {0, 2, 500},
        {1, 3, 600}
    };

    // Source and destination
    int src = 0;
    int dst = 3;
    int k = 1; // Maximum number of stops

    // Find the cheapest price
    int result = solution.findCheapestPrice(V, flights, src, dst, k);

    // Print the result
    if (result != -1) {
        cout << "The cheapest price from " << src << " to " << dst <<
        " with at most " << k << " stops is " << result << endl;
    } else {
        cout << "route from " << src << " to " << dst << " within "
        << k << " stops." << endl;
    }

    return 0;
}
*/

// Q.2: DisJoint Set DS: Kruskal Algorithm:
/*
#include <iostream>
#include <vector>
using namespace std;

class DisJoint{
    public:
    int n;
    vector<int> par;
    vector<int> rank;

    DisJoint(int n){
        this->n = n;

        for (int i = 0; i < n; i++){
           par.push_back(i);
           rank.push_back(0);
        }
    }

    int find(int x){
        if (par[x] == x){
            return x;
        }

        return find(par[x]);
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);
        if (rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB]){
            par[parB] = parA;
        }
        else{
            par[parA] = parB;
        }
    }
// Additional for print info
    void getInfo(){
        for(int i=0; i<n; i++){
            cout << i << ": "<< par[i] << " , " << rank[i] << endl;
        }
    }
};
int main()
{
    DisJoint dj(6);
    dj.unionByRank(0, 2);

    cout << dj.find(2) << endl;

    dj.unionByRank(1, 3);
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);
    cout << dj.find(2) << endl;
    dj.unionByRank(0, 4);

    dj.getInfo();
    return 0;
}
*/

// Q.3: kruskal algorithm : greedy approach for mst
//  i: sort all the edges  ii : smallest wt -> Cycle :
/*
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Edge{
public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph{
public:
    vector<Edge> edges;
    int V;
    vector<int> par; 
    vector<int> rank; 

    Graph(int V){
        this->V = V;

        for (int i = 0; i < V; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    
    int find(int x){
        if(par[x] == x){
            return x; 
        }

        return par[x] = find(par[x]);
    }

    void unionByRanks(int u, int v){
        int parU = find(u); 
        int parV = find(v); 

        if(rank[parU] == rank[parV]){
            par[parV] = parU; 
            rank[parU]++; 
        }else if(rank[parU] > rank[parV]){
            par[parV] = parU; 
        }else{
            par[parU] = parV; 
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u, v, wt));
    }


    void kruskals(){
        sort(edges.begin(), edges.end(), [] (Edge &a, Edge &b) {return a.wt < b.wt; });
        int minCost = 0; 
        int count = 0; 
        for(int i=0; i<edges.size() && count < V-1; i++){
            Edge e = edges[i]; 
            int parU = find(e.u); 
            int parV = find(e.v); 

            if(parU != parV){
                unionByRanks(parU, parV); 
                minCost += e.wt; 
                count++; 
            }
        }

        cout << "Min Cost = " << minCost << endl; 
    }

}; 

int main(){
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);


  graph.kruskals();
    return 0;
}*/ 


// Q.4: Flood fill algorithm : 
/*LeetCode : 733:  
- An image is represented by an m x n integer grid image where image[i][j] 
 represents the pixel value of the image.

- You are also given three integers sr, sc, and color. You should perform a 
flood fill on the image starting from the pixel image[sr][sc].

- To perform a flood fill, consider the starting pixel, plus any pixels connected 
4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color), 
and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill. 

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<int>>& image, vector<vector<bool>>& vis, int newColor, int oldColor) {
        vis[row][col] = true;  
        image[row][col] = newColor; 

        // up 
        if (row - 1 >= 0 && !vis[row - 1][col] && image[row - 1][col] == oldColor) {
            dfs(row - 1, col, n, m, image, vis, newColor, oldColor);
        }
        // down
        if (row + 1 < n && !vis[row + 1][col] && image[row + 1][col] == oldColor) {
            dfs(row + 1, col, n, m, image, vis, newColor, oldColor); 
        }
        // left
        if (col - 1 >= 0 && !vis[row][col - 1] && image[row][col - 1] == oldColor) {
            dfs(row, col - 1, n, m, image, vis, newColor, oldColor); 
        }
        // right
        if (col + 1 < m && !vis[row][col + 1] && image[row][col + 1] == oldColor) {
            dfs(row, col + 1, n, m, image, vis, newColor, oldColor); 
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(); 
        int m = image[0].size(); 
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dfs(sr, sc, n, m, image, vis, newColor, image[sr][sc]);
        return image;  
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    for (const auto& row : result) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}

