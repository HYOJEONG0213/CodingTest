#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, N, M, K, A[1000004], tree[4000004];


ll init(ll s, ll e, ll index){
	if(s == e) return tree[index] = A[s];
	
	ll mid = (s+e)/2;
	ll l = init(s, mid, index*2);
	ll r = init(mid+1, e, index*2+1);
	
	return tree[index] = l+r;
}

ll sum(ll s, ll e, ll left, ll right, ll index){
	if(e < left || s > right) return 0;
	if(left <= s && right >= e) return tree[index];
	
	
	ll mid = (s+e)/2;
	ll l = sum(s, mid, left, right, index*2);
	ll r = sum(mid+1, e, left, right, index*2+1);
	return l + r;
}

void update(ll s, ll e, ll index, ll target, ll value){
	if(target < s || target > e) return;
	if(s==e) {
		tree[index] += value;
		return;
	}
	tree[index] += value;
	
	ll mid = (s+e)/2;
	update(s, mid, index*2, target, value);
	update(mid+1, e, index*2+1, target, value);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for(ll i = 1; i <= N; i++){
		cin >> A[i];
	}
	init(1, N, 1);
	
	for(ll i = 0; i < M + K; i++){
		cin >> a >> b >> c;
		if(a == 1){
			ll temp = c - A[b];
			A[b] = c;
			update(1, N, 1, b, temp);
		}
		else{
			cout << sum(1, N, b, c, 1) << "\n";
		}
	}	
}