#include <bits/stdc++.h>
using namespace std;

int T, N, M, A, B, visited[1004];

vector <int> adj[1004];

int dfs(int here){
	int cnt = 1;
	visited[here] = 1;
	for(int there : adj[here]){
		if(visited[there] != 0) continue;
		visited[there] = 1;
		cnt += dfs(there);
	}
	
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N;
		cin >> M;
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < N; i++){
			adj[i].clear();
		}
		
		for(int i = 0; i < M; i++){
			cin >> A >> B;
			adj[A].push_back(B);
			adj[B].push_back(A);
		}
		
		int cnt = dfs(1);
		//cout << cnt;
		if(cnt == N && M == N - 1){
			cout << "tree \n";
		}
		else{
			cout << "graph \n";
		}
	}
}