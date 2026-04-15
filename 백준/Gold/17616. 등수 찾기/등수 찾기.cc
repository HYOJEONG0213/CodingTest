#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
typedef pair<int,int> pp;
int N, M, X, a, b, dist1[100004], dist2[100004];
vector <int> adj[100004], radj[100004];

void dij(vector <int> *ad, int * dist){
	priority_queue <pp, vector<pp>, greater<pp>> pq;
	pq.push({1, X});
	dist[X] = 1;
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		int cost = f.first;
		int u = f.second;
		if(dist[u] != cost) continue;
		
		for(int v : ad[u]){
			int next = cost + 1;
			if(dist[v] < next){
				dist[v] = next;
				pq.push({next, v});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;
	fill(dist1, dist1+100004, -INF);
	fill(dist2, dist2+100004, -INF);
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	
	//dist1 : 내 뒤에 최소 몇개있는가
	//dist2 : 내 앞에 최소 몇개있는가  
	dij(adj, dist1);
	dij(radj, dist2);
	
	
	
	int cnt = 0;
	int mx1 = 0;
	int mx2 = 0; 
	for(int i = 1; i <= N; i++){
		//cout << dist2[i] << " ";
		dist1[i]!=-INF ? mx1++ : 0;
		dist2[i]!=-INF ? mx2++ : 0;
		
		//몰?루
		if(dist1[i] == -INF && dist2[i] == -INF){
			cnt++;
		} 
	}
	
	cout << mx2 << " " << mx2 + cnt;
}