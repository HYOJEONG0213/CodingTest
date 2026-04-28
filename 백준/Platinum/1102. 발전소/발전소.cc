#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, cost[18][18], dp[(1<<16)+4], P, original, cnt;
string s;

int f(int mask){
	if(__builtin_popcount(mask) >= P) return 0;
	int &ret = dp[mask];
	if(ret != -1) return ret;
	
	ret = INF;
	for(int i = 0; i < N; i++){
		if((mask & (1<<i)) == 0) continue;	//i : 현재 켜져있는 불빛으로 
		for(int j = 0 ; j < N; j++){
			if((mask & (1<<j)) != 0) continue;	//j : 꺼져있는 불빛을 킬 수 있다면 
			int next = mask | (1<<j);
			ret = min(ret, f(next) + cost[i][j]);
		} 
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }
	cin >> s;
	for(int i = 0 ; i < N; i++){
		if (s[i] == 'Y') original |= (1<<i);
		cnt++;
	} 
	cin >> P;
	
	if(P > 0 && original == 0){
		cout << -1;
		return 0;
	}
	int ret = f(original);
	cout << (ret==INF ? -1 : ret);
}