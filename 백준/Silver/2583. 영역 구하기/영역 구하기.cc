#include <bits/stdc++.h>
using namespace std;

#define y1 jjjjj
int M, N, K, x1, y1, x2, y2, a[104][104], visited[104][104], cnt;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector <int> ret;

int dfs(int y, int x){
    if(visited[y][x] == 1) return 0;
    visited[y][x] = 1;
    cnt++;
    
    for(int i = 0; i < 4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
        
        if(a[ny][nx] == 0){
            dfs(ny, nx);
        }
    }
    
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        //초기화 
        for(int j = y1; j < y2; j++){
            for(int k = x1; k < x2; k++){
                a[j][k] = 1;
            }
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] == 0 && visited[i][j] == 0){
                cnt = 0;
                ret.push_back(dfs(i, j));
            }
        }
    }
    
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (int r : ret)
        cout << r << " " ;
}    