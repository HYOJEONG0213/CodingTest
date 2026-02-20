#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, N, M, K, A[1000004], tree[1000004];

void update(ll index, ll value){
	while(index <= N){
		tree[index] += value;
		index += index & -index;
	}
} 

ll sum(ll index){
	ll ret = 0;
	while(index > 0){
		ret += tree[index];
		index -= index & -index;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for(ll i = 1; i <= N; i++){
		cin >> A[i];
		update(i, A[i]);
	}
	for(ll i = 0; i < M + K; i++){
		cin >> a >> b >> c;
		if(a == 1){
			ll temp = c - A[b];
			update(b, temp);
			A[b] = c;
		}
		else{
			cout << sum(c) - sum(b-1) << "\n";
		}
	}	
}