#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
int N, A[4004], B[4004], C[4004], D[4004];
ll ret;
vector<int> AB;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	AB.reserve(N*N);
	
	for(int i = 0; i < N; i++){
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			AB.push_back(A[i]+B[j]);
		}
	}
	
	sort(AB.begin(), AB.end());
	
	for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
        	int target = -(C[i]+D[j]);
        	
			auto lower = lower_bound(AB.begin(), AB.end(), target);
			auto upper = upper_bound(AB.begin(), AB.end(), target);
			
			ret += (upper-lower);
		}
	}
	
	cout << ret;
}