#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int N, M, a, b, ret, visited[1004], assigned[1004];
vector <int> person[1004];

bool f(int idx){
	for(auto work : person[idx]){
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
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> a;
		for(int j = 0; j < a; j++){
			cin >> b;
			person[i].push_back(b);
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 2; j ++){
			memset(visited, 0, sizeof(visited));
			if(f(i)){
				ret++; 
			}
		}
	}
	
	cout << ret;
}