#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, S, D, U, V, P, dict[504], adj[504][504];

void dij(){
	fill(dict, dict+504, INF);
	priority_queue <pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>>> pq;

	dict[S] = 0;
	pq.push({0, S});
	while(pq.size()){
		int u = pq.top().second;
		int hereCost = pq.top().first;
		pq.pop();
		if(dict[u]!=hereCost) continue;
		
		for(int i = 0; i < N; i++){
			if(adj[u][i] == -1) continue;
			
			int nextCost = hereCost + adj[u][i];
			
			if(dict[i] > nextCost){
				dict[i] = nextCost;
				pq.push({nextCost, i});
			}
		}
	}
	
}

void remove(){
	queue <int> q;
	//마지막에서 추적해야 중간에 딴길로 안새겠지  
	q.push(D);
	
	while(q.size()){
		int u = q.front(); q.pop();
		
		for(int i = 0; i < N; i++){
			if(adj[i][u]==-1) continue;
			
			if(dict[u] == dict[i]+adj[i][u]){
				adj[i][u] = -1;
				q.push(i);
			}
			
			
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while(1){
		memset(adj, -1, sizeof(adj));
		
		
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		
		cin >> S >> D;
		for(int i = 0; i < M ; i++){
			cin >> U >> V >> P;
			adj[U][V] = P;
		}
		
		dij();
		
		remove();
		dij();
	
	
		cout << (dict[D] == INF ? -1 : dict[D]) << "\n";
	}
}