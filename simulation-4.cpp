//강력한 폭발
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> bomb;
int visited[21][21];
int max_cnt = 0;

int bomb_shapes[3][5][2] = {
    { {-2, 0}, {-1, 0}, {0, 0}, {1, 0}, {2, 0} },
    { {-1, 0}, {1, 0}, {0, 0}, {0, -1}, {0, 1} },
    { {-1, -1}, {-1, 1}, {0, 0}, {1, -1}, {1, 1} }
};

bool in_range(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

void mark(int idx, int type, int val) {
    int r = bomb[idx].first;
    int c = bomb[idx].second;
    for (int i = 0; i < 5; i++) {
        int nr = r + bomb_shapes[type][i][0];
        int nc = c + bomb_shapes[type][i][1];
        if (in_range(nr, nc)) {
            visited[nr][nc] += val;
        }
    }
}

void dfs(int idx) {
    if (idx == (int)bomb.size()) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] > 0) count++;
            }
        }
        max_cnt = max(max_cnt, count);
        return;
    }

    for (int type = 0; type < 3; type++) {
        mark(idx, type, 1);    
        dfs(idx + 1);         
        mark(idx, type, -1);   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (val == 1) {
                bomb.push_back({i, j});
            }
        }
    }

    dfs(0);

    cout << max_cnt << "\n";
    return 0;
}