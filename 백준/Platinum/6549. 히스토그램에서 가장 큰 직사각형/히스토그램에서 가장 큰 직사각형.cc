#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, H[100004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while(cin >> n){
		if(n == 0) return 0;
		
		stack <ll> stk;
		ll ret = 0;
		
		for(ll i = 0; i < n; i++) cin >> H[i];
		// 맨끝에 가상 0인 친구를 세워둬야 스택 빌떄까지 해줌 
		H[n] = 0;
		
		for(ll i = 0; i < n+1; i++){
			while(stk.size() && H[stk.top()] > H[i]){
				ll height = H[stk.top()];
				stk.pop();
				
				ll weight = i;
				if(stk.size()){
					weight = i - stk.top() - 1;
				}
				ret = max(ret, height*weight);
			}
			stk.push(i);
		}
		cout << ret << "\n";
	}

	
}