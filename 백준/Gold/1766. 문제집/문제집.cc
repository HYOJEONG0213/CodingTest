#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vv;

int N, M, A, B, cnt[32004];
vv adj[32004], ret; 
priority_queue <int, vv, greater<int>> pq;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> A >> B;
		adj[A].push_back(B);
		cnt[B]++;
	}
	for(int i = 1; i <= N; i++){
		if(cnt[i]==0){
			pq.push(i);
		}
	}
	
	while(!pq.empty()){
		int here = pq.top(); pq.pop();
		ret.push_back(here);
		
		for(int next : adj[here]){
			cnt[next]--;
			if(cnt[next]==0){
				pq.push(next);
			}
		}
	}
	
	for(int i : ret){
		cout << i << " ";
	}
}