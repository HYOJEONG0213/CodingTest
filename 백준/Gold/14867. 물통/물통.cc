#include <bits/stdc++.h>
using namespace std;

int A, B, C, D, ret;
const int INF = 987654321;
map <pair<int, int>, int> m;
queue <pair<int, int>> q;

void go(int x, int y, int d){
	if(m[{x, y}]) return;
	m[{x, y}] = d+1;
	q.push({x, y});
}

int bfs(){
	q.push({0, 0});
	m[{0,0}] = 1;
	
	while(q.size()){
		auto f = q.front(); q.pop();
		int x = f.first;
		int y = f.second;
		
		go(A, y, m[{x, y}]);
		go(x, B, m[{x, y}]);
		go(0, y, m[{x, y}]);
		go(x, 0, m[{x, y}]);
		go(max(x - (B-y), 0), min(B, y+x), m[{x, y}]);
		go(min(A, x+y), max(y - (A-x), 0), m[{x, y}]);
		
		if(m[{C, D}]) return m[{C, D}]-1;
	}
	
	return -1;
}

//int go(int x, int y){
//	if(x == C && y == D) return 1;
//	int &ret = visited[{x, y}];
//	if(ret != 0) return INF;
//	
//	ret = INF;
//	ret = min(ret, go(A, y)+1);
//	ret = min(ret, go(x, B)+1);
//	ret = min(ret, go(0, y)+1);
//	ret = min(ret, go(x, 0)+1);
//
//	if(x <= B - y){
//		ret = min(ret, go(0, y+x)+1);
//	}
//	else{
//		ret = min(ret, go(x - (B -y), B)+1);
//	}
//
//	if(y <= A - x){
//		ret = min(ret, go(x+y, 0)+1);
//	}
//	else{
//		ret = min(ret, go(A, y - (A-x))+1);
//	}
//	
//	cout << x << " " << y << " " << ret << "\n";
//	return ret;
//}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//visited[{0,0}] = 1;
	cin >> A >> B >> C >> D;
	//ret = min(go(A, 0), go(0, B));
	//cout << (ret == INF ? -1 : ret);
	
	cout <<  bfs();
}