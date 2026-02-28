#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, M, K, a, b, c, d;
vector <ll> tree1, tree2;

void update(vector <ll> &tree, ll idx, ll value){
	while(idx <= N){
		tree[idx] += value;
		idx += idx&-idx;
	}
}

void range_update(ll left, ll right, ll value){
	update(tree1, left, value);
	update(tree1, right+1, -value);
	
	update(tree2, left, value * left);
	update(tree2, right+1, -value * (right+1));
}

ll _sum(vector <ll> &tree, ll idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= idx&-idx;
	}
	return ret;
}

ll sum(ll x){
	return _sum(tree1, x) * (x+1) - _sum(tree2, x);
}

ll range_sum(ll left, ll right){
	return sum(right) - sum(left-1);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	tree1.resize(1000004);
	tree2.resize(1000004);
	for(int i = 1; i <= N; i++){
		cin >> a;
		range_update(i, i, a);
	}
	
	for(int i = 0; i < M+K; i++){
		cin >> a;
		if(a ==1){
			cin >> b >> c >> d;
			range_update(b, c, d);
		}
		else{
			cin >> b >> c;
			cout << range_sum(b, c) << "\n";
		}
	}
}