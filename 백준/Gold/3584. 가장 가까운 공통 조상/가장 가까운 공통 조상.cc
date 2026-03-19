#include <bits/stdc++.h>
using namespace std;

const int MAXLEVEL = 16;
int T, N, A, B, parent[10004][MAXLEVEL], visited[10004];
vector <int> adj[10004];


void bfs(){
	int s;
	for(int i = 1; i <= N; i++){
		if(parent[i][0]==0){
			s = i;
			break;
		}
	}
	
	visited[s] = 1;
	queue <int> q;
	q.push(s);
	while(q.size()){
		int here = q.front(); q.pop();
		for(int i : adj[here]){
			if(visited[i]) continue;
			visited[i] = visited[here]+1;
			q.push(i);
		}
	}
}

void setParent(){
	for(int j = 1; j < MAXLEVEL; j++){
		for(int i = 1; i <= N; i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
}

int getParent(int u, int v){
	if(visited[u] < visited[v]) swap(u, v);
	for(int j = MAXLEVEL-1; j >= 0; j--){
		if(visited[u] - visited[v] >= 1<<j){
			u = parent[u][j];
		}
	}
	
	if(u==v) return u;
	
	for(int j = MAXLEVEL-1; j >= 0; j--){
		if(parent[u][j] != parent[v][j]){
			u = parent[u][j];
			v = parent[v][j];
		}
	}
	
	return parent[u][0];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		memset(parent, 0, sizeof(parent));
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < 10004; i++){
			adj[i].clear();
		}
			


		cin >> N;
		for(int i = 0; i < N-1; i++){
			cin >> A >> B;
			adj[A].push_back(B);
			parent[B][0] = A;
		}
		
		bfs();
		setParent();
		cin >> A >> B;
		cout << getParent(A, B) << "\n";
	}
}