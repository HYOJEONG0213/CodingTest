#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A, B;

ll f(ll N){
	ll ret = 0;
	for(ll i = 0; (1LL<<i) <= N; i++){
		ll cycle = (1LL<<(i+1));
		ret += ((N+1) / cycle) * (1LL<<i);
		
		if((N+1) % cycle > 0)
			ret += max(0LL, (N+1) % cycle - (1LL<<i) );
	} 
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	cout << f(B) - f(A-1);
}