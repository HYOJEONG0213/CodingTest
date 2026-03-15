#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
typedef tuple<int,int,int> tt;
const int INF = 987654321;
const int MAXNUM = 18;

int N, a, b, c, d, e, K, visited[100004];
int mx[100004][MAXNUM], mn[100004][MAXNUM], parent[100004][MAXNUM];
vector <pp> adj[100004]; 

void bfs(){
	queue <int> q;
	q.push(1);
	visited[1] = 1;
	
	while(q.size()){
		int here = q.front(); q.pop();
		
		for(auto i : adj[here]){
			int next = i.first, nextCost = i.second;
			if(visited[next]) continue;
			visited[next] = visited[here]+1;
			parent[next][0] = here;
			mx[next][0] = nextCost;
			mn[next][0] = nextCost;
			q.push(next);
		}
	}
}

void setParent(){
	for(int j = 1; j < MAXNUM; j++){
		for(int i = 1; i <= N; i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
			mx[i][j] = max(mx[parent[i][j-1]][j-1], mx[i][j-1]);
			mn[i][j] = min(mn[parent[i][j-1]][j-1], mn[i][j-1]);
		}
	}
}

pp getParent(int u, int v){
	int retMax = 0, retMin = INF;
	
	if(visited[u] > visited[v]) swap(u, v);
	for(int i = MAXNUM-1; i >= 0; i--){
		if(visited[v]-visited[u] >= 1<<i){
			retMax = max(retMax, mx[v][i]);
			retMin = min(retMin, mn[v][i]);
			v = parent[v][i];
		}
		
		if(visited[u]==visited[v]) break;
	}
	if(u==v) return make_pair(retMin, retMax);
	
	for(int i = MAXNUM-1; i >= 0; i--){
		if(parent[u][i] != parent[v][i]){
			retMax = max({retMax, mx[u][i], mx[v][i]});
			retMin = min({retMin, mn[u][i], mn[v][i]});
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	
	retMax = max({retMax, mx[u][0], mx[v][0]});
	retMin = min({retMin, mn[u][0], mn[v][0]});
	
	
	return make_pair(retMin, retMax);
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(&mn[0][0], &mn[0][0]+100004*MAXNUM, INF);
	
	cin >> N;
	for(int i = 0; i < N-1; i++){
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	bfs();
	setParent();
	
	cin >> K;
	for(int i = 0 ; i < K; i++){
		cin >> d >> e;
		pp temp = getParent(d, e);
		cout << temp.first << " " << temp.second << "\n";
	}
}