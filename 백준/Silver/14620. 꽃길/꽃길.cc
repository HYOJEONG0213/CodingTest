#include <bits/stdc++.h>
using namespace std;

int N, arr[14][14], visited[14][14], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, ret = 987654321;
vector <int> v;

void dfs(int level, int sum){
    if(level == 3){
        ret = min(ret, sum);
        return;
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            bool flag = true;
            if(visited[i][j] == 1) continue;
        
            for(int k = 0; k < 4; k++){
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] == 1) {
                    flag = false;
                    break;
                }
            }
            if(flag == false) continue;
            
            visited[i][j] = 1;
            sum += arr[i][j];
            for(int k = 0; k < 4; k++){
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                sum += arr[ny][nx];
                visited[ny][nx] = 1;
            }
            
            dfs(level+1, sum);
            
            visited[i][j] = 0;
            sum -= arr[i][j];
            for(int k = 0; k < 4; k++){
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                sum -= arr[ny][nx];
                visited[ny][nx] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j]; 
        }
    }
    
    dfs(0, 0);
    
    cout << ret;
}