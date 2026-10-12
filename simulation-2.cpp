//행복한 수열의 개수
#include <iostream>
#include <algorithm>

using namespace std;

int arr[301][301];
int n, m;

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
}

void sol(){
    int ans = 0;
    for (int i = 0; i < n; i++){
        bool is_happy;
        for (int j = 0; j <= n - m ; j++){
            is_happy = true;
            for (int k = j; k < j + m; k++){
                if (arr[i][k] != arr[i][j]){
                    is_happy = false;
                }
            }
            if (is_happy){
                ans++;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++){
        bool is_happy;
        for (int j = 0; j <= n - m; j++){
            is_happy = true;
            for (int k = j; k < j + m; k++){
                if (arr[k][i] != arr[j][i]){
                    is_happy = false;
                }
            }
            if (is_happy){
                ans++;
                break;
            }
        }
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}