#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int N, R, Q, a, b, psum[100004], visited[100004];
vector <int> adj[100004];

void f(int here){
	visited[here] = 1;
	for(auto i : adj[here]){
		if(visited[i]) continue;
		f(i);
		psum[here] += psum[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(psum, psum+100004, 1);
	cin >> N >> R >> Q;
	for(int i = 0; i < N-1 ; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	f(R);
	
	for(int i = 0; i < Q; i++){
		cin >> a;
		cout << psum[a] << "\n";
	}
}