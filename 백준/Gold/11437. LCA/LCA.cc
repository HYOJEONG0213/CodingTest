#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, parent[50004][20], depth[50004], visited[50004];
vector <int> adj[50004];
const int MAXNUM = 16;

void setParent(){
	for(int i = 1; i < MAXNUM; i++){
		for(int j = 1; j <= N; j++){
			parent[j][i] = parent[parent[j][i-1]][i-1];
		}
	}
}

int LCA(int x, int y){
	if(depth[x] > depth[y]) swap(x, y);
	
	for(int i = MAXNUM-1; i >= 0; i--){
		if(depth[y] - depth[x] >= (1<<i)){
			y = parent[y][i];
		}
	}
	
	if(x == y) return x;
	
	for(int i = MAXNUM-1; i >= 0; i--){
		if(parent[x][i] != parent[y][i]){
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	
	return parent[x][0];
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
			parent[i][0] = x;
			q.push(i);
		}
	} 
	
	setParent();
	
	cin >> M;
	
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}