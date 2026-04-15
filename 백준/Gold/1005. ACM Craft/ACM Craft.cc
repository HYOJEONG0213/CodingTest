#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pp;
const int INF = 987654321;
int T, N, K, W, X, Y, dist[1004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		int indegree[1004];
		int D[1004];
		vector <pp> adj[1004];
		memset(indegree, 0, sizeof(indegree));
		memset(D, 0, sizeof(D));
		fill(dist, dist+1004, -INF);
		
		cin >> N >> K;
		for(int i = 1; i <= N; i++){
			cin >> D[i];
		}
		for(int i = 1; i <= K; i++){
			cin >> X >> Y;
			adj[X].push_back({D[Y], Y});
			indegree[Y]++;
		}
		cin >> W;
		
		queue <int> q;
		for(int i = 1; i <= N; i++){
			if(indegree[i]==0) {
				q.push(i);
				dist[i] = D[i];
			}
		}
		
		for(int i = 1; i <= N; i++){
			if(q.size()==0){
				cout << "사이클 존재";
				return 0;
			}
			
			int here = q.front(); q.pop();
			int cost = dist[here];
			
			if(here == W) break;
			
			for(auto j : adj[here]){
				int v = j.second;
				int weight = j.first;
				int next = cost + weight;
				indegree[v]--;
				if(indegree[v]==0) q.push(v);
				
				dist[v] = max(dist[v], next);
			} 
		}
		
		cout << dist[W] << "\n";
	}
}