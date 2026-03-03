#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tt;
int N, M, a, b, c, ret, p[1004], level[1004];
priority_queue <tt, vector<tt>, greater<tt>> pq;

int find(int x){
	if(p[x]==-1) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x); y = find(y);
	if(x==y) return;
	if(level[x] < level[y]){
		p[x] = y;
	}
	else{
		p[y] = x;
		if(level[x]==level[y])	
			level[x]++;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> N;
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;
		pq.push(make_tuple(c, a, b));
	}
	
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		tie(c, a,b) = f;
		int x = find(a), y = find(b);
		if(x==y) continue;
		//cout << c << " " << a << " " << b << "\n";

		merge(x, y);
		ret += c;
	}
	
	cout << ret;
}