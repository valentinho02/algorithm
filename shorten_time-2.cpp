#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int arr[501][501];
int acc[501][501];

void input(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
}

void sol(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            acc[i][j] = acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1] + arr[i][j];
        }
    }
    int max = -1;
    for (int i = k; i <= n; i++){
        for (int j = k; j <= n; j++){
            if (acc[i][j] - acc[i - k][j] - acc[i][j - k] + acc[i - k][j - k] > max){
                max = acc[i][j] - acc[i - k][j] - acc[i][j - k] + acc[i - k][j - k];
            }
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