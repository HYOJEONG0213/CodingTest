#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, M, a, b, c, d, A[100004], tree1[100004], tree2[100004];

void update(ll *tree, ll index, ll value){
	while(index <= N){
		tree[index] += value;
		index += index&-index;
	}
}

ll sum(ll *tree, ll index){
	ll ret = 0;
	while(index > 0){
		ret += tree[index];
		index -= index&-index;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(ll i = 1; i <= N; i++){
		cin >> A[i];
		update(tree1, i, A[i]);
	}
	cin >> M;
	for(ll i = 1; i <= M; i++){
		cin >> a;
		if(a==1){
			cin >> b >> c >> d;
			update(tree2, b, d);
			update(tree2, c+1, -d);
		}
		else{
			cin >> b;
			ll temp1 = sum(tree1, b) - sum(tree1, b-1);
			ll temp2 = sum(tree2, b);
			cout << temp1+temp2 << "\n";
		}
	}
}