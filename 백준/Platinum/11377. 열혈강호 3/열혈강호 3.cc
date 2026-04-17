#include <bits/stdc++.h>
using namespace std;

int N, M, K, a, b, visited[1004], assigned[1004], ret;
vector <int> person[1004];

bool f(int idx){
	for(int work : person[idx]){
		if(visited[work]) continue;
		visited[work] = 1;
		
		if(assigned[work]==-1 || f(assigned[work])){
			assigned[work] = idx;
			return true;
		}
	}
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(assigned, -1, sizeof(assigned));
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++){
		cin >> a;
		for(int j = 0; j < a; j++){
			cin >> b;
			person[i].push_back(b);
		}
	}
	
	for(int i = 0; i < N; i++){
		memset(visited, 0, sizeof(visited));
		if(f(i)){
			ret++;
		}
	}
	int cnt = 0;
	for(int i = 0; i < N; i++){
		memset(visited, 0, sizeof(visited));
		if(f(i)){
			ret++;
			cnt++;
		}
		if(cnt >= K) break;
	}
	
	cout << ret;
}