#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, ret, assigned[204];
bool visited[204];
vector <int> cow[204];

bool f(int idx){
	for(int box : cow[idx]){
		if(visited[box]) continue;
		visited[box] = true;
		
		if(assigned[box]==-1 || f(assigned[box])){
			assigned[box] = idx;
			return true;
		}
	}
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(assigned, -1, sizeof(assigned));
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> a;
		for(int j = 0; j < a; j++){
			cin >> b;
			cow[i].push_back(b);
		}
	}
	
	for(int i = 0; i < N; i++){
		memset(visited, 0, sizeof(visited));
		if(f(i)){
			ret++;
		}
	}
	
	cout << ret;
}