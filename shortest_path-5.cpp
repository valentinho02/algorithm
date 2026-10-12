#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph(101);
bool connected[101][101];

void input(){
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if (connected[a][b]){
            for (int j = 0; j < graph[a].size(); j++){
                if (graph[a][j].first == b){
                    graph[a][j].second = min(graph[a][j].second, c);
                }
            }
        }
        else{
            connected[a][b] = true;
            graph[a].push_back({b, c});
        }
    }
}

void dijkstra(int x){
    int dist[101];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[x], x});
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
        if (dist[i] == INT_MAX) cout << "-1 ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
}

void sol(){
    for (int i = 1; i <= n; i++){
        dijkstra(i);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}