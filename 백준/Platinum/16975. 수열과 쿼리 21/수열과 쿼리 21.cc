#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, M, a, b, c, d, A[100004], tree[400004], lazy[400004];

void init(ll s, ll e, ll node){
	if(s==e){
		tree[node] = A[s];
		return;
	}
	int mid = (s+e)/2;
	init(s, mid, node*2);
	init(mid+1, e, node*2+1);
	tree[node] = tree[node*2]+tree[node*2+1];
}

void update_lazy(ll s, ll e, ll node){
	if(lazy[node]==0) return;
	
	tree[node] += (e-s+1) * lazy[node];
	if(s != e){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	
	lazy[node] = 0;
}

void update(ll s, ll e, ll node, ll left, ll right, ll value){
	update_lazy(s, e, node);
	if(e < left || s > right) return;
	if(left <= s && e <= right) {
		lazy[node] += value;
		update_lazy(s, e, node);
		return;
	}
	
	ll mid = (s+e)/2;
	update(s, mid, node*2, left, right, value);
	update(mid+1, e, node*2+1, left, right, value);
	tree[node] = tree[node*2]+tree[node*2+1];
}

ll sum(ll s, ll e, ll node, ll left, ll right){
	update_lazy(s, e, node);
	if(e < left || s > right) return 0;
	if(left <= s && e <= right) return tree[node];
	
	ll mid = (s+e)/2;
	ll l = sum(s, mid, node*2, left, right);
	ll r = sum(mid+1, e, node*2+1, left, right);
	return l+r;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(ll i = 0; i < N; i++){
		cin >> A[i];
	}
	init(0, N-1, 1);
	cin >> M;
	for(ll i = 0; i < M; i++){
		cin >> a;
		if(a==1){
			cin >> b >> c >> d;
			b--; c--;
			update(0, N-1, 1, b, c, d);
		}
		else{
			cin >> b;
			b--;
			cout << sum(0, N-1, 1, b, b) << "\n";
		}
	}
}