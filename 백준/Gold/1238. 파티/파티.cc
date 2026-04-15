#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, X, a, b, c, ret[1004];

void dij(int * dict, vector <pair<int,int>> *adj){
	priority_queue <pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>> > pq;
	dict[X] = 0;
	pq.push({0, X});
	
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		int u = f.second;
		int cost = f.first;
		if(dict[u] != cost) continue;
		
		for(auto j : adj[u]){
			int v = j.second;
			int weight = j.first;
			int next = cost + weight;
			if(dict[v] > next){
				dict[v] = next;
				pq.push({next, v});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int dict1[1004], dict2[1004];
	vector <pair<int,int>> adj[1004], radj[1004];
	fill(dict1, dict1+1004, INF);
	fill(dict2, dict2+1004, INF);
	
	cin >> N >> M >> X;
	for(int i = 0 ; i < M; i++){
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		radj[b].push_back({c, a});
	}
	dij(dict1, adj);
	dij(dict2, radj);
	for(int i = 1; i <= N; i++){
		ret[i] = dict1[i] + dict2[i];
		//cout << ret[i] << " ";
	}
	
	cout << *max_element(ret, ret+1004);
	
}