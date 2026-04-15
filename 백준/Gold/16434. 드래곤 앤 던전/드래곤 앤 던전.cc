#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, ATK, t, a, h, ret, H;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> ATK;
	
	for(int i = 0; i < N; i++){
		cin >> t >> a >> h;
		if(t == 1){
			ll damage = a * (ceil((double)h / ATK) - 1);
			if(H < damage){
				ret += damage - H;
				H = 0;
			}
			else{
				H = H - damage;
			}
		}
		else{
			ATK += a;
			H = min(ret, H + h);
		}
	}
	
	cout << ret+1;
}