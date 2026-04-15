#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int n, m, y, x, visited[max_n][max_n], a[max_n][max_n];
string s;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> s; 
        for(int j = 0; j < m; j++){
            a[i][j] = s[j] - '0';
            //scanf("%1d", &a[i][j]);
        }
    }
    
    queue <pair<int, int>> q;
    visited[0][0] = 1;     //첫번째에 꼭 방문처리를 해줘야!!! 
    q.push({0, 0});    //1, 1에서 출발한다고는 하지만 우리 배열에선 (0,0)이므로! 
    
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] != 0 || a[ny][nx] == 0) continue;
            
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        
        }
        
    }
    
    cout << visited[n-1][m-1];    //와 여기서 틀렸었넹;;;
    
}