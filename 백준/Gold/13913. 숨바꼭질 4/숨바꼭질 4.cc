#include <bits/stdc++.h>
using namespace std;

int N, K, visited[100004], tr[100004];
queue <int> q;
vector <int> ret;

void trace(int a){
    int i = 0;
    while(true){
        ret.push_back(a);
        if(a == N){
            reverse(ret.begin(), ret.end());
            return;
        }
        
        int temp = tr[a];
  //      cout << "*" <<temp<<"*";
        a = temp;
   //     i++;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    
    if(N == K){
        cout << 0 << "\n";
        cout << N;
    }
    
    q.push(N);
    visited[N] = 1;
    
    while(q.size()){
        int now = q.front();
        q.pop();
        
        for(int i : {now + 1, now - 1, now * 2}){
            if(i < 0 || i > 100000) continue;
            if(visited[i] > 0) continue;
            visited[i] = visited[now] + 1;
            tr[i] = now;
         //   cout << visited[i] << " " << i << " " << tr[visited[i]] << "\n";
            
            if(i == K) {
                cout << visited[i] - 1 << "\n";
                trace(K);
                for(int j : ret)
                    cout << j << " " ;
                exit(0);
            }
            
            q.push(i);
        }
    }
}