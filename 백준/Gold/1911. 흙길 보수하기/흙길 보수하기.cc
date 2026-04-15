#include <bits/stdc++.h>
using namespace std;

int N, L, l, r, ret;
vector <pair<int, int>> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < N; i++){
		int a = v[i].first;
		int b = v[i].second;
		
		if(a < l){
			a = l;
			if(a > b) continue;
		}
		
		int d = b - a;
		int Q = d / L;
		//cout << Q <<"\n";
		int r = d % L;
		ret += Q;

		if(r != 0){
			ret++;
			l = a + L * (Q+1);
		//	cout << l << " "; 
		}
	}
	cout << ret;
} 