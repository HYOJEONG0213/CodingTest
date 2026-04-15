#include <bits/stdc++.h>
using namespace std;
#define prev aaaaaa

int M, N, a[104][104], visited[104][104], ret, prev;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector <pair<int, int>> deletelist;

 void dfs(int y, int x){
     visited[y][x] = 1;
     
     if(a[y][x] == 1){
         deletelist.push_back({y, x});
         return;
     }
 
     for(int i = 0; i < 4; i++){
         int ny = dy[i] + y;
         int nx = dx[i] + x;
         if(ny < 0 || nx < 0 || ny >= M || nx >= N || visited[ny][nx] == 1) continue;
         dfs(ny, nx);        
     }
     return;
 }
 
 int check(){
     int sum = 0;
     for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] == 1) sum++;
    //        cout << a[i][j] << " ";
        }
   //     cout << "\n";
     }
     
     return sum;
 }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) prev++;
        }
    }
    
    while(true){
        deletelist.clear();
        memset(visited, 0, sizeof(visited));
//        fill(deletelist.begin(), deletelist.end(), 0);
        dfs(0, 0);
        /*for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(a[i][j] == 0 && visited[i][j] == 0){
                    dfs(i, j);
                }
            }
        }*/
    
        for(pair <int, int> p: deletelist){
          //  cout << p.first << p.second << " ";
            a[p.first][p.second] = 0; 
         //   cout << y<<x <<" ";
        }
       
       ret++; 
        int c = check(); 
       // cout << c << " ";
        if(c == 0) {
            cout << ret << "\n";
            cout << prev;
            exit(0);
        }
        else {
            prev = c;
          //  cout << "test" << prev << " ";
        }
        
    }
}