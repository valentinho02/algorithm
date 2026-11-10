#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, m;
int grid[105][105];
bool is_removed[105][105];

vector<pair<int, int>> stones;
vector<pair<int, int>> start_points;

int max_reachable = 0;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs() {
    bool visited[105][105] = {false};
    queue<pair<int, int>> q;
    int count = 0;

    for (auto p : start_points) {
        q.push(p);
        visited[p.first][p.second] = true;
        count++;
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
                // 이미 방문했으면 스킵
                if (visited[nr][nc]) continue;
                
                // 돌이 있는 칸인데, 치우지 않은 돌이라면 스킵
                if (grid[nr][nc] == 1 && !is_removed[nr][nc]) continue;

                visited[nr][nc] = true;
                count++;
                q.push({nr, nc});
            }
        }
    }
    return count;
}

// M개의 돌을 선택하는 백트래킹 (조합)
void backtrack(int idx, int count) {
    if (count == m) {
        max_reachable = max(max_reachable, bfs());
        return;
    }

    if (idx >= stones.size()) return;

    // 1. 현재 돌을 치우는 경우
    auto [r, c] = stones[idx];
    is_removed[r][c] = true;
    backtrack(idx + 1, count + 1);
    is_removed[r][c] = false; // 원복

    // 2. 현재 돌을 치우지 않는 경우
    backtrack(idx + 1, count);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> k >> m)) return 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                stones.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        start_points.push_back({r, c});
    }

    backtrack(0, 0);

    cout << max_reachable << "\n";

    return 0;
}