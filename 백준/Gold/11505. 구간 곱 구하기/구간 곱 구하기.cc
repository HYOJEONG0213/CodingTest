#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll N, M, K, a,b,c, A[1000004], tree[1000004], temptree[1000004];

ll power(ll num, ll exp){
	ll ret = 1;
	num %= mod;
	
	while(exp > 0){
		if(exp % 2 == 1) ret = (ret*num) % mod;
		num = (num*num) % mod;
		exp /= 2;
	}
	return ret;
} 

void update(ll index, ll value, int flag){
	if(value == 0){
		while(index <= N){
			// flag가 *라면 0 늘려주고, /라면 0을 제거할거야~  
			temptree[index] += flag;
			index += index & -index;
		}
		return;
	}
	
	while(index <= N){
		if(flag==1){
			tree[index] *= value;
			tree[index] %= mod;
		}
		else{
			tree[index] *= power(value, mod-2);
			tree[index] %= mod;
		}
		index += index & -index;
	}
}

ll sum(ll index){
	ll ret = 1;
	while(index > 0){
		ret *= tree[index];
		ret %= mod;
		index -= index & -index;
	}
	return ret;
}

ll sum_zero(ll index){
	ll ret = 0;
	while(index > 0){
		ret += temptree[index];
		index -= index & -index;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(tree, tree+1000004, 1);
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		update(i, A[i], 1);
	}
	
	for(int i = 0; i < M+K; i++){
		cin >> a >> b >> c;
		if(a==1){
			update(b, A[b], -1);
			update(b, c, 1);
			A[b] = c;
		}
		else{
			ll zero = sum_zero(c) - sum_zero(b-1);
			if(zero){
				cout << 0 << "\n";
				continue;
			}
			
			int temp = sum(c);
			int temp2 = sum(b-1);
			cout << (temp * power(temp2, mod-2) % mod) << "\n";
		}
	}
}