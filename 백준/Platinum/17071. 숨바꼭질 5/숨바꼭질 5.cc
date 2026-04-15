#include <bits/stdc++.h>
using namespace std;

int N, K, visited[2][500004], level = 1, sum;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    
    if(N == K){
        cout << 0 << "\n";
        exit(0);
    }
    
    queue <int> q;
    
    q.push(N);
    visited[0][N] = 1;
    
    while(q.size()){
        K = K + level;
        if(K > 500000) break;
        
        if(visited[level % 2][K] != 0){
            cout << level;
            exit(0);
        }
        
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
        int now = q.front();
        q.pop();
        
        for(int i : {now + 1, now - 1, now * 2}){
            if(i < 0 || i > 500000) continue;
            if(visited[level%2][i] != 0) continue;
            if(visited[level%2][i] == 0)
                visited[level%2][i] = visited[(level+1) % 2][now] + 1;
             
            if(i == K) {
                cout << level;
                exit(0);
            }
                
            q.push(i);
        }
        }
        level++;
    }
    
    cout << -1;
}