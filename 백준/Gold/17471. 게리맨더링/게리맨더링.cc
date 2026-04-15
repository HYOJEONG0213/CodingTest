#include <bits/stdc++.h>
using namespace std;

int N, M, cost[14], visited[14], con[14], temp, ret = 987654321;
vector <int> arr[14];

pair <int, int> dfs(int here, int value){
	visited[here] = 1;
	pair <int, int> ret = {1, cost[here]};
	
	for(int there : arr[here]){
		if(visited[there]) continue;
		if(con[there] != value) continue;
		
		pair <int, int> p = dfs(there, value);
		ret.first += p.first;
		ret.second += p.second;
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> cost[i];
	}
	
	for(int i = 1; i<=N; i++){
		cin >> M;
		for(int j = 0; j < M; j++){
			cin >> temp;
			arr[i].push_back(temp);
			//arr[temp].push_back(i);
		}
	}
	
	for(int i = 1; i < (1 << N) - 1; i++){
		int idx1 = -1, idx2 = -1;
		memset(con, 0, sizeof(con));
		memset(visited, 0, sizeof(visited));
		
		for(int j = 0; j < N; j++){
			if(i & (1<<j)){
				con[j + 1] = 1;
				idx1 = j + 1;
			}
			else{
				idx2 = j + 1;
			}
		}
		
		pair <int, int> p1 = dfs(idx1, 1);
		pair <int, int> p2 = dfs(idx2, 0);
		
		if(p1.first + p2.first == N){
			temp = abs(p1.second - p2.second);
			ret = min(ret, temp);
		}
	}
	
	cout << (ret == 987654321 ? -1 : ret);
}