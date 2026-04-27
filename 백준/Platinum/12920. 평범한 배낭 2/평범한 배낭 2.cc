#include <bits/stdc++.h>
using namespace std;

struct Bag{
	int V, C;
};
const int INF = 987654321;
int N, M, V, C, K, mx;
// dp[idx][가방무게] = 최대 가치 
int dp[10004];
vector <Bag> bag; 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		Bag b;
		cin >> V >> C >> K;
		for(int j = 1; K > 0; j *= 2){
			int num = min(j, K);
			bag.push_back({V*num, C*num});
			K -= num;
		}
	}
	
	for(int i = 0; i < bag.size(); i++){
		for(int j = M; j >= bag[i].V ; j--){
			dp[j] = max(dp[j], dp[j-bag[i].V] + bag[i].C);
		}
	}
	
	cout << dp[M];
}