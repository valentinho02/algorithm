#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;


int arr[10];

void input(){
    cin >> k >> n;
}

void func(int cnt){
    
    for (int i = 1; i <= k; i++){
        arr[cnt] = i;
        if (cnt == n){
            for (int i = 1; i <= n; i++) cout << arr[i] << " ";
            cout << endl;
        }
        else func(cnt + 1);
    }
}

void sol(){
    func(1);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}

