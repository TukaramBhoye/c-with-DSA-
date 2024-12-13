/*You're given a graph initially shaped like a tree with 𝑛 nodes labeled
from 1 to 𝑛. However, one extra edge has been added to this graph. This
extra edge connects two different nodes from 1 to 𝑛, and it's not a duplicate
of any existing edge.

Your task is to find and return this extra edge that, if removed, would
make the graph a tree again. If there are multiple answers (multiple edges
that could be removed to turn the graph into a tree), you should return the
one that appears last in the input list.

** To solve this problem, you need to:
- Identify which edge, when removed, disconnects the graph into a tree
  (a connected graph with no cycles).
- Since the input guarantees that exactly one edge addition has made the
  graph non-tree, finding this edge is crucial. */
 
/* 
// 2nd way to solve similar approach but syntax change

#include <iostream>
#include <vector>

using namespace std;

class Edge
{
public:
    int u;
    int v;

    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
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
        par.resize(V + 1);
        rank.resize(V + 1, 0);
        for (int i = 0; i <= V; i++){
            par[i] = i;
        }
    }

    int find(int x){
        if (par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unionByRank(int u, int v){
        int parU = find(u); 
        int parV = find(v);

        if(parU != parV){
            if(rank[parU] > rank[parV]){
                par[parU] = parV; 
            }else if(rank[parU] < rank[parV]){
                par[parU] = parV; 
            }else{
                par[parV] = parU; 
                rank[parU]++; 
            }
        }
    }

    void addEdge(int u, int v){
        edges.push_back(Edge(u, v)); 
    }

    vector<int> findConnection(){
        for(const auto & edge: edges){
            int u = edge.u; 
            int v = edge.v; 

            if(find(u) == find(v)){
                return {u, v}; 
            }else{
                unionByRank(u, v); 
            }
        }
        return {};
    }
};

int main (){
Graph graph(6);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(5, 6);
    graph.addEdge(4, 6);

    vector<int> result = graph.findConnection();
    if (!result.empty()) {
        cout << "Redundant Edge: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No redundant edge found." << endl;
    }

    return 0;
}*/ 


/*Q.2: You are given an m x n grid where each cell can have one of three values:

- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a 
rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has 
a fresh orange. If this is impossible, return -1.
*/
 /*
#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 

class Solution{ 
    public:
    int orangeRotating(vector<vector<int>> & grid){
        int rows = grid.size(); 
        int cols = grid[0].size(); 
        queue<pair<int, int>> q; 
        int freshOrange = 0; 

        for(int i=0; i < rows; ++i){
            for(int j=0; j < cols; ++j){
                if(grid[i][j] == 2) {
                    q.push(make_pair(i, j)); 
                }else if(grid[i][j] == 1){
                    freshOrange++; 
                }
            }
        }

        // Directions for 4-directional movement 
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        int minutes = 0; 

        // bfs 
        while(!q.empty() && freshOrange > 0){
            int qSize  = q.size(); 
            bool rottenInThisMinute = false; // 

            for(int i=0; i<qSize; ++i){
                pair<int, int> current = q.front(); 
                q.pop(); 

                int x = current.first; 
                int y = current.second; 

                for(const pair<int, int> & direction : directions){
                    int dx = direction.first; 
                    int dy = direction.second; 
                    int nx = x + dx; 
                    int ny = y + dy; 

                    if(nx >= 0 && ny >=0 && nx < rows && ny < cols && grid[nx][ny] == 1){
                        grid[nx][ny] = 2; 
                        q.push(make_pair(nx, ny)); 
                        freshOrange--;
                        rottenInThisMinute = true;
                    }
                }
            }
            if(rottenInThisMinute){
                minutes++;
            }
        }

        return freshOrange == 0 ? minutes : -1;
    }
};

int main() {
    Solution sol; 
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = sol.orangeRotating(grid); 
    cout << "Minimut min: " << result << endl; 
    return 0; 
}
*/ 
/*Given a 2D grid consisting of 0s (water) and 1s (land), your task is to 
find the maximum area of an island in the grid. An island is defined as a 
group of connected 1s (land cells) connected vertically or horizontally. 
You may assume all four edges of the grid are surrounded by water.

Write a function int maxAreaOfIsland(vector<vector<int>>& grid) that takes 
a 2D grid and returns the size of the largest island.
/*

#include <iostream>
#include <vector>
#include <functional> // Required for std::function

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        // Function to perform DFS
        function<int(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0) {
                return 0;
            }
            grid[x][y] = 0; // Mark as visited
            int area = 1; // Current cell
            area += dfs(x - 1, y);
            area += dfs(x + 1, y);
            area += dfs(x, y - 1);
            area += dfs(x, y + 1);
            return area;
        };

        // Main logic
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    int area = dfs(i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 1}
    };

    int result = sol.maxAreaOfIsland(grid);
    cout << "Maximum area of island: " << result << endl;
    return 0;
}
*/ 

