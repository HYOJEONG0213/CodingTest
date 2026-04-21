#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, c[804][804], f[804][804], d[804][804], ret, ret_cnt, a, b, weight;
int dist[804], p[804], S=802, E=803, isIn[804];
vector <int> adj[804];

void bfs(){
	while(1){
		fill(dist, dist+804, -INF);
		memset(p, -1, sizeof(p));
		memset(isIn, 0, sizeof(isIn));
		queue <int> q;
		q.push(S);
		dist[S]=0;
		isIn[S]=true;
		
		while(q.size()){
			int here = q.front(); q.pop();
			isIn[here]=false;
			for(int i : adj[here]){
				int next = dist[here] + d[here][i];
				
				if(c[here][i]-f[here][i]>0 && dist[i] < next){
					p[i] = here;
					dist[i] = next;
					if(isIn[i]==false){
						isIn[i]=true;
						q.push(i);
					}
				}
			}
		}
		
		if(p[E]==-1) break;
		
		int flow = INF;
		for(int here = E; here != S; here = p[here]){
			int pre = p[here];
			flow = min(flow, c[pre][here] - f[pre][here]);
		}
		
		for(int here = E; here != S; here = p[here]){
			int pre = p[here];
			f[pre][here] += flow;
			f[here][pre] -= flow;
			ret += flow * d[pre][here];
		}
		
		ret_cnt += flow;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	
	// S -> 일 -> 사람 -> E  
	for(int i = 1; i <= N; i++){
		cin >> a;
		for(int j = 0; j < a; j++){
			cin >> b >> weight;
			b += 400;
			adj[i].push_back(b);
			adj[b].push_back(i);
			d[b][i] = weight;
			d[i][b] = -weight;
			c[b][i] = 1;
		}
	}
	
	for(int i = 401; i <= M+400; i++){
		c[S][i]=1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	
	for(int i = 1; i <= N; i++){
		c[i][E]=1;
		adj[E].push_back(i);
		adj[i].push_back(E);
	}
	
	bfs();
	
	cout << ret_cnt << "\n";
	cout << ret;
	
}