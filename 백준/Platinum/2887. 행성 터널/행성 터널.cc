#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tt;
const ll INF = 9876543219;
ll N, ret, level[100004], p[100004];
vector <tt> tree;

struct Edge{
	int x, y, z, id;
};
vector <Edge> edge;

ll find(ll x){
	if(p[x]==-1) return x;
	return p[x] = find(p[x]);
}

void merge(ll x, ll y){
	x = find(x), y = find(y);
	if(x==y) return;
	if(level[x] < level[y]){
		p[x] = y;
	}
	else{
		if(level[x]==level[y]){
			level[x]++;
		}
		p[y] = x;
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> N;
	for(int i = 0; i < N; i++){
		Edge temp;
		cin >> temp.x >> temp.y >> temp.z;
		temp.id = i;
		edge.push_back(temp);
	}
	
	sort(edge.begin(), edge.end(),
	[](const Edge & a, const Edge & b){
		return a.x < b.x;
	});
	for(int i = 0; i < N-1; i++){
		ll x = abs(edge[i+1].x - edge[i].x);
		tree.push_back(make_tuple(x, edge[i].id, edge[i+1].id));
	}
	
	sort(edge.begin(), edge.end(), 
	[](const Edge & a, const Edge & b){
		return a.y < b.y;
	});
	for(int i = 0; i < N-1; i++){
		ll y = abs(edge[i+1].y - edge[i].y); 
		tree.push_back(make_tuple(y, edge[i].id, edge[i+1].id));
	}
	
	sort(edge.begin(), edge.end(), 
	[](const Edge & a, const Edge & b){
		return a.z < b.z;
	});
	for(int i = 0; i < N-1; i++){
		ll z = abs(edge[i+1].z - edge[i].z); 
		tree.push_back(make_tuple(z, edge[i].id, edge[i+1].id));
	}
	
	sort(tree.begin(), tree.end());
	
	int cnt = 0;
	for(int i = 0; i < tree.size(); i++){
		ll dir, idx1, idx2;
		tie(dir, idx1, idx2) = tree[i];
		idx1 = find(idx1);
		idx2 = find(idx2);
		
		if(idx1 == idx2) continue;
		merge(idx1, idx2);
		ret += dir;
		cnt++;
		
		if(cnt == N-1) break;
	}
	
	cout << ret;
}