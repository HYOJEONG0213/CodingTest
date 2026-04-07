#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int N, M, K, c[30004], visited[30004], p[30004], level[30004], a, b;
int dp[30004];
pp psum[30004];
vector <pp> v;

int find(int x){
	if(p[x]==-1) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x==y) return;
	
	if(level[x] < level[y]){
		p[x] = y;
	}
	else{
		if(level[x]==level[y]){
			level[y]++;
		}
		p[y] = x;
	}
}

void f(){
	for(int i = 0; i < v.size(); i++){
		int k, cnt;
		tie(k, cnt) = v[i];
		
		for(int j = K-1; j >= k; j--){
			dp[j] = max(dp[j], dp[j-k] + cnt);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++){
		cin >> c[i];
	}
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		merge(a, b);
	}
	for(int i = 1; i <= N; i++){
		int idx = find(i);
		psum[idx].first++;
		psum[idx].second += c[i];
	}
	for(int i = 1; i <= N; i++){
		int idx = find(i);
		if(visited[idx]==1) continue;
		visited[idx] = 1;
		v.push_back(psum[idx]);
	}
	
	f();
	cout << dp[K-1];
}