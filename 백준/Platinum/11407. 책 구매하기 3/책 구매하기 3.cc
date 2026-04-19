#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, A[204], c[204][204], f[204][204], d[204][204];
int ret, retcnt, dist[204], S=202, E=203, p[204];
bool isIn[204];
vector <int> adj[204];

void bfs(){
	while(1){
		// 초기화
		memset(isIn, 0, sizeof(isIn));
		memset(p, -1, sizeof(p));
		fill(dist, dist+204, INF);
		 
		queue <int> q;
		q.push(S);
		isIn[S]=true;
		dist[S] = 0;
		
		while(q.size()){
			int here = q.front(); q.pop();
			isIn[here] = false;
			for(int i : adj[here]){
				int next = dist[here] + d[here][i];
				if(dist[i] > next && c[here][i] - f[here][i] > 0){
					dist[i] = next;
					p[i] = here;
					if(isIn[i]==false){
						isIn[i] = true;
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
		
		retcnt += flow;
		ret += flow * dist[E];
		
		for(int here = E; here != S; here = p[here]){
			int pre = p[here];
			f[pre][here]+= flow;
			f[here][pre]-= flow;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	for(int i = 101; i <=M+100; i++){
		cin >> A[i];
	}
	
	// S -> 사람 -> 서점 -> E  
	
	//S -> 사람
	for(int i = 1; i <= N; i++){
		adj[S].push_back(i);
		adj[i].push_back(S);
		c[S][i] = A[i];
	}
	
	// 사람 -> 서점
	for(int i = 101; i <= M+100; i++){
		for(int j = 1; j <= N; j++){
			cin >> c[j][i];
			if(c[j][i]!=0){
				adj[j].push_back(i);
				adj[i].push_back(j);
			}
		}
	}
	
	// 서점 -> E  
	for(int i = 101; i <= M+100; i++){
		adj[i].push_back(E);
		adj[E].push_back(i);
		c[i][E] = A[i];
	}
	
	// 배송비  
	for(int i = 101; i <= M+100; i++){
		for(int j = 1; j <= N; j++){
			cin >> d[j][i];
			d[i][j] = -d[j][i];
		}
	}
	
	bfs();
	
	cout << retcnt << "\n";
	cout << ret;
}