/* Question 4: Word Ladder : 
- A transformation sequence from word beginWord to word endWord using a dictionary
wordList is a sequence of words beginWord -> s1 -> s2-> .... -> sk such that. 
- Every adjacent pair of words differs by a single letter. 
 Everu si for 1 <= i <= k is in wordList. Note that beginWord does not need to 
 be in wordList. 
 sk == endWord 
 -Given two wordsm begin Word and endWord, and a dictionary wordList, return the number of
 words in the shortest transformation sequence from beginWord to endWord, or 0 
 if no such sequence exists. 
*/ 
/*
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0; // End word not in word list
        }

        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return level;
                }

                for (int j = 0; j < word.size(); ++j) {
                    char originalChar = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        word[j] = c;
                        if (wordSet.find(word) != wordSet.end()) {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }
                    word[j] = originalChar; // Restore original character
                }
            }
            ++level;
        }
        return 0; // No path found
    }
};

int main(){
    Solution sol; 
    vector<string> wordList = {"hot", "dot", "dog", "cog"}; 

    int result = sol.ladderLength("hit", "cog", wordList);
    cout << "Length of shortes transformation sequence: "<< result << endl ;
    return 0; 
}
*/ 

/*Question 5: Redundant Connection II 
- In this problem, a rooted tree is a directed graph such that, there is exactly 
 one node(the root) for, which all other nodes are descendants of this node, 
 plus every node has exactly one parent, except for the root node which has no
 parents.

 - The given input is a directed graph that started as a rooted tree with n 
 nodes (with distinct values from 1 to n), with one additional dierected edge 
 added. The added edge has two different vertices chosen from 1 to n. and was
 not an edge that already existed. 

- The resulting graph is given as a 2D-array of edges. Each element of edges 
is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, 
where ui is a parent of child vi. 

- Return an edge that can be removed so that the resulting graph is a rooted tree
of n nodes. if there are multiple answers. return the answer that occur last 
in the given 2D-array. 
*//*
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> canA, canB;

        // Step 1: Check whether there is a node with two parents.
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                canA = {parent[v], v};
                canB = {u, v};
                edges[i][1] = 0; // Temporarily remove this edge
            }
        }

        // Step 2: Use union-find to detect a cycle.
        for (int i = 1; i <= n; ++i) parent[i] = i;
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][1] == 0) continue; // Skip the temporarily removed edge

            int u = edges[i][0];
            int v = edges[i][1];
            int pu = find(parent, u);
            if (pu == v) {
                if (canA.empty()) return {u, v};
                return canA;
            }
            parent[v] = pu;
        }

        return canB;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> result = sol.findRedundantDirectedConnection(edges);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
*/ 


/*Question 6: Couples Holding Hands: 
- There are n couples sitting in 2n seats arranged in a row and want to 
hold hands. 
- The people and seats are represented by an integer array row where row[i] 
  is the ID of the person sitting in the ith seat. The couples are numbered 
  in order, the first couple being (0, 1), the second couple being (2, 3), and 
  so on with the last couple being (2n - 2, 2n - 1).

- Return the minimum number of swaps so that every couple is sitting side by 
  side. A swap consists of choosing any two people, then they stand up and 
  switch seats.

*/ 
/*
#include <iostream>  
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        unordered_map<int, int> seatIndex;

        // Initial positions
        for (int i = 0; i < row.size(); ++i) {
            seatIndex[row[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < row.size(); i += 2) {
            int firstPerson = row[i];
            int secondPerson = firstPerson ^ 1; // Partner ID

            if (row[i + 1] != secondPerson) {
                swaps++;

                int partnerIndex = seatIndex[secondPerson];

                // Update seatIndex
                seatIndex[row[i + 1]] = partnerIndex;

                // Swap partners
                swap(row[i + 1], row[partnerIndex]);
            }
        }

        return swaps;
    }
};

int main() {
    Solution sol;
    vector<int> row = {0, 2, 1, 3};
    int result = sol.minSwapsCouples(row);
    cout << "Minimum swaps needed: " << result << endl;
    return 0;
}
*/ 

/*7: Course Schedule |||
    There are n different online numbered from 1 to n. You are given an array courses 
    where coursesk[i] = [duration_i, lastDay_i] indicate that the ith course should
    be taken continously for duration days and must be finished before or on lastDay_i. 

- You will start on the 1st day and you cannot take two or more courses 
  simultaneously 
 */
/*
#include <iostream> 
#include <vector> 
#include <queue> 
#include <algorithm>
using namespace std; 

class Solution{
    public: 
    int scheduleCourse(vector<vector<int>> & courses){
        // sort courses by end day 

        sort(courses.begin(), courses.end(), [](const vector<int> & a, const vector<int> & b){
            return a[1] < b[1]; 
        });

        priority_queue<int> maxHeap; 
        int totalTime = 0; 

        for(int i=0; i < courses.size(); ++i){
            int duration = courses[i][0]; 
            int end = courses[i][1]; 

            // add the current course duration to total time 

            maxHeap.push(duration); 
            totalTime += duration; 

           // if total time exceeds the current course end time, remove the longest course
            if(totalTime > end){
                totalTime -= maxHeap.top(); 
                maxHeap.pop(); 
            }
        }
        return maxHeap.size(); 
    }
};

int main (){
     Solution sol; 
    vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    cout << sol.scheduleCourse(courses) << endl; 

}
*/ 


/*Q.8 : There is a new alien language which uses the latin alphabet. However, 
the order among letters are unknown to you. You receive list of non-empty words 
from the dictionary, where words are sorted lexicographically by the roles of this 
new language. Derive the order of letters in this language. 

*/ 
/*
#include <iostream> 
#include <queue> 
#include <string> 
#include <unordered_map> 
#include <unordered_set>
#include <vector> 

using namespace std; 

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<int, unordered_set<int>> graph; 
        int indegree[26] = {}; 

        // Initialize graph with empty sets for each character present in the words
        for (const auto& word : words) { 
            for (char c : word) {
                graph[c - 'a'] = {}; 
            }
        }

        // Build the graph and calculate indegrees
        for (int i = 1; i < words.size(); i++) {
            int j = 0; 
            while (j < min(words[i - 1].size(), words[i].size()) && words[i - 1][j] == words[i][j]) {
                ++j; 
            }

            if (j < words[i].size() && (j == words[i - 1].size() || words[i - 1][j] != words[i][j])) {
                graph[words[i - 1][j] - 'a'].insert(words[i][j] - 'a'); 
            } else if (j == words[i].size() && j < words[i - 1].size()) {
                return ""; 
            }
        }

        // Compute indegrees
        for (const auto& pair : graph) {
            int from = pair.first;
            const unordered_set<int>& to_set = pair.second;
            for (int to : to_set) {
                indegree[to]++; 
            }
        }

        // Initialize the queue with nodes having zero indegree
        queue<int> zero_indegree_nodes;
        for (int i = 0; i < 26; ++i) {
            if (graph.count(i) && indegree[i] == 0) {
                zero_indegree_nodes.push(i); 
            }
        }

        // Perform topological sorting
        string result; 
        while (!zero_indegree_nodes.empty()) {
            int node = zero_indegree_nodes.front(); 
            zero_indegree_nodes.pop(); 
            result += node + 'a'; 

            for (int neighbor : graph[node]) {
                if (--indegree[neighbor] == 0) {
                    zero_indegree_nodes.push(neighbor); 
                }
            }
        }

        return result.size() == graph.size() ? result : ""; 
    }
};

int main() {
    Solution sol; 

    vector<string> words1 = {"wrt", "wrf", "er", "ett", "rftt"}; 
    string result1 = sol.alienOrder(words1); 
    cout << "Order of characters: " << result1 << endl; 

    return 0; 
}
*/ 

/*Q.9 : Given a 2D grid consist of 0s (land) and 1s (water). An Island is 
a maximal 4 - directionally connected group of 0s and a closed island is 
an island totally (all left, top, right, bottom) surrounded by 1s. 

Return the number of closed islands. */
/*
#include <iostream>
#include <vector>
#include <functional> // Required for std::function
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int closedIsland = 0;

        // function to perform DFS :
        function<bool(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= rows || y >= cols) {
                return false;
            }
            if (grid[x][y] == 1) {
                return true; // water
            }

            grid[x][y] = 1;
            bool top = dfs(x - 1, y);
            bool bottom = dfs(x + 1, y);
            bool left = dfs(x, y - 1);
            bool right = dfs(x, y + 1);

            return top && bottom && left && right; // Must be surrounded on all four sides
        };

        // Main logic
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0 && dfs(i, j)) {
                    closedIsland++;
                }
            }
        }
        return closedIsland;
    }
};

void printGrid(const vector<vector<int>> & grid){
    for(const auto &row : grid){
        for(int cell : row){
            if(cell == 1){
                cout << "1"; 
            }else{
                cout << "0"; 
            }
        }
        cout << endl;
    }
}
int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };

    cout << "Original Grid:" << endl;
    printGrid(grid);

    int result = sol.closedIsland(grid);
    

    printGrid(grid); 
    cout << "Number of closed islands: " << result << endl;
    return 0;
}
*/ 


/*
Question 10: shortest Path with Alternating Colors: 
You are given an integer n, the number of nodes in a directed graph where the
nodes are labled from 0 to n-1. Each edge is red or blue in this graph, and there
could be self edges and parallel edges. 

You are given two arrays redEdges and blueEdges where: 
redEdges[i] = [ai. bi] indicates that there is a directed red edge from node 
ai to node bi in the graph, and ---- 
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node 
uj to node vj in the graph. 

Return an array answer of length n, where each answer[x] is the length of the 
shortest path from node 0 to node x such that the edge colors alternate along
the path, or -1 if such a path does not exist. 

*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redGraph(n), blueGraph(n); 
        for (const auto& edge : redEdges) {
            redGraph[edge[0]].push_back(edge[1]); 
        } 

        for (const auto& edge : blueEdges) {
            blueGraph[edge[0]].push_back(edge[1]); 
        }
   
        // Q for BFS 
        queue<tuple<int, int, int>> q;  // node, color, distance
        vector<vector<bool>> vis(n, vector<bool>(2, false));

        vector<int> answer(n, -1); 

        q.push(make_tuple(0, 0, 0)); // from red Edge
        q.push(make_tuple(0, 1, 0)); // from blue edge

        vis[0][0] = vis[0][1] = true; 
        answer[0] = 0; 

        // BFS Traversal 
        while (!q.empty()) {
            tuple<int, int, int> current = q.front(); 
            q.pop(); 

            int node = get<0>(current);
            int color = get<1>(current); 
            int dist = get<2>(current); 
            int nextColor = 1 - color; // alternate color

            const vector<vector<int>>& nextGraph = (nextColor == 0) ? redGraph : blueGraph; 
            for (int neighbor : nextGraph[node]) {
                if (!vis[neighbor][nextColor]) {
                    vis[neighbor][nextColor] = true; 
                    q.push(make_tuple(neighbor, nextColor, dist + 1)); 
                    if (answer[neighbor] == -1) {
                        answer[neighbor] = dist + 1; 
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution sol;
    
    // Example test case
    int n = 3;
    vector<vector<int>> redEdges = {{0, 1}, {1, 2}};
    vector<vector<int>> blueEdges = {{1, 0}};

    vector<int> result = sol.shortestAlternatingPaths(n, redEdges, blueEdges);

    // Output the result
    cout << "Shortest Alternating Paths: ";
    for (int d : result) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
