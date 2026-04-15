#include <bits/stdc++.h>
using namespace std;

int N, K, root, ret;
vector <int> adj[54];

void dfs(int here){
    int child = 0;
    for(int there : adj[here]){
        if(there== K) continue;
        dfs(there);
        child++;
        
    }
    if(child == 0) ret++;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        if(temp == -1) root = i;
        else adj[temp].push_back(i);
    }
    
    cin >> K;
    if (K == root) {
        cout << 0;
        exit(0);
    }
    
    dfs(root);
    cout << ret; 
    
}