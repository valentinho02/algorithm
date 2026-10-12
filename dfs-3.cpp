#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n;
int graph[26][26];
bool visited[26][26];

int cnt = 0;
int people = 0;
priority_queue <int, vector<int>, greater<>> pq;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
}

void dfs(int x, int y){
    visited[x][y] = true;
    people++;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
        if (!graph[nx][ny]) continue;
        if (visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}

void sol(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visited[i][j] || graph[i][j] == 0) continue;
            cnt++;
            people = 0;
            dfs(i, j);
            pq.push(people);
        }
    }
    cout << cnt << "\n";
    while (!pq.empty()){
        cout << pq.top() << "\n";
        pq.pop();
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}