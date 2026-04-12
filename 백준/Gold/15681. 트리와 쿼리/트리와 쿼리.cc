#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int N, R, Q, a, b, p[100004], arr[100004], psum[100004], visited[100004];
vector <int> adj[100004];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> R >> Q;
	for(int i = 0; i < N-1 ; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue <int> q;
	q.push(R);
	visited[R] = 1;
	while(q.size()){
		int here = q.front(); q.pop();
		for(int i : adj[here]){
			if(visited[i]) continue;
			visited[i]=1;
			p[i] = here;
			q.push(i);
			arr[here]++;
		}
	}
	
	for(int i = 1; i <= N; i++){
		if(arr[i]==0){
			q.push(i);
		}
		psum[i]=1;
	}
	
	while(q.size()){
		int here = q.front(); q.pop();
		//cout << here << " ";
		arr[p[here]]--;
		psum[p[here]] += psum[here];
		if(here==R) continue;
		if(arr[p[here]]==0) q.push(p[here]);
	}
	
	for(int i = 0; i < Q; i++){
		cin >> a;
		cout << psum[a] << "\n";
	}
}