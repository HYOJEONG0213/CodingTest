#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, ret, visited[104], assigned[104];
vector <int> person[104];

bool f(int idx){
	for(int i : person[idx]){
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
	memset(assigned, -1, sizeof(assigned));
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		a--; b--;
		person[a].push_back(b);
	}
	
	for(int i = 0; i < N; i++){
		memset(visited, 0, sizeof(visited));
		if(f(i)){
			ret++;
		}
	}
	cout << ret;
} 