#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
const int INF = 987654321;
int TC, N, M, W, S, E, T, dist[504];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> TC;
	while(TC--){
		vector <pp> adj[504];
		
		
		cin >> N >> M >> W;
		for(int i = 0; i < M; i++){
			cin >> S >> E >> T;
			adj[S].push_back({E, T});
			adj[E].push_back({S, T});
		}
		for(int i = 0; i < W; i++){
			cin >> S >> E >> T;
			adj[S].push_back({E, -T});
		}
		
		bool flag = false;
		
		fill(dist, dist+504, INF);
		for(int cnt = 1; cnt <= N; cnt++){
			if(dist[cnt] != INF) continue;
			dist[cnt] = 0;
			for(int i = 0; i < N; i++){
				for(int here = 1; here <= N; here++){
					if(dist[here]==INF) continue;
					
					for(auto j : adj[here]){
						int v = j.first, cost = j.second;
						int next = cost + dist[here];
						if(dist[v] > next){
							if(i == N-1){
								flag = true;
								break;
							}
							else{
								dist[v] = next;
							}
						}
					}
					if(flag == true) break;
				}	
				if(flag == true) break;
			}
		}
		
		if(flag == true){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}