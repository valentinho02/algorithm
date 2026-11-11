//최단거리3
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> edge(1001);
int st,dt;
int dist[1001];
int back[1001];

void input(){
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m ; i++){
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    cin >> dt >> st;
}

void sol(){
    for (int i = 0; i <= n; i++){
        dist[i] = INT_MAX;
        back[i] = INT_MAX;
    }
    priority_queue<pair<int, int>> pq;
    dist[st] = 0;
    back[st] = st;
    pq.push({dist[st], st});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        if (d > dist[cur]) continue;
        for (auto[next, cost] : edge[cur]){
            if (dist[next] == d + cost) back[next] = min(back[next], cur);
            else if (dist[next] > d + cost){
                dist[next] = d + cost;
                pq.push({dist[next], next});
                back[next] = cur;
            } 
        }
    }
    cout << dist[dt] << "\n";
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}