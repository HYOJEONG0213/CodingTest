/*

3 4
2 2 0 0
2 2 0 0
2 2 2 2

*/


#include <bits/stdc++.h>
using namespace std;

int N, M, a[10][10], temp[10][10], visited[10][10], dy[4] = {-1,0,1,0}, dx[4]={0,1,0,-1}, cnt, ret;
vector <pair<int, int>> v;

void dfs(int y, int x){
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        
        if(visited[ny][nx]==0 && temp[ny][nx] == 0) dfs(ny, nx);
    }
    
    return;

}

void solve(vector <int> &b){
    cnt = 0;
    memset(visited, 0, sizeof(visited));
    memcpy(temp, a, sizeof(a));
    //벽세우기 
    for(int i = 0; i < b.size(); i++){
        int y1, x1;
        tie(y1, x1) = v[b[i]];
        temp[y1][x1] = 1;   
    }
        
    //벽 세운뒤 dfs하기(감염시키기)  
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(temp[i][j] == 2 && visited[i][j] == 0){
                dfs(i, j);    
            }
        }
    }
        
    //감염을 마친후 안전한 영역 수 구하기
        
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(temp[i][j] == 0 && visited[i][j] == 0) cnt ++;
        }
    }
    
    ret = max(ret, cnt);
    
    return;
}

void combi(int start, vector <int> &b){
    //임의의 벽 3개를 세우기용. 
    if(b.size() == 3) {
        solve(b);
        return;
    }
    
//    memcpy(a, temp, sizeof(temp));    //ㅎㅎ;; a를 고치기엔 실수 많을듯 
    
    //조합하기. 이때 해당 지점이 0인 지역만 가능함. << 전역변수 벡터는 0인것만 넣었자낭! 
    for(int i = start+1; i < v.size(); i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back(); 
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            
            if(a[i][j] == 0) v.push_back({i, j});
        }
    }
    
    vector <int> b;
    //벽 임의로 3개 지정하기 위해 조합을 사용. 
    combi(-1, b);
    
    cout << ret;
}