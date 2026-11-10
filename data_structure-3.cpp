#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<string, int> um;

void input(){
    cin >> n;
    while (n--){
        string str;
        cin >> str;
        if (um.find(str) == um.end()) um[str] = 1;
        else um[str]++;
    }
}

void sol(){
    int ans = -1;
    for (auto[str, a] : um){
        ans = max(a, ans);
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}