#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
const int MAXNUM = 17;
int N, M, a, b, c, visited[40004];
int parent[40004][MAXNUM], psum[40004][MAXNUM];
vector <pp> adj[40004];


void bfs(){
	queue <int> q;
	q.push(1);
	visited[1] = 1;
	
	while(q.size()){
		int here = q.front(); q.pop();
		for(auto i : adj[here]){
			int next = i.first, cost = i.second;
			if(visited[next]) continue;
			visited[next] = visited[here]+1;
			parent[next][0] = here;
			psum[next][0] = cost;
			q.push(next);
		}
	}
}

void setParent(){
	for(int j = 1; j < MAXNUM; j++){
		for(int i = 1; i <= N; i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
			psum[i][j] += psum[i][j-1] + psum[parent[i][j-1]][j-1];
		}
	}
}

int getParent(int u, int v){
	int ret = 0;
	if(visited[u] < visited[v]) swap(u, v);
	for(int i = MAXNUM-1; i >= 0; i--){
		if(visited[u]-visited[v] >= 1<<i){
			ret += psum[u][i];
			//cout << psum[u][i] << " ";
			u = parent[u][i];
		}
	}
	if(u==v){
		//cout << u << "* ";
		return ret;
	}
	
	for(int i = MAXNUM-1; i >= 0; i--){
		if(parent[u][i] != parent[v][i]){
			ret += psum[u][i];
			ret += psum[v][i];
			
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	
	//cout << parent[u][0] << "* ";
	ret += psum[u][0];
	ret += psum[v][0];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N-1; i++){
		cin >> a >> b>> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	bfs();
	setParent();
	
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		cout << getParent(a, b) << "\n";
	}
}