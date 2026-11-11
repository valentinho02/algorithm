// 안전지대
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int graph[51][51];
void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
}

int safe_floor[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void draw_floor(int f){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (graph[i][j] > f) safe_floor[i][j] = 1;
            else safe_floor[i][j] = 0;
        }
    }
}

bool dfs(int x, int y){
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
        if (safe_floor[nx][ny] != 1) continue;
        safe_floor[nx][ny] = 2;
        dfs(nx, ny);
    }
    return safe_floor[x][y];
}

void sol(){
    pair<int, int> ans = {1, 0};
    for (int floor = 1; floor <= 100; floor++){
        int cnt = 0;
        draw_floor(floor);
        for (int i =0 ; i < n; i++){
            for (int j = 0; j < m; j++){
                if (safe_floor[i][j] == 1 && dfs(i, j)) cnt++;
            }
        }
        if (ans.second < cnt){
            ans = {floor, cnt};
        }
    }
    cout << ans.first << " " << ans.second;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}
