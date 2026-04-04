#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T, n, m, A[1004], B[1004], psumA[1004], psumB[1004];
ll ret;
vector <int> vA, vB;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
		psumA[i] = psumA[i-1]+A[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++){
		cin >> B[i];
		psumB[i] = psumB[i-1]+B[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int num = psumA[j] - psumA[i-1];
			vA.push_back(num);
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = i; j <= m; j++){
			int num = psumB[j] - psumB[i-1];
			vB.push_back(num);
		}
	}
	sort(vA.begin(), vA.end());
	sort(vB.begin(), vB.end());
	
	
	for(auto i : vA){
		int target = T - i;
		ll cnt = upper_bound(vB.begin(), vB.end(), target) - lower_bound(vB.begin(), vB.end(), target);
		ret += cnt;
	}
	
	cout << ret;
}