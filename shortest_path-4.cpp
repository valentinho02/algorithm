#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

int n, m, a, b;
vector<vector<pair<int, int>>> graph(1001);

void input(){
    cin >> n >> m;
    int c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> a >> b;
}

void sol(){
    int dist[1001][2];
    for (int i = 0; i <= n; i++) dist[i][0] = INT_MAX;

    dist[a][0] = 0;
    dist[a][1] = a;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[a][0], a});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        if (d > dist[cur][0]) continue;
        for (auto[next, w] : graph[cur]){
            if (d + w < dist[next][0]){
                dist[next][0] = d + w;
                dist[next][1] = cur;
                pq.push({dist[next][0], next});
            }
        }
    }
    cout << dist[b][0] << "\n";
    stack<int> s;
    int node = b;
    s.push(b);
    while (node != a){
        node = dist[node][1];
        s.push(node);
    }
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}