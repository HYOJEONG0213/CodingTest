#include <bits/stdc++.h>
using namespace std;

int N, x[100004], dp[1000004], mx;
bool visited[1000004];
const int INF = 987654321;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> x[i];
		visited[x[i]]=1;
		mx = max(mx, x[i]);
	}
	for(int i = 0; i < N; i++) {
		for(int j = x[i]*2; j <= mx; j+=x[i]){
			if(visited[j]==0) continue;
			dp[x[i]]++;
			dp[j]--;
		}
	}
	
	for(int i = 0; i < N; i++) {
		cout << dp[x[i]] << " ";	
	}
}