#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
struct Dot{
	ll idx, cost, cnt;
	
	bool operator<(const Dot &other) const{
		return cost > other.cost;
	}
};
typedef pair<ll,ll> pp;
ll N, M, K, a, b, c, dp[10004][24];
vector <pp> adj[10004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(&dp[0][0], &dp[0][0]+10004*24, INF);
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
	
	priority_queue <Dot> pq;
	Dot s = {1, 0, 0};
	dp[1][0] = 0;	// 시작점 초기화 반드시!!!  
	pq.push(s);
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		
		if(dp[f.idx][f.cnt] < f.cost) continue;
		
		for(auto i : adj[f.idx]){
			ll nextcost = f.cost + i.first;
			if(dp[i.second][f.cnt] > nextcost){
				dp[i.second][f.cnt] = nextcost;
				Dot t = {i.second, nextcost, f.cnt};
				pq.push(t);
			}
			if(f.cnt+1 <= K){
				if(dp[i.second][f.cnt+1] > f.cost){
					dp[i.second][f.cnt+1] = f.cost;
					Dot t = {i.second, f.cost, f.cnt+1};
					pq.push(t);
				}
			}
		}
	}
	
	ll mn = INF;
	for(auto i : dp[N]){
		mn = min(mn, i);
	}
	cout << mn;
}