#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, visited[1004], ret, assigned[1004];
vector <int> people[1004];

bool f(int person){
	for(int work : people[person]){
		if(visited[work]) continue;
		visited[work] = 1;
		
		if(assigned[work]==-1 || f(assigned[work])){
			assigned[work] = person;
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
			//works[b].push_back(i);
			people[i].push_back(b);
		}
	}
	
	for(int i = 0; i < N; i++){
		memset(visited, 0, sizeof(visited));
		if(f(i)==true) ret++;
	}
	
	cout << ret;
}