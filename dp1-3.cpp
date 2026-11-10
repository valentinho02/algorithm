//사각형 채우기
//https://edu.codetree.ai/hanyang/class/398/learn/lecture/4291/curated-cards/challenge-rectangle-fill/description
# include <iostream>
# include <vector>
# include <algorithm>


using namespace std;

int dp[1001];
int n;

void input(){
    cin >> n;
}

int search(int num){
    if (dp[num] != -1){
        return dp[num];
    }
    return dp[num] = (search(num - 2) + search(num - 1)) % 10007;
}

void sol(){
    for (int i = 0; i <= n; i++) dp[i] = -1;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    search(n);
    cout << dp[n] << "\n";
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}