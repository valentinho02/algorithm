#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long fibo[46];

void input(){
    cin >> n;
}

void sol(){
    fibo[1] = fibo[2] = 1;

    for (int i = 3; i <= n; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    cout << fibo[n];
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}