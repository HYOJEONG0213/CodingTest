#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e12;
ll N, A, B, M, dist[54], a, b, c, earn[54], visited[54];
vector <pair<ll,ll>> adj[54];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> A >> B >> M;
	fill(dist, dist+54, -INF);
	for(int i = 0 ; i < M; i++){
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	for(int i = 0; i < N; i++){
		cin >> earn[i];
	}
	
	dist[A]=earn[A];
	queue <ll> q;
	for(int i = 0; i < N; i++){
		for(int here = 0; here < N; here++){
			ll hereCost = dist[here];
			if(hereCost==-INF) continue;
			//cout << here << "\n";
			for(auto j : adj[here]){
				ll v = j.first;
				ll weight = j.second;
				ll next = hereCost - weight + earn[v];
				if(dist[v] < next){
					if(i==N-1){
						q.push(v);
					}
					dist[v] = next;
				}
			}
		}
	}
	
	if(dist[B]==-INF){
		cout << "gg";
		return 0;
	}
	
	
	while(q.size()){
		ll f = q.front(); q.pop();
		if(f == B){
			cout << "Gee";
			return 0;
		}
		for(auto i : adj[f]){
			int v = i.first;
			if(visited[v]==1) continue;
			visited[v] = 1;
			q.push(v);
		}
	}
	
	
	cout << dist[B];

	
	
}