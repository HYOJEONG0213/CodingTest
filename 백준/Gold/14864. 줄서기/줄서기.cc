#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, v[100004], visited[100004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		v[i] = i;
	}
	
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		v[a]++;
		v[b]--;
	}
	
	
	for(int i = 1; i <= N; i++){
		if(visited[v[i]]== 1) {
			cout << "-1";
			return 0;
		}
		visited[v[i]] = 1;
	}
	
	for(int i = 1; i <= N; i++){
		cout << v[i] <<" ";
	}
	
	
}