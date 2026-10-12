#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, k;
int graph[101][101];
bool visited[101][101];
int r, c;
int nr, nc;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input(){
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }
    cin >> r >> c;
    nr = r-1; nc = c-1;
}


void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    int cur = graph[x][y];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) visited[i][j] = false;
    visited[x][y] = true;
    int next_val = -1;
    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;
            if (graph[nx][ny] >= cur) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
            if (next_val < graph[nx][ny]){
                next_val = graph[nx][ny];
                nr = nx;
                nc = ny;
            } else if (next_val == graph[nx][ny]){
                if (nx < nr){
                    nr = nx;
                    nc = ny;
                } else if (nx == nr && ny < nc){
                    nc = ny;
                }
            }
        }
    }
}

void sol(){
    while (k--){
        int tempr = nr;
        int tempc = nc;
        bfs(nr, nc);
        if (nr == tempr && nc == tempc) break;;
    }
    cout << nr + 1 << " " << nc + 1<< "\n";
}

int main(){
    cin.tie(nullptr); 
    ios_base::sync_with_stdio(false);
    input();
    sol();
    return 0;
}