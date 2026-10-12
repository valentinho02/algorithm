//숫자 빠르게 찾기

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, arr[100001];
vector<int> q;

void input(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int a;
    for (int i = 0; i < m; i++){
        cin >> a;
        q.push_back(a);
    }
}

void binary_search(int key){
    int left = 1;
    int right = n;
    int mid;
    while (left <= right){
        mid = (left + right) / 2;
        if (arr[mid] == key) break;
        if (arr[mid] < key){
            left = mid + 1;
        }  else right = mid - 1;
    }
    if (arr[mid] == key) cout << mid << "\n";
    else cout << "-1\n";
}

void sol(){
    for (int key : q){
        binary_search(key);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}