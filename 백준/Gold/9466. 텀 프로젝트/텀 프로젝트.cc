#include <bits/stdc++.h>
using namespace std;

int T, N, A[100004], p[100004], level[100004];

int find(int x){
	if(p[x]==-1){
		return x;
	}
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(level[x]<level[y]){
		p[x] = y;
	}
	else{
		if(level[x]==level[y])
			level[x]++;
		p[y] = x;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--){
		memset(p, -1, sizeof(p));
		memset(level, 0, sizeof(level));
		int ret = 0;
		
		cin >> N;
		for(int i = 1; i <= N; i++){
			cin >> A[i];
		}
		for(int i = 1; i <= N; i++){
			if(find(i)==find(A[i])){
				int curr = A[i];
				int cnt = 0;
				
				while(curr != i){
					cnt++;
					curr = A[curr];
				}
				cnt++;
				ret += cnt;
			}
			else{
				merge(i, A[i]);
			}
		}
		
		cout << N - ret << "\n";
	}
}