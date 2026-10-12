//아름다운 수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
int arr[14];
int ans = 0;
void input(){
    cin >> n;
}

void func(int len){
    if (len > n) return;
    if (len == n) {
        ans++;
        return;
    }
    for (int i = 1; i <= 4; i++){
        for (int j = len + 1; j <= len + i; j++) arr[j] = i;
        func(len + i); 
    }
}

void sol(){
    func(0);
    cout << ans << "\n";
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}