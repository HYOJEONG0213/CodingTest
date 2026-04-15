#include <bits/stdc++.h>
using namespace std;

int N, M, bird_visited[1504][1504], water_visited[1504][1504], sy, sx, fy, fx, y, x, ret;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
char a[1504][1504];
queue <pair<int, int>> bird, water, bird_next, water_next;
string s;

void resetQ(queue <pair<int, int>> &q){
    queue <pair<int, int>> temp;
    swap(q, temp);
}

bool bird_move(){
    while(bird.size()){
        tie(y, x) = bird.front();
        bird.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(bird_visited[ny][nx] != 0) continue;
            bird_visited[ny][nx] = 1;
            if(a[ny][nx] == 'X') 
                bird_next.push({ny, nx});
            else if(a[ny][nx] == '.')
                bird.push({ny, nx});
            else if(a[ny][nx] == 'L') return true;
        }
    }
    
    return false;
}

void ice_melting(){
    while(water.size()){
        tie(y, x) = water.front();
        water.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(water_visited[ny][nx] != 0) continue;
            water_visited[ny][nx] = 1;
            if(a[ny][nx] == 'X') {
                water_visited[ny][nx] = 1;
                water_next.push({ny, nx});
                a[ny][nx] = '.';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < M; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'L' || a[i][j] == '.'){
                water.push({i, j});
                water_visited[i][j] = 1;
            }
            if(a[i][j] == 'L') {
                sy = i; 
                sx = j;
            }
        }
    }
    
    
    bird_visited[sy][sx] = 1;
    bird.push({sy, sx});
    while(bird_move() == false){
        ret++;
        ice_melting();
        
        bird = bird_next;
        water = water_next;
        
        resetQ(bird_next);
        resetQ(water_next);
    }
    
    cout << ret;
}