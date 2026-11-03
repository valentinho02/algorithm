//최단 거리 11

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, start, _end;
vector<vector<pair<int, int>>> graph(1001);
int dist[1001];


void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> start >> _end;
}

bool cmp(pair<int, int> a){
    return a.first < a.second;
}

void sol(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[start], start}); 
    while (!pq.empty()){

    }
}