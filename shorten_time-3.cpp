#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int n;
long long k, arr[1001], acc[1001];
unordered_set<long long> us;

void input(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void sol(){
    for (int i = 1; i <= n; i++) {
        acc[i] = acc[i - 1] + arr[i];
        us.insert(acc[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (us.find(acc[i] + k) != us.end()) ans++;
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}

