#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, M, A[1000004], a, b, c;
ll tree[1000004];

void update(int index, int value){
	while(index <= N){
		tree[index] += value;
		index += index & -index;
	}
}

ll sum(int index){
	ll ret = 0;
	while(index > 0){
		ret += tree[index];
		index -= index & -index;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0 ; i < M; i++){
		cin >> a >> b >> c;
		
		if(a == 0){
			if(b > c) swap(b, c);
			cout << sum(c) - sum(b-1) << "\n";
		}
		else{
			int temp = c - A[b];
			update(b, temp);
			A[b] = c;
		}
	}
}