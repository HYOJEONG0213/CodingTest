#include <bits/stdc++.h>
using namespace std;

int N, M, A, B, indegree[32004], dist[32004];
vector <int> adj[32004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> A >> B;
		adj[A].push_back(B);
		indegree[B]++;
	}
	queue <int> q;
	for(int i = 1; i <= N; i++){
		if(indegree[i]==0) q.push(i);
	}
	for(int i = 1; i <= N; i++){
		if(q.empty()) {
			break;
		}
		
		int here = q.front(); q.pop();
		dist[i] = here;
		for(auto j : adj[here]){
			indegree[j]--;
			if(indegree[j] == 0){
				q.push(j); 
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		cout << dist[i] << " ";
	}
	
}