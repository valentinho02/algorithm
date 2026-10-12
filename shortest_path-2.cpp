#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> graph(20001);

void input(){
    cin >> n >> m >> k;
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

void sol(){
    int dist[20001];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[k], k});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        if (d > dist[cur]) continue;
        for (auto[next, w] : graph[cur]){
            if (d + w < dist[next]){
                dist[next] = d + w;
                pq.push({dist[next], next});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (dist[i] == INT_MAX){
            cout << "-1\n"; 
            continue;
        }
        cout << dist[i] << "\n";
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}