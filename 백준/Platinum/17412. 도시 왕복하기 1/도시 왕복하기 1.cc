#include <bits/stdc++.h>
using namespace std;

#define prev ppp 
int N, P, a, b, ret, c[404][404], f[404][404];
vector <int> adj[404];

void bfs(){
	while(1){
		// 경로추적 초기화
		int p[404];
		memset(p, -1, sizeof(p)); 
		
		queue <int> q;
		q.push(1);	
		
		// 정방향 탐색
		while(q.size()){
			int here = q.front(); q.pop();
			for(int next : adj[here]){
				if(c[here][next] - f[here][next] > 0 && p[next]==-1){
					q.push(next);
					p[next] = here;
					
					if(next==2) break;
				}
			}
		}
		
		// 경로 못찾았다면 ㅈㅈㅈ  
		if(p[2]==-1) break;
		
		// 역방향 탐색  
		for(int here = 2; here != 1; here = p[here]){
			int prev = p[here];
			f[prev][here]++;
			f[here][prev]--; 
		}
		
		ret++;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	for(int i = 0; i < P; i++){
		cin >> a >> b;
		c[a][b] = 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	bfs();
	
	cout << ret;
}