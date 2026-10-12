//연속한 k개의 숫자

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>

using namespace std;

int n, k, b;

int arr[100001];
unordered_set<int> missing;

void input(){
    cin >> n >> k >> b;
    int miss;
    for (int i = 0; i < b; i++){
        cin >> miss;
        missing.insert(miss);
    }
}

void sol(){
    for (int i = 1; i <= n; i++){
        if (missing.find(i) == missing.end()){ //exist
            arr[i] = arr[i - 1];
        } else{
            arr[i] = arr[i - 1] + 1;
        }
    }
    int min = INT_MAX;
    for (int i = k; i <= n; i++){
        if (arr[i] - arr[i - k] < min){
            min = arr[i] - arr[i - k];
        }
    }
    cout << min;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}