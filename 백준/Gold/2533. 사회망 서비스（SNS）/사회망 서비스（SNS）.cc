#include <bits/stdc++.h>
using namespace std;

#define prev ppp
const int INF = 987654321;
int N, u, v, dp[1000004][2];
vector <int> adj[1000004];


int go(int idx, int prev, int flag){
	int &ret = dp[idx][flag];
	if(ret != -1) return ret;
	
	// 부모가 얼리니 자식은  
	if(flag == 1){
		ret = 1;
		for(auto i : adj[idx]){
			if(i == prev) continue;
			ret += min(go(i, idx, 0), go(i, idx, 1));
		} 
	}
	// 자식은 꼭 얼리 
	else{
		ret = 0;
		for(auto i : adj[idx]){
			if(i == prev) continue;
			ret += go(i, idx, 1);
		}
	}
	
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i = 0; i < N-1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cout << min(go(1, 0, 0), go(1, 0, 1));
}