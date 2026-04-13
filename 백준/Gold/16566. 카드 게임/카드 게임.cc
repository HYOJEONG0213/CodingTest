#include <bits/stdc++.h>
using namespace std;

int N, M, K, a, p[4000004];
vector <int> pick;

int find(int x){
	if(p[x]==-1) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x==y) return;
	
	p[x] = y;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++){
		cin >> a;
		pick.push_back(a);
	}
	sort(pick.begin(), pick.end());
	
	for(int i = 0; i < K; i++){
		cin >> a;
		auto iter = upper_bound(pick.begin(), pick.end(), a) - pick.begin();
		int idx = find(iter);
		cout << pick[idx] << "\n";
		merge(idx, idx+1);
	}
}