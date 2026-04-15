#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;
ll N;
map <ll, ll> mp;

ll fibo(ll n){
	if(n <= 2) return mp[n];
	
	ll &ret = mp[n];
	if(ret != 0) return ret;
	
	if(n % 2 == 1){
		ll a = fibo((n+1)/2) % mod;
		a = a*a % mod;
		ll b = fibo((n-1)/2) % mod;
		b = b*b % mod;
		return ret = (a + b) % mod;
	}
	else{
		ll a = fibo(n/2)%mod;
		ll b = ((fibo(n/2 + 1) % mod) + fibo(n/2 - 1) % mod ) % mod;
		return ret = (a * b) % mod;
	} 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	mp[0] = 0;
	mp[1] = 1;
	mp[2] = 1;
	
	cout << fibo(N);
}