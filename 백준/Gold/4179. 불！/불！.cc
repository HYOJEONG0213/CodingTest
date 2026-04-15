#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int R, C, visited[1004][1004], p_visited[1004][1004], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, ret = 1, sy, sx, x, y;
char a[1004][1004];
string s;
vector <pair<int, int>> fire;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    queue <pair<int, int>> q;
    fill(&visited[0][0], &visited[0][0] + 1004 * 1004, INF);
    
    cin >> R >> C;
    for(int i =0 ; i < R ; i++){
        cin >> s;
        for(int j = 0 ; j < C; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'F') {
                //fire.push_back({i, j});
                q.push({i, j});
                visited[i][j] = 1;
            }
            else if(a[i][j] == 'J') {
                sy = i; sx = j;
            }
        }
    }
    
    
    //불의 bfs 
//    for(int i = 0 ; i < fire.size(); i++){
 //      q.push(fire[i]); 
 //      visited[q.front().first][q.front().second] = 1; //불 있는 자리 방문 처리 
       
       while(q.size()){
           tie(y, x) = q.front();
           q.pop();
           
           for(int i = 0 ; i < 4; i++){
               int ny = dy[i] + y; 
               int nx = dx[i] + x;
               if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue; 
               if(a[ny][nx] == '#') continue;
               if(visited[ny][nx] != INF || visited[ny][nx] < visited[y][x] + 1) continue;
               
               visited[ny][nx] = visited[y][x] + 1;
               q.push({ny, nx});
           }
       //}
    }
    
    /*for(int i =0 ; i < R ; i++){
        //cin >> s;
        for(int j = 0 ; j < C; j++){
            cout << visited[i][j];
        }
        cout <<"\n";
    }*/
    
    
    //사람의 bfs 
    q.push({sy, sx});
    p_visited[sy][sx] = 1;
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        
        //cout << y <<"," << x<<" ";
        
        if(y == 0 || x == 0 || y == R-1 || x == C-1) {
               cout << p_visited[y][x];
               exit(0);
        }
        
        for(int i = 0 ; i < 4; i++){
           int ny = dy[i] + y; 
           int nx = dx[i] + x;
           
           //이미 사람이 방문한거라면 ㅈㅈ 
           if(a[ny][nx] != '.') continue;
           if(p_visited[ny][nx] != 0) continue;
           //불의 방문값이 사람의 방문값보다 작은 경우는 못지나가므로 ㅈㅈ 
           //cout <<ny << "," << nx << ":"<<visited[ny][nx] << " ";
          // if(visited[ny][nx] != 0 && visited[ny][nx] <= p_visited[y][x] + 1) continue;
           if(visited[ny][nx] <= p_visited[y][x] + 1) continue;
           
           p_visited[ny][nx] = p_visited[y][x] + 1;
           q.push({ny, nx});
           //    cout << "오예";
           
        }
    }
    
    cout << "IMPOSSIBLE";
}  