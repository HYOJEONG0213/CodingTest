#include <bits/stdc++.h>
using namespace std;

int N, K, dx[2] = {-1, 1};
queue <int> q;
int visited[100004];
long long cnt[100004];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    
    //bfs 첫번째 넣는것에 대한 처리를 꼭!! 
    q.push(N);
    visited[N] = 1;
    cnt[N] = 1;
    
    while(q.size()){
        int f = q.front();
        q.pop();
        for(int nx : {f + 1, f - 1, f * 2}){
            if(nx < 0 || nx > 100000) continue;
            
            if(visited[nx] == 0) {
                visited[nx] = visited[f] + 1;
                q.push(nx);
                cnt[nx] += cnt[f];
            }
            
            else if(visited[nx] == visited[f] + 1){
                cnt[nx] += cnt[f];
            }
        }
    }
    
    cout << visited[K] - 1 << "\n";
    cout << cnt[K];
}