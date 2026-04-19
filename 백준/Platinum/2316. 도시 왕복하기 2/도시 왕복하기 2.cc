#include <bits/stdc++.h>
using namespace std;

#define prev ppp
const int INF = 987654321;
int a, b, N, P, ret, c[804][804], f[804][804], p[804];
vector <int> adj[804];

void bfs(){
	while(1){
		memset(p, -1, sizeof(p));
		
		queue <int> q;
		q.push(1+400);
		while(q.size()){
			int here = q.front(); q.pop();
			for(int i : adj[here]){
				if(c[here][i] - f[here][i] > 0 && p[i]==-1){
					p[i] = here;
					q.push(i);
				}
				if(p[2]!=-1) break;
			}
		}
		
		if(p[2]==-1) break;
		ret++;
		
		for(int here = 2; here != 1+400; here = p[here]){
			int prev = p[here];
			f[prev][here]++;
			f[here][prev]--;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	// ouput : + 400
	
	for(int i = 1; i <= 400; i++){
		adj[i].push_back(i+400);
		adj[i+400].push_back(i);
		if(i==1 || i == 2){
			c[i][i+400] = INF;
		}
		else{
			c[i][i+400] = 1;
		}
	}
	
	for(int i = 0; i < P; i++){
		cin >> a >> b;
		adj[a].push_back(b+400);
		adj[a+400].push_back(b);
		c[a+400][b] ++;
		adj[b].push_back(a+400);
		adj[b+400].push_back(a);
		c[b+400][a] ++;
	}
	
	bfs();
	
	cout << ret;
		
}