#include <bits/stdc++.h>
using namespace std;
#define y1 yyyyy 

typedef long long ll;
typedef pair<ll, ll> pp;
struct Line{
	pp p1, p2;
};
ll N, mx, ret, p[3004], level[3004];
Line lines[3004];
map <ll, ll> mp;

ll outer(pp a, pp b, pp c) {
    ll res = (a.first * b.second + b.first * c.second + c.first * a.second) 
	- (a.second * b.first + b.second * c.first + c.second * a.first);

	if(res > 0) return 1;
	if(res < 0) return -1;
	return 0;
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
		cin >> lines[i].p1.first >> lines[i].p1.second >> lines[i].p2.first >> lines[i].p2.second;
	}
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			ll a = outer(lines[i].p1, lines[i].p2, lines[j].p1);
			ll b = outer(lines[i].p1, lines[i].p2, lines[j].p2);
			ll c = outer(lines[i].p1, lines[j].p1, lines[j].p2);
			ll d = outer(lines[i].p2, lines[j].p1, lines[j].p2);
			if(a*b > 0 || c*d > 0) continue;
			if(a*b == 0 && c*d == 0){
				// 대소 비교 
				if(lines[i].p1 > lines[i].p2) swap(lines[i].p1, lines[i].p2);
				if(lines[j].p1 > lines[j].p2) swap(lines[j].p1, lines[j].p2);
				
				if(lines[i].p1 <= lines[j].p2 && lines[i].p2 >= lines[j].p1){
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