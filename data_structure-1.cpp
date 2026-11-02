#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
unordered_map<int, int> um;

void sol(){
    cin >> n;
    string s;
    int a, b;
    while (n--){
        cin >> s;
        if (s == "add"){
            cin  >> a >> b;
            um[a] = b;
        } else if (s == "find"){
            cin >> a;
            if (um.find(a) != um.end()) cout << um[a] << "\n";
            else cout << "None\n";
        } else if (s == "remove"){
            cin >> a;
            um.erase(a);
        }
    }   
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}