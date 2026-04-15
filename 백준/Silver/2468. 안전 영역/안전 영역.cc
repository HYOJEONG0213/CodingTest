#include <bits/stdc++.h>
using namespace std;

int N, a[104][104], visited[104][104], dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1}, cnt, ret = 1;

void dfs(int y, int x, int height){
    if(visited[y][x] == 1) return;
    
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if(a[ny][nx] > height) {
            dfs(ny, nx, height);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <=100; i++){
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(a[j][k] > i && visited[j][k] == 0){
                    dfs(j, k, i);
                    cnt++; 
                }
            }
        }
        ret = max(cnt, ret);    
    }
    
    cout << ret;
}