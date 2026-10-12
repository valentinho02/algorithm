#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, k;
int graph[101][101];
bool visited[101][101];
vector<pair<int, int>> start;

void input(){
    cin >> n >> k;
    for (int i = 0 ; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    int xpos, ypos;
    for (int i = 0; i < k; i++){
        cin >> xpos >> ypos;
        start.push_back({xpos - 1, ypos - 1});
    }
}

void sol(){
    int ans = 0;
    for (auto[x, y] : start){
        if (visited[x][y]) continue;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()){
            auto[xpos, ypos] = q.front();
            q.pop();
            if (visited[xpos][ypos]) continue;
            visited[xpos][ypos] = true;
            ans++;
  
            for (int i = 0; i < 4; i++){
                int nx = xpos + dx[i];
                int ny = ypos + dy[i];
                if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                if (graph[nx][ny]) continue;
                if (visited[nx][ny]) continue;
                q.push({nx, ny});
            }   
        }
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}