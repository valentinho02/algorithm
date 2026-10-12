#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int graph[101][101];
queue<pair<int, int>> q;
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
}

void sol(){

    if (!graph[0][0]){
        cout << 0;
        return;
    } 
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if (!graph[nx][ny]) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    cout << (int)visited[n - 1][m - 1];
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}