#include <bits/stdc++.h>
using namespace std;
int N, M, max_cnt = 0, visited[10004], dp[10004];
vector <int> adj[10004];
vector <int> ret;


int dfs(int here){
    visited[here] = 1;
    int ret = 1;
      
    for(int there : adj[here]){
        if(visited[there]==1) continue;
        ret += dfs(there);
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        //cout << d << " ";
        //cout << i << " : " << max_cnt << "    ";
        max_cnt = max(dp[i], max_cnt);
    }

    for(int i =1; i <= N; i++)
        if (max_cnt == dp[i])
            cout << i << " ";

}