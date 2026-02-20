#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll N, M, K, a,b,c, A[1000004], tree[1000004*4];


ll init(ll s, ll e, ll index){
	if(s == e) return tree[index] = A[s];
	
	ll mid = (s+e)/2;
	ll l = init(s, mid, index*2);
	ll r = init(mid+1, e, index*2+1);
	return tree[index] = (l*r) % mod;
}

ll update(ll s, ll e, ll index, ll target, ll value){
	if(target < s || target > e) return tree[index];
	if(s == e) return tree[index] = value;
	
	ll mid = (s+e)/2;
	ll l = update(s, mid, index*2, target, value);
	ll r = update(mid+1, e, index*2+1, target, value);
	return tree[index] = (l*r) % mod;
}

ll sum(ll s, ll e, ll left, ll right, ll index){
	if(e < left || s > right) return 1;
	if(left <= s && e <= right) return tree[index];
	
	ll mid = (s+e)/2;
	ll l = sum(s, mid, left, right, index*2);
	ll r = sum(mid+1, e, left, right, index*2+1);
	return (l*r) % mod;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(tree, tree+1000004, 1);
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	init(1, N, 1);

	for(int i = 0; i < M+K; i++) {
		cin >> a >> b >> c;
		if(a==1) {
			update(1, N, 1, b, c);
			A[b] = c;
		} else {
			cout << sum(1, N, b, c, 1) << "\n";
		}
	}
}