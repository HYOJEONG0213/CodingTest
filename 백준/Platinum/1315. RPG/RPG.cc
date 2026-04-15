#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, dp[1004][1004], visited[1004];
struct quest{
	int str, in, pnt;
};
vector <quest> v;



int go(int str, int in){
	int &ret = dp[str][in];
	if(ret != -1) return ret;
	
	ret = 0;
	vector <int> here;
	int cnt = 0;
	for(int i = 0; i < N; i++){
		if(str < v[i].str && in < v[i].in) continue;
		
		ret++;
		if(visited[i]==1) continue;
		
		here.push_back(i);
		visited[i] = 1;
		cnt += v[i].pnt;
	}
	
	for(int i = 0; i <= cnt; i++){
		int nextStr = min(1000, str + i);
		int nextInt = min(1000, in + (cnt - i));
		ret = max(ret, go(nextStr, nextInt));
	}
	
	for(int i : here){
		visited[i] = 0;
	}
	
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({a,b,c});
	}
	
	
	cout << go(1,1);
}