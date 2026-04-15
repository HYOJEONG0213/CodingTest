#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
//dp[경찰차1의 인덱스][경찰차2의 인덱스] = 최소거리  
int N, W, ret, dp[1004][1004];
pair<int,int> A[1004];
vector <int> retList;

int getDist(int start, int end){
	return abs(A[start].first-A[end].first) + abs(A[start].second-A[end].second);
}


int go(int a, int b, int idx){
	if(idx >= W+2) return 0;
	
	int &ret = dp[a][b];
	if(ret != -1) return ret;
	
	ret = min(go(idx, b, idx+1)+getDist(a, idx), go(a, idx, idx+1)+getDist(b, idx));
	return ret;
}

void solve(){
	int a = 0, b = 1;
	for(int i = 2; i < W+2; i++){
		if(dp[i][b] + getDist(a, i) < dp[a][i] + getDist(b, i)){
			cout << "1" << "\n";
			a = i;
		}
		else{
			cout << "2" << "\n";
			b = i;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> W;
	memset(dp, -1, sizeof(dp));
	int sy1 = 1, sx1 = 1, sy2 = N, sx2 = N;
	A[0] = {1,1};
	A[1] = {N,N};
	for(int i = 2; i < W+2; i++){
		int a, b;
		cin >> a >> b;
		A[i] = {a, b};
	}
	
	cout << go(0, 1, 2) << "\n";
	solve();
}