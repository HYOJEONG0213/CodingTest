#include <bits/stdc++.h>
using namespace std;

int N, a, b, c, assigned[54], visited[54], ret;
struct Shark{
	int a, b, c;
};

Shark shark[54];

vector <int> v[54];

int comp(Shark &a, Shark &b){
	if(a.a == b.a && a.b == b.b && a.c == b.c) return 2;
	if(a.a <= b.a && a.b <= b.b && a.c <= b.c) return 1;
	else if(a.a >= b.a && a.b >= b.b && a.c >= b.c) return -1;

	return 0;
}

bool f(int idx){
	for(int i : v[idx]){
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
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b >> c;
		shark[i] = {a, b, c};
	}
	
	// v[i] = j : i번째 상어는 j 상어를 먹을 수 있다!  
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			int temp = comp(shark[i], shark[j]);
			//if(i==1 && j == 4) cout << temp <<"*\n";
			if(temp==1){
				v[j].push_back(i);
			}
			else if(temp==-1){
				v[i].push_back(j);
			}
			else if(temp==2){
				v[i].push_back(j);
			}
		}
	}
	
//	for(int i = 0; i < N; i++){
//		for(auto j : v[i]){
//			cout << j << " ";
//		} 
//		cout << "\n";
//	}
	
	for(int i = 0; i < N; i++){
		// 최대 2마리까지 먹을 수 있음  
		for(int j = 0; j < 2; j++){
			memset(visited, 0, sizeof(visited));
			if(f(i)){
				ret++;
			}
		}
	}
	
	if(ret == N) cout << 1;
	else cout << N - ret;
}