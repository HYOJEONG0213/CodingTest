#include <bits/stdc++.h>
using namespace std;

int N, M, k, A[10004], p[10004], visited[10004], level[10004] , v, w, ret;

int find(int x){
	if(p[x] == x) return x;
	return x = find(p[x]);
}

void merge(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return;
	if(A[x] > A[y]){
		p[x] = y;
	}
	else{
		p[y] = x;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> k;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		p[i] = i;
	}
	for(int i = 0; i < M; i++){
		cin >> v >> w;
		merge(v, w);
	}
	for(int i = 1; i <= N; i++){
		int x = find(i);
		if(visited[x]==1) continue;
		ret += A[x];
		visited[x] = 1;
	}
	if(ret > k){
		cout << "Oh no";
	}
	else{
		cout << ret;
	}
}