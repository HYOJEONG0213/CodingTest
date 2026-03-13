#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, parent[50004], depth[50004], visited[50004];
vector <int> adj[50004];

int LCA(int x, int y){
	if(depth[x] > depth[y]) swap(x, y);
	while(depth[x] != depth[y]) y = parent[y];
	while(x != y){
		x = parent[x];
		y = parent[y];
	}
	
	return x;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N-1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	// 전처리! 
	visited[1] = 1;
	queue <int> q;
	q.push(1);
	while(q.size()){
		int x = q.front(); q.pop();
		
		for(int i : adj[x]){
			if(visited[i]) continue;
			visited[i] = 1;
			depth[i] = depth[x]+1;
			parent[i] = x;
			q.push(i);
		}
	} 
	
	
	cin >> M;
	
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}