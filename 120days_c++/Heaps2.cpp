// 42:NB2:67: Heaps Part : II:
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapify(int i, vector<int> &arr, int n){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxI = i;

    // for descending <
    if(left < n && arr[left] > arr[maxI]) {
        maxI = left;
    }
    // for descending <
    if(right < n && arr[right] > arr[maxI]){
        maxI = right;
    }

    if(maxI != i){
        swap(arr[i], arr[maxI]);
        heapify(maxI, arr, n); // pass values to function
    }
}

void heapSort(vector<int> &arr){
    int n = arr.size();

    // step1: build maxHeap
    for(int i = n/2-1;  i >= 0;  i--){ // O(n*logn)
        heapify(i, arr, n);
    }

    // step 2 : taking elements to correct position
    for(int i = n-1; i >= 0; i--){ // O(n*logn)
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main(){
    vector<int> arr = {1, 4, 2, 5, 3};
    heapSort(arr);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

/*Q.2 NearBy Cars: Based on car locations (Cx, Cy), find nears K cars */

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Car {
public:
    int idx;
    int distSq;

    Car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq;
    }

    // operator overloading
    bool operator < (const Car &obj) const {
        return this->distSq < obj.distSq;  // minheap
    }
};

void nearbyCars(vector<pair<int, int>> pos, int K) {
    vector<Car> cars;  // store all Car objects

    for (int i = 0; i < pos.size(); i++) { // O(n)
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i, distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());

    for (int i = 0; i < K; i++) { // O(K * log n + n)
        cout << "car " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<pair<int, int>> pos;
    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));

    int K = 2;
    nearbyCars(pos, K);
    return 0;
}
*/

/*Q.3 : Connect N Ropes :
If cost to connect 2 Ropes = Sum of their lengths find min costs to connect n
Ropes.

also same question
merge Stone : in leat code Q.->1000
*/
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int connectNRopes(vector<int> ropes){
    priority_queue<int, vector<int>,greater<int>>  pq(ropes.begin(), ropes.end());
    int cost = 0;

    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost += min1 + min2;
        pq.push(min1 + min2);

    }

    return cost;
}
int main(){
    vector<int> ropes = {4, 3, 2, 6};
    connectNRopes(ropes);

  return 0;
}
*/

/*Q.4: for an M*N metrix, a row is weaker than a row if one of the following is true
- The numbers of soldiers in row i is less than the number of soldiers in row j
- Both rows have the same number of soldiers  i<j
*Find K weakest rows:  soldier = 1: civilians = 0; */

/*
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Row{
    public:
        int count; // soldier count
        int idx;

        Row(int count, int idx){
            this->count = count;
            this->idx = idx;
        }

        bool operator < (const Row &obj) const{
            if(this->count == obj.count){
                return this->idx > obj.idx;
            }
            return this->count > obj.count; // meanHeap
        }
};
void weakestSoldier(vector<vector<int>> matrix, int K){
    vector<Row> rows;
    for(int i = 0; i<matrix.size(); i++){
        int count = 0;
        for(int j=0; j<matrix[i].size() && matrix[i][j]== 1; j++){

                count++;

        }
        rows.push_back(Row(count, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i=0; i<K; i++){
        cout <<"Row: "<< pq.top().idx << endl;
        pq.pop();
    }
}
int main(){
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                {1, 1, 1, 1},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}};

    weakestSoldier(matrix, 3);
    return 0;
}*/

/* Q.5: Sliding Window Maximum:
 - Maximum of all subArray of size K

  K = 3: */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void slidingWindowMax(vector<int> arr, int K)
{
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < K; i++)
    {
        pq.push(make_pair(arr[i], i));
    }

    cout << "output: " << pq.top().first << " ";

    for (int i = K; i < arr.size(); i++)
    {
        while (!pq.empty() && pq.top().second <= (i - K))
        { // outside window
            pq.pop();
        }

        pq.push(make_pair(arr[i], i));

        cout << pq.top().first << " ";
    }
}
int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int K = 3;

    slidingWindowMax(arr, K);
    return 0;
}


