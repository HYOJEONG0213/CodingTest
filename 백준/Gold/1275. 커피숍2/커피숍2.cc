#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, Q, A[100004], x, y, a, b, tree[100004];

void update(ll index, ll value){
	while(index <= N){
		tree[index] += value;
		index += index&-index;
	}
}

ll sum(ll index){
	ll ret = 0;
	while(index > 0){
		ret += tree[index];
		index -= index&-index;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		update(i, A[i]);
	}
	for(int i = 0; i < Q; i++){
		cin >> x >> y >> a >> b ;
		if(x > y) swap(x, y);
		cout << sum(y) - sum(x-1) << "\n";
		update(a, b-A[a]);
		A[a] = b;
	}
}