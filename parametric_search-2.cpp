//수의개수
//https://edu.codetree.ai/hanyang/class/204/learn/lecture/2075/curated-cards/intro-number-of-integers/description

# include <iostream>
# include <algorithm>
# include <vector>
# include <unordered_map>

using namespace std;

int n, m;
unordered_map<int, int> um;
vector<int> query;

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
        query.push_back(a);
    }
}

void sol(){
    for (int q : query){
        if (um.find(q) == um.end()) cout << "0\n";
        else cout << um[q] << "\n";
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}