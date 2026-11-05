//범위 내에 있는 점의 수 2

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int n, q;
vector<int> v;
vector<pair<int, int>> query;
int acc[1000001];

void input(){
    cin >> n >> q;
    int a, b;
    for (int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < q; i++){
        cin >> a >> b;
        query.push_back({a, b});
    }
}

void sol(){
    sort(v.begin(), v.end());
    int idx = 0;
    for (int i = 0; i <= 1000000; i++){
        if (i == v[idx]) idx++;
        acc[i] = idx;
    }
    for (auto[a, b] : query){
        cout << acc[b] - acc[a - 1] << "\n";
    }
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}