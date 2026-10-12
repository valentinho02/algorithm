#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> graph(1001);
void input(){
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

bool visited[1001];
int ans = 0;

void dfs(int x){
    visited[x] = true;
    for (auto next : graph[x]){
        if (visited[next]) continue;
        ans++;
        dfs(next);
    }
}

void sol(){
    dfs(1);
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
    return 0;
}