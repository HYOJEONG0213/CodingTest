#include <bits/stdc++.h>
using namespace std;

int N, L, R, sum, ret, dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, visited[54][54], a[54][54];
vector <pair<int, int>> v;

int comp(int a, int b){
    if(abs(a - b) >= L && abs(a - b) <= R) return 1;
    else return 0;
}

void dfs(int y, int x){
    for(int i = 0 ; i < 4; i ++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if(visited[ny][nx] != 0) continue;
        if(comp(a[ny][nx], a[y][x]) == 1){
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += a[ny][nx];
            dfs(ny, nx);
        }
    }   
}

int main(){
    cin >> N >> L >> R;
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0; j < N ; j ++){
            cin >> a[i][j];
        }
    }    
    
    while(true){
        bool flag = false;
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0; j < N ; j ++){
                if(visited[i][j] == 0){
                    sum = a[i][j];
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    dfs(i, j);
                    
                    if(v.size() == 1) continue;
                    
                    flag = true;
                    int avg = sum / v.size();
                
                    for(auto u : v){
                        a[u.first][u.second] = avg;
                    }
                    
                }
            }
        }
        
        if(flag == false) break;
        ret++;
        
    }
    
    cout << ret;
}