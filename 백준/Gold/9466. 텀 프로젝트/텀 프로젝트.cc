#include <bits/stdc++.h>
using namespace std;

int T, N, A[100004], visited[100004], done[100004], ret;

void dfs(int here){
	visited[here] = 1;
	int next = A[here];
	
	if(visited[next]==0){
		dfs(next);
	}
	else{
		if(done[next]==0){
			for(int i = next; i != here; i = A[i]){
				ret++;
			}
			ret++;
		}
	}
	
	done[here] = 1;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		memset(visited, 0, sizeof(visited));
		memset(done, 0, sizeof(done));
		ret = 0;
		
		cin >> N;
		for(int i = 1; i <= N; i++){
			cin >> A[i];
		}
		for(int i = 1; i <= N; i++){
			if(visited[i]==1) continue;
			dfs(i);
		}
		
		cout << N - ret << "\n";
	}
}