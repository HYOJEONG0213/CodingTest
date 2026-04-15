#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
typedef tuple <int,int,int> tt;
int V, E, A, B, C, ret, p[10004], _rank[10004];
vector <tt> adj;

int find(int x){
	if(p[x] == -1) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return ;
	if(_rank[a] < _rank[b]){
		p[a] = b;
		return;
	}
	else{
		p[b] = a;
		if(_rank[a] == _rank[b]){
			_rank[a]++;
		}
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> V >> E;
	for(int i = 0; i < E; i++){
		cin >> A >> B >> C;
		adj.push_back(make_tuple(C, A, B));
	}
	sort(adj.begin(), adj.end());
	
	int cnt = 0;
	for(int i = 0; i < adj.size(); i++){
		int w, a, b;
		tie(w, a, b) = adj[i];
		if(find(a) == find(b)) continue;
		ret += w;
		cnt++;
		merge(a, b);
		
		if(cnt == V-1) break;
	}
	
	
	cout << ret;
}