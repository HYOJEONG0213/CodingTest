#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1111111111;

ll n, H[100004], tree[400004];

ll init(ll s, ll e, ll index){
	if(s==e) return tree[index] = s;
	
	ll mid = (s+e)/2;
	ll l = init(s, mid, index*2);
	ll r = init(mid+1, e, index*2+1);
	
	if(H[l] < H[r]) return tree[index] = l;
	else return tree[index] = r;
}

ll query(ll s, ll e, ll left, ll right, ll index){
	if(e < left || s > right) return 0;
	if(left <= s && e <= right) return tree[index];
	
	ll mid = (s+e)/2;
	ll l = query(s, mid, left, right, index*2);
	ll r = query(mid+1, e, left, right, index*2+1);
	if(H[l] < H[r]) return l;
	else return r;
}

ll getExtent(ll s, ll e){
	if(s > e) return 0;
	
	ll mn = query(1, n, s, e, 1);
	ll area = H[mn] * (e-s + 1);
	
	ll left = getExtent(s, mn-1);
	ll right = getExtent(mn+1, e);
	
	return max({left, right, area});
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	H[0] = INF;
	while(cin >> n){
		if(n == 0) return 0;
		
		ll ret = 0;
		fill(tree, tree+400004, INF);
		
		for(ll i = 1; i <= n; i++) cin >> H[i];
		init(1, n, 1);
		cout << getExtent(1, n) << "\n";
	}

	
}