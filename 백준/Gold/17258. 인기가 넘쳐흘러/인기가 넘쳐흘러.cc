#include <bits/stdc++.h>
using namespace std;
#define prev pppp
//A : 일반인, B : 친구들, dp[해당지점에서][남은 친구수] = 최대시간수  
int N, M , K, T, a, b, A[304], dp[304][304];
vector <pair<int,int>> v;

int go(int idx, int num, int prev){
	if(idx > v.size()) return 0;
	int &ret = dp[idx][num];
	if(ret != -1) return ret;
	
	int need = max(0, T - v[idx].second);
	int real_need = (need <= prev ? 0 : need - prev);
	if(need == 0) prev = 0;
	
	if(num - real_need >= 0)
		return ret = max(go(idx+1, num - real_need, need)+v[idx].first,
			go(idx+1, num, prev));
	else
		return ret = max(ret, go(idx+1, num, prev));
	
	
	return ret;
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K >> T;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		for(int i = a; i <= b-1; i++){
			A[i] = min(T, A[i]+1);
		}
	}
	
	int temp = A[1];
	int count = 1;
	
	for(int i = 2; i <= N; i++){
		if(temp != A[i]){
			v.push_back({count, temp});
			count = 0;
			temp = A[i];
		}
		count ++;
	}
	v.push_back({count, temp});
	
	
	cout << go(0, K, 0);
	
}