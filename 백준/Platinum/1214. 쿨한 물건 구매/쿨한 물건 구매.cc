#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll D, P, Q, mn=1e18;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> D >> P >> Q;
	if(P > Q) swap(P, Q);
	
	// Q, P의 최대 횟수 : q, p 
	ll q = (D/Q +1);
	ll maxcycle = P;
	
	for(ll i = 0; i <= min(q, maxcycle); i++){
		ll remain = D - Q*i;
		
		if(remain <= 0) {
			mn = min(mn, Q*i);
			break;
		}
		
		ll pcnt = (remain + P-1) / P;
		ll sum = Q*i + P*pcnt;
		mn = min(mn, sum);
		if(mn==D) break;
	}
	
	cout << mn;
}