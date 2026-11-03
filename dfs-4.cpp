//안전지대

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int graph[101][101];
int low, high;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[101][101];

void input(){
    low = INT_MAX;
    high = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
            if (graph[i][j] < low) low = graph[i][j];
            if (graph[i][j] > high) high = graph[i][j];
        }
    }
}


void dfs(int x, int y, int height){   
    visited[x][y] = true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
        if (graph[nx][ny] > height) continue;
        if (visited[nx][ny]) continue;
        dfs(nx, ny, height);
    }
}

void ans(){
    for (int h = low; h <= high; h++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                visited[i][j] = false;
            }
        }
        int cnt = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!visited[i][j] && graph[i][j] < h){
                    dfs(i, j, h);
                }
            }
        }
    }
}