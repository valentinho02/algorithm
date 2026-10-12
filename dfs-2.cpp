#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int graph[101][101];
bool visited[101][101];
int n, m;

void input(){
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
}

void dfs(int x, int y){
    for (int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
        if (!graph[nx][ny]) continue;
        if (visited[nx][ny]) continue;
        visited[nx][ny] = true;
        dfs(nx, ny);
    }
}

void sol(){
    if (graph[0][0]) dfs(0, 0);
    cout << (int)visited[n-1][m-1] << "\n";
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}