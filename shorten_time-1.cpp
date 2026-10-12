#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;
vector<int> acc;

void input(){
    cin >> n >> k;
    int num;
    for (int i = 0 ; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
}

void sol(){
    acc.push_back(0);
    for (int i = 0; i < n; i++){
        acc.push_back(acc[i] + v[i]);
    }
    int max = -1;
    for (int i = k; i <= n; i++){
        if (acc[i] - acc[i - k] > max){
            max = acc[i] - acc[i - k];
        }
    }
    cout << max;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}