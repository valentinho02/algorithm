#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph(101);

void input(){
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
}

void sol(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int dist[101];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[1] = 0;
    pq.push({dist[1], 1});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        if (d > dist[cur]) continue;
        for (auto[next, diff] : graph[cur]){
            if (dist[next] > d + diff){
                dist[next] = d + diff;
                pq.push({d + diff, next});
            }
        }
    }
    for (int i = 2; i <= n; i++){
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