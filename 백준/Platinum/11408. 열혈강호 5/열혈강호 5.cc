#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, a, b, weight, c[804][804], f[804][804], d[804][804];
int S=801, E=802, visited[804];
int p[804], dist[804], ret, retcnt;
vector <int> adj[804];

void bfs(){
	while(1){
		memset(p, -1, sizeof(p));
		memset(visited, 0, sizeof(visited));
		fill(dist, dist+804, INF);
		queue <int> q;
		
		q.push(S);
		visited[S] = 1;
		dist[S] = 0;
		
		while(q.size()){
			int here = q.front(); q.pop();
			visited[here] = 0;
			int herecost = dist[here];
			
			for(int i : adj[here]){
				int next = herecost + d[here][i];
				if(dist[i] > next && c[here][i] - f[here][i] > 0){
					p[i] = here;
					dist[i] = next;
					
					// 큐에 들어있지 않다면  
					if(visited[i]==0){
						visited[i] = 1;
						q.push(i);
					}
				}
			} 
		}
		
		if(p[E]==-1) break;
		retcnt++;
		ret += dist[E]; 
		
		for(int here = E; here != S; here = p[here]){
			int pre = p[here];
			f[pre][here]++;
			f[here][pre]--;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		adj[S].push_back(i);
		adj[i].push_back(S);
		c[S][i] = 1;
		
		cin >> a ;
		for(int j = 0; j < a; j++){
			cin >> b >> weight;
			int workNum = b + 400;
			
			d[i][workNum] = weight;
			d[workNum][i] = -weight;
			
			// S -> 사람 -> 일 -> E  
			
			adj[i].push_back(workNum);
			adj[workNum].push_back(i);
			c[i][workNum]=1;
		}
	}
	
	for(int i = 1; i <= M; i++){
		int workNum = i + 400;
		adj[workNum].push_back(E);
		adj[E].push_back(workNum);
		c[workNum][E] = 1;
	}
	
	bfs();
	
	cout << retcnt << "\n";
	cout << ret;
}