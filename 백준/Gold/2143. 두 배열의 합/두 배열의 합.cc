#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T, n, m, A[1004], B[1004], psumA[1004], psumB[1004];
ll ret;
unordered_map <int,int> mpA, mpB;

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
			mpA[num]++;
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = i; j <= m; j++){
			int num = psumB[j] - psumB[i-1];
			mpB[num]++;
		}
	}
	
	for(auto iter = mpA.begin(); iter != mpA.end(); iter++){
		int target = T - iter->first;
		if(mpB.count(target)){
			ret += (ll)iter->second * mpB[target];
		}
	}
	
	cout << ret;
}