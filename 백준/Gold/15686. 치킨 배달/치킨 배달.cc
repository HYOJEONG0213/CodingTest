#include <bits/stdc++.h>
using namespace std;

int N, M, a[54][54];
vector <pair<int, int>> chickens;
vector <pair<int, int>> peoples;

int go(int y, int x, vector <int> &v){
    int d_min = 10000;
    for(int i : v){
        int d = abs(chickens[i].first - y) + abs(chickens[i].second - x) ;
        d_min = min(d_min, d);        
    }
    
    return d_min;
    /*if(visited[y][x] == 1) return;
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny > N || nx > N) continue;
        if(a[ny][nx] == 1){
            
        }
    }*/
}

int combi(int start, vector <int> &v){
    if(v.size() == M){
        int temp = 0;
        for(auto i : peoples){
            temp += go(i.first, i.second, v);
        }
        return temp; 
    }
    
    int cnt = 0;
    int min_cnt = 10000;
    for(int i = start + 1; i < chickens.size(); i++){
        v.push_back(i);
        min_cnt = min(min_cnt, combi(i, v)); 
        v.pop_back();
    }
    
    return min_cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N ; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) peoples.push_back({i, j});
            else if(a[i][j] == 2) chickens.push_back({i, j}); 
        }
    }
    
    vector <int> v;
    int min = combi(-1, v);
    cout << min;
}