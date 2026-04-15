#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X, Y, Z, ret=-1;


int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> X >> Y;
	Z = Y*100 / X ;
	
	ll l = 1, r = 1000000000;
	while(l <= r){
		ll mid = (r+l)/2;
		ll temp = ((Y+mid)*100) / (X+mid);
		
		if(Z < temp){
			//cout << mid << "\n";
			r = mid - 1;
			ret = mid;
		}
		else{
			l = mid + 1;
		}
	}
	
	cout << ret;
}