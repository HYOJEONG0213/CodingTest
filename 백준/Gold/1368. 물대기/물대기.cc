#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int s, e, dir;
	
	bool operator<(const Edge &other) const{
		return dir < other.dir;
	}
};

int N, W[304], a, b, p[304], level[304], ret, visited[304];
vector <Edge> v;

int find(int x){
	if(p[x]==-1) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x); y = find(y);
	if(x==y) return;
	if(W[x]<W[y]){
		p[y] = x;
	}
	else{
		p[x] = y;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> W[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			Edge edge;
			edge.s = i, edge.e = j;
			cin >> edge.dir;
			v.push_back(edge);
		}
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++){
		int s = v[i].s, e = v[i].e, dir = v[i].dir;
		s = find(s);
		e = find(e);
		if(s==e) continue;
		if(dir > max(W[s], W[e])) continue;
		
		//cout << dir << " ";
		ret += dir;
		merge(s, e);
	}
	
	for(int i = 0; i < N; i++){
		int num = i;
		num = find(num);
		if(visited[num]==1) continue;
		//cout << "\n "<< W[i] << " ";
		ret += W[num];
		visited[num] = 1;
	}
	
	cout << ret;
}