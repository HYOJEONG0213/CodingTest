#include <bits/stdc++.h>
using namespace std;

int n, m, T, a, b, visited[1004], assigned[1004];
vector <int> adj[1004];

bool f(int idx){
	for(int i : adj[idx]){
		if(visited[i]) continue;
		visited[i] = 1;
		
		if(assigned[i]==-1 || f(assigned[i])){
			assigned[i] = idx;
			return true;
		}
	}
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		// 초기화 필요  
		memset(assigned, -1, sizeof(assigned));
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < 1004; i++){
			adj[i].clear();
		}
		int ret = 0;
		
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			adj[a].push_back(b);
		}
		
		for(int i = 0; i < n; i++){
			memset(visited, 0, sizeof(visited));
			if(f(i)){
				ret++;
			}
		}
		
		cout << ret << "\n";
	}
}