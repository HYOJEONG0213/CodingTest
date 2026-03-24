#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
ll N, A[4004], B[4004], C[4004], D[4004];
ll ret;
vector<ll> AB, CD;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			AB.push_back(A[i]+B[j]);
			CD.push_back(C[i]+D[j]);
		}
	}
	
	sort(CD.begin(), CD.end());
	
	for(ll target : AB){
		auto lower = lower_bound(CD.begin(), CD.end(), -target);
		auto upper = upper_bound(CD.begin(), CD.end(), -target);
		
		ret += (upper-lower);
	}
	
	cout << ret;
}