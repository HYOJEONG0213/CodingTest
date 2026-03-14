#include <bits/stdc++.h>
using namespace std;

const int MAXDEPTH=20;
int N, M, a, b, visited[100004], parent[100004][MAXDEPTH];
vector <int> adj[100004];

void setParent(){
	for(int i = 1; i < MAXDEPTH; i++){
		for(int j = 1; j <= N; j++){
			parent[j][i] = parent[parent[j][i-1]][i-1];
		}
	}
}

int getParent(int u, int v){
	if(visited[u] < visited[v]) swap(u, v);
	for(int i = MAXDEPTH-1; i>=0; i--){
		if(visited[u]-visited[v] >= (1<<i))
			u = parent[u][i];
	}
	if(u==v) return u;
	
	for(int i = MAXDEPTH-1; i>=0; i--){
		if(parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N-1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue <int> q;
	visited[1] = true;
	q.push(1);
	while(q.size()){
		int x = q.front(); q.pop();
		
		for(int i : adj[x]){
			if(visited[i]) continue;
			visited[i] = visited[x]+1;
			parent[i][0] = x;
			q.push(i);
		}
	}
	
	setParent();
	
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		cout << getParent(a, b) << "\n"; 
	}
}