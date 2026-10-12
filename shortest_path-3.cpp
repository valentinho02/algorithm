#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph(100001);

void input(){
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        graph[b].push_back({a, c});
    }
}

void sol(){
    int dist[100001];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[n] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[n], n});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        if (dist[cur] < d) continue;
        for (auto[next, w] : graph[cur]){
            if (d + w < dist[next]){
                dist[next] = d + w;
                pq.push({dist[next], next});
            }
        }
    }
    int ans = -1;
    for (int i = 1; i < n; i++){
        if (ans < dist[i]) ans = dist[i];
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}