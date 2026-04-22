#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
struct Edge{
	int u, value, cnt;
	
	bool operator< (const Edge &other) const{
		if(value == other.value) return cnt > other.cnt;
		return value > other.value;
	}
};
const int INF = 987654321;
//dist[정점][지금까지정점수]=최소비용  
int N, M, S, E, a, b, w, d[1004][1004], dist[1004][1004], K, p, ret=INF, cnt;
vector <pp> adj[1004];

void bfs(){
	// 최단경로 구하기
	fill(&dist[0][0], &dist[0][0]+1004*1004, INF);
	priority_queue <Edge> pq;
	Edge edge = {S, 0, 0};
	pq.push(edge);
	dist[S][0]=0;
	
	while(pq.size()){
		Edge e = pq.top(); pq.pop();
		if(dist[e.u][e.cnt] < e.value) continue;
		if(e.cnt >= N-1) continue;
		bool flag = false;
		for(int i = 0; i < e.cnt; i++){
			if(dist[e.u][i] <= e.value){
				flag = true;
				break;
			}
		}
		if(flag) continue;
		
		for(auto i : adj[e.u]){
			int next = i.first;
			int nextvalue = e.value + i.second;
			if(dist[next][e.cnt+1] > nextvalue){
				dist[next][e.cnt+1] = nextvalue;
				pq.push({next, nextvalue, e.cnt+1});
			}
		}
	}
	
	for(int i=1; i < 1004; i++){
		if(ret > dist[E][i]){
			cnt = i;
			ret = dist[E][i];
		}
	}
	
	cout << ret << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	cin >> S >> E;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
		d[a][b] = w;
		d[b][a] = w;
	}
	bfs();
	
	int total = 0;
	for(int i = 0; i < K; i++){
		cin >> p;
		total += p;
		
		int mn = INF;
		int minEdge = cnt;
		for(int j = 0; j <= cnt; j++){
			if(dist[E][j]==INF) continue;
			int temp = dist[E][j] + (j * total);
			if(mn > temp){
				mn = temp;
				minEdge = j;
			}
		}
		
		cnt = minEdge;
		cout << mn << "\n";
	}
}