#include <bits/stdc++.h>
using namespace std;

int N, M, n, a[1004], indegree[1004], ret[1004];
vector <int> adj[1004];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> n;
		cin >> a[0];
		for(int j = 1; j < n; j++){
			cin >> a[j];
			adj[a[j-1]].push_back(a[j]);
			indegree[a[j]]++;
		}
	}
	
	queue <int> q;
	for(int i = 1; i <= N; i++){
		if(indegree[i]==0)
			q.push(i);
	}
	
	for(int i = 1; i <= N; i++){
		if(q.empty()){
			cout << "0";
			return 0;
		}
		int here = q.front(); q.pop();
		ret[i] = here;
		for(auto j : adj[here]){
			indegree[j]--;
			if(indegree[j]==0){
				q.push(j);
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		cout << ret[i] << "\n";
	}
}