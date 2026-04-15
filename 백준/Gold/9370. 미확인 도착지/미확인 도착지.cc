#include <bits/stdc++.h>
using namespace std;

const int INF = 987654322;
typedef pair<int,int> ppp;
int T, n, m, t, s, g, h, a, b, d;

void dij(int *dist, int start, vector <ppp> *adj){
	dist[start] = 0;
	priority_queue <ppp, vector <ppp>, greater <ppp> > pq;
	pq.push({0, start});
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		int u = f.second;
		int cost = f.first;
		if(dist[u] != cost) continue;
		
		for(auto i : adj[u]){
			int v = i.second;
			int weight = i.first;
			int next = cost + weight;
			if(dist[v] > next){
				dist[v] = next;
				pq.push({next, v});
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		//초기화 필요함!!	
		vector <ppp> adj[2004];
		int dist1[2004];
		fill(dist1, dist1+2004, INF); 
		vector <int> x;
		vector <int> ret; 
		
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for(int i = 0; i < m; i++){
			cin >> a >> b >> d;
			d*=2;
			if((a == g && b == h) || (a == h && b == g)) d--;
			adj[a].push_back({d, b});
			adj[b].push_back({d, a});
		}
		for(int i = 0; i < t; i++){
			cin >> a;
			x.push_back(a);
		}
		sort(x.begin(), x.end());
		
		dij(dist1, s, adj);
        
		for(int i = 0; i < x.size(); i++){
			if(dist1[x[i]] % 2 == 1){
				cout << x[i] << " ";
			}
		}
		
		cout << "\n";
	}
	

}