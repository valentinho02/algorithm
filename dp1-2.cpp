// 계단 오르기
# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int n;
int dp[1001];

void input(){
    cin >> n;
}

int dfs(int cur){
    int cnt = 0;
    if (cur >= 2 &&dp[cur - 2] == -1) cnt += dfs(cur - 2);
    else if (cur >= 2) cnt += dp[cur - 2];
    if (cur >= 3 && dp[cur - 3] == -1) cnt += dfs(cur - 3);
    else if (cur >= 3) cnt += dp[cur -3];
    dp[cur] = cnt % 10007;
    return dp[cur];
}

void sol(){
    dp[0] = 1; dp[1] = 0;
    for (int i = 2; i <= n; i++) dp[i] = -1;
    dfs(n);
    cout << dp[n];
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}