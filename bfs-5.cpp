//빙하

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int graph[301][301];
bool visited[301][301];
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

bool check(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (graph[i][j] == 1) return false;
        }   
    }
    return true;
}

int bfs(){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) visited[i][j] = false;
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()){
        auto[x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if (graph[nx][ny] == 1){
                cnt++;
                graph[nx][ny] = 0;
            }
            else if (graph[nx][ny] == 0){
                q.push({nx, ny});
            }
        }
    }
    return cnt;
}

void sol(){
    int tm = 0;
    while (true){
        tm++;
        int cnt = bfs();
        if (check()){
            cout << tm << " " << cnt;
            return;
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}