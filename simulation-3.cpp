//트로미노
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int graph[201][201];

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
}

void sol(){
    int ans = -1;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m - 1; j++){
            int square = graph[i][j] + graph[i + 1][j] + graph[i][j+ 1] + graph[i + 1][j + 1];
            for (int p = 0; p < 2; p++){
                for (int q = 0; q < 2; q++){
                    ans = max(ans, square - graph[i + p][j + q]);
                }
            }
        }
    }
    for (int i = 0; i < n - 2; i++){
        for (int j = 0; j < m; j++){
            ans = max(ans, graph[i][j] + graph[i + 1][j] + graph[i+2][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m - 2; j++){
            ans = max(ans, graph[i][j] + graph[i][j+ 1] + graph[i][j + 2]);
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