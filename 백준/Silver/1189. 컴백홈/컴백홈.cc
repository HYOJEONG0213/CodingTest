#include <bits/stdc++.h>
using namespace std;

int R, C, K, visited[10][10], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
char arr[10][10];
string s;

int go(int y, int x){
    if(y == 0 && x == C-1){
        if(visited[y][x] == K)
            return 1;
        return 0;
    }
    
    int ret = 0;
    
    for(int i = 0; i < 4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= R || nx >= C 
        || arr[ny][nx] == 'T' || visited[ny][nx]) continue;
        
        visited[ny][nx] = visited[y][x] + 1;
        ret += go(ny, nx);
        visited[ny][nx] = 0;
    }
    
     return ret;   
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0 ;  j < C ; j++){
            arr[i][j] = s[j];
        }
    }
   
    visited[R-1][0] = 1;
    cout << go(R-1, 0);
}