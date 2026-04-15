#include <bits/stdc++.h>
using namespace std;

int N, M, visited[54][54], ret, dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
char a[54][54];
vector <pair<int, int>> landList;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j] == 'L') landList.push_back({i, j}); 
        }
    }
    
    for(auto l : landList){
        queue <pair<int, int>> q;
        memset(visited, 0, sizeof(visited));
        
        q.push({l.first, l.second});
        visited[l.first][l.second] = 1;    //맨처음꺼 방문처리 해줘야함 ㅠㅠㅠ!!! 
        
        while(q.size()){
            pair <int, int> f;
            f = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int ny = dy[i] + f.first;
                int nx = dx[i] + f.second;
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(visited[ny][nx] != 0) continue;
                if(a[ny][nx] == 'L') {
                    q.push({ny, nx});
                    visited[ny][nx] = visited[f.first][f.second] + 1;
                    //cout << f.first << f.second << visited[f.first][f.second] << "    ";
                    ret = max(ret, visited[ny][nx]);
                }
            }
        }
    }
    
    cout << ret -1;
}   