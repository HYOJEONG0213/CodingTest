#include <bits/stdc++.h>
using namespace std;
#define y1 yyyyy 

typedef long long ll;
ll N, mx, x1[3004], x2[3004], y1[3004], y2[3004], ret, p[3004], level[3004];
map <ll, ll> mp;

ll outer(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3){
	return a1*b2+a2*b3+a3*b1 - (a1*b3 + a3*b2 + a2*b1);
}

ll find(ll x){
	if(p[x]==-1){
		return x;
	}
	return p[x] = find(p[x]);
}

void merge(ll x, ll y){
	x = find(x), y = find(y);
	if(x==y) return;
	if(level[x] < level[y]){
		p[x] = y;
	}
	else{
		if(level[x]==level[y]){
			level[x]++;
		}
		p[y] = x;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		if(make_pair(x1[i], y1[i]) > make_pair(x2[i], y2[i])){
			swap(x1[i], x2[i]);
			swap(y1[i], y2[i]);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			ll a = outer(x1[i], y1[i], x2[i], y2[i], x1[j], y1[j]);
			ll b = outer(x1[i], y1[i], x2[i], y2[i], x2[j], y2[j]);
			ll c = outer(x1[i], y1[i], x1[j], y1[j], x2[j], y2[j]);
			ll d = outer(x2[i], y2[i], x1[j], y1[j], x2[j], y2[j]);
			if(a*b > 0 || c*d > 0) continue;
			if(a*b == 0 && c*d == 0){
				// 대소 비교 
				if(x2[i] >= x1[j] && x1[i] <= x2[j] 
				&& min(y1[i], y2[i]) <= max(y1[j], y2[j]) 
				&& max(y1[i], y2[i]) >= min(y1[j], y2[j])){
					merge(i, j);
				}
			}
			else{
				merge(i, j);
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		int a = find(i);
		if(mp[a]==0) ret++;
		mp[a]++;
		mx = max(mx, mp[a]);
	}
	
	cout << ret << "\n";
	cout << mx;
}