#include <bits/stdc++.h>
using namespace std;

int T, N, M, K, visited[54][54], a[54][54];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
    if(visited[y][x] == 1) return;
    
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(a[ny][nx] == 0) continue;
        
        dfs(ny, nx);
    }
}

int main(){
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> M >> N >> K;
        int ret = 0;
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(a));
        
        for(int j = 0; j < K; j++){
            int y, x;
            cin >> x >> y;
            a[y][x] = 1;
        }
        
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(visited[j][k] == 0 && a[j][k] == 1){
                    dfs(j, k);
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }
}