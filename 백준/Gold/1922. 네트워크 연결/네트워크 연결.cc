#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c, ret, p[1004], level[1004];

struct Edge{
	int cost, a, b;
	
	bool operator<(const Edge &other) const{
		return cost < other.cost;
	}
};
vector <Edge> edges;

int find(int x){
	if(p[x]==-1) return x;
	return p[x] = find(p[x]);
}

bool merge(int x, int y){
	x = find(x); y = find(y);
	if(x==y) return false;
	
	if(level[x] < level[y]){
		p[x] = y;
	}
	else{
		p[y] = x;
		if(level[x]==level[y])	
			level[x]++;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> N;
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end());
	int edge_count = 0;
	
	for(const auto & edge : edges){
		if(merge(edge.a, edge.b)){
			ret += edge.cost;
			edge_count++;
		}
		
		if(edge_count == N-1) break;
	}
	
	cout << ret;
}