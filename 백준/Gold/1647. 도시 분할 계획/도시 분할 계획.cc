#include <bits/stdc++.h>
using namespace std;

int N, M, p[100004], level[100004], A, B, C, ret;

struct adj{
	int A, B;
	int cost;
	
	bool operator<(const adj &other) const{
		return cost < other.cost;
	}
};

vector <adj> v;

int find(int x){
	if(p[x]==-1) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x); y = find(y);
	if(x==y) return;
	
	if(level[x] < level[y])
		p[x] = y;
	else{
		p[y] = x;
		if(level[x]==level[y])
			level[x]++;
	}
	
		
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> A >> B >> C;
		
		v.push_back({A, B, C});
	}
	
	sort(v.begin(), v.end());
	int num = 0;
	for(int i = 0; i < M; i++){
		A = find(v[i].A); 
		B = find(v[i].B);
		int cost = v[i].cost;
		 
		if(A == B) continue;
		ret += cost;
		merge(A, B);
		num++;
		
		if(num == N-1) {
			ret -= cost;
			break;
		}
	}
	
	cout << ret;
}