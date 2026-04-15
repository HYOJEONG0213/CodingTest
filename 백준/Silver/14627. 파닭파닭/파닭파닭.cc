#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll S, C, maxValue, ret, a, l=1, r, sum;
vector <ll> L;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S >> C;
	for(int i =0; i < S; i++){
		cin >> a;
		L.push_back(a);
		sum += a;
		maxValue = max(L[i], maxValue);
	}
	
	r = maxValue;
	
	while(l <= r){
		ll mid = (l+r)/2;
		//cout << mid << " ";
		ll cnt = 0;
		vector <ll> temp = L;
		copy(L.begin(), L.end(), temp.begin());
		
		ll i = 0;
		while(i < S && cnt < C){
			if(temp[i] - mid < 0){
				if(i + 1 == S) break;
				i++;
				continue;
			}
			
			temp[i] -= mid;
			cnt++;
		}
		
		//cout << cnt << "\n"; 
		if(cnt >= C) {
			ret = max(ret, mid);
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	
	cout << sum - ret * C;
}