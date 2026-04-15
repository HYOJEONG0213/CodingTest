#include <bits/stdc++.h>
using namespace std;

#define y1 aaaa
#define y2 aaaaa

int N, M, x1, y1, x2, y2, visited[304][304], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, ret, cnt;
bool flag = true; 
char a[304][304];
string s;


int main(){
    cin >> M >> N;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--; y1--; x2--; y2--;
    for(int i = 0; i < M; i++){
        cin >> s;
        for(int j = 0; j < N; j++){
            a[i][j] = s[j];
        }
    }
    
    queue <int> q;
    q.push(1000 * y1 + x1);
    visited[y1][x1] = 1;
    
    while(a[y2][x2] != '0'){
        cnt++;   
        queue <int> temp;
        while(q.size()){
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
                if(visited[ny][nx] != 0) continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                }
                else if(a[ny][nx] == '0')
                    q.push(1000 * ny + nx);
            }
        }    
        q = temp; 
    }
    
    cout << visited[y2][x2];
}