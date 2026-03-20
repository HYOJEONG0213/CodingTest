#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
const int MAXNUM = 18;
int N, M, u, v, w, k, a, idx, parent[100004][MAXNUM], visited[100004];
ll dist[100004];
vector <pp> adj[100004];

void bfs(){
	queue <int> q;
	q.push(1);
	visited[1] = 1;
	
	while(q.size()){
		int here = q.front(); q.pop();
		for(auto i : adj[here]){
			v = i.first, w = i.second;
			if(visited[v]) continue;
			visited[v] = visited[here]+1;
			parent[v][0] = here;
			dist[v] = dist[here] + w; 
			q.push(v);
		}
	}
}

void setParent(){
	for(int j = 1; j < MAXNUM; j++){
		for(int i = 1; i<=N; i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
}

int getLCA(int u, int v){
	if(visited[u] < visited[v]) swap(u, v);
	for(int i = MAXNUM-1; i >= 0; i--){
		if(visited[u]-visited[v] >= 1<<i){
			u = parent[u][i];
		}
	}
	
	if(u==v) return u;
	
	for(int i = MAXNUM-1; i >= 0; i--){
		if(parent[u][i]!=parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	
	return parent[u][0];
}

ll getDist(int u, int v){
	int LCA = getLCA(u, v);
	return dist[u] + dist[v] - dist[LCA]*2;
}

int getKNum(int u, int k){
	for(int i = MAXNUM-1; i >= 0; i--){
		if(k >= (1 << i)) {
			u = parent[u][i];
			k -= (1<<i);
		}
	}
	
	return u;
}

int getNum(int u, int v, int k){
	int num = 1;
	int ret = u;
	
	int LCA = getLCA(u, v);
	int left = visited[u] - visited[LCA] + 1;
	int right = visited[v]- visited[LCA] ;
	if(k <= left){
		return getKNum(u, k-1);
	}
	else{
		k -= left;
		return getKNum(v, right-k);
	}
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i < N; i++){
		cin >> u >> v >> w;
		
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	bfs();
	setParent();
	
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> a;
		if(a==1){
			cin >> u >> v;
			cout << getDist(u, v) << "\n";
		}
		else{
			cin >> u >> v >> k;
			cout << getNum(u, v, k) << "\n";
		}
	}
}