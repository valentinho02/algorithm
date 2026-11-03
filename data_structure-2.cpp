//수 등장 횟수

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> q;
unordered_map<int, int> um;
void input(){
    cin >> n >> m;
    int a;
    for (int i = 0; i < n; i++){
        cin >> a;
        if (um.find(a) == um.end()) um[a] = 1;
        else um[a]++;
    }
    for (int i = 0; i < m; i++){
        cin >> a;
        q.push_back(a);
    }
}

void sol(){
    for (int a : q){
        if (um.find(a) == um.end()) cout << "0 ";
        else cout <<um[a] << " ";
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}