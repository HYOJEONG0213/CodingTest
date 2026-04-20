#include "bits/stdc++.h"
using namespace std;

const int INF = 987654321;
int N, M, A[204], S=202, E=203;
int c[204][204], f[204][204], ret, p[204];
vector <int> adj[204];

void bfs(){
	while(1){
		// 초기화
		memset(p, -1, sizeof(p));
		
		 queue <int> q;
		 q.push(S);
		 p[S] = S;
		 while(q.size()){
		 	int here = q.front(); q.pop();
			for(int i : adj[here]){
		 		if(c[here][i] - f[here][i] > 0 && p[i]==-1){
		 			p[i] = here;
		 			q.push(i);
				 }
				 if(p[E]!=-1) break;
			 }
			 if(p[E]!=-1) break;
		 }
		 
		 if(p[E]==-1) break;
		 
		 int minflow = INF;
		 for(int here=E; here != S; here = p[here]){
		 	int pre = p[here];
			 minflow = min(minflow, c[pre][here] - f[pre][here]);
		 }
		 
		 ret+=minflow;
		 for(int here=E; here != S; here = p[here]){
		 	int pre = p[here];
		 	f[pre][here]+=minflow;
		 	f[here][pre]-=minflow;
		 }
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	// S -> 서점 -> 사람 -> E
	
	// 사람->E 
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		adj[i].push_back(E);
		adj[E].push_back(i);
		c[i][E]=A[i];
	}
	// S->서점 
	for(int i = 101; i <= M+100; i++){
		cin >> A[i];
		adj[i].push_back(S);
		adj[S].push_back(i);
		c[S][i]=A[i];
	}
	// 서점->사람 
	for(int i = 101; i <= M+100; i++){
		for(int j = 1; j <= N; j++){
			cin >> c[i][j];
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	
	bfs();
	
	cout << ret;
}