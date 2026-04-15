#include <bits/stdc++.h>
using namespace std;

int n ,m, a, b, ret, p[500004], level[500004];

int find(int x){
	if(p[x] == -1) return x;
	return p[x] = find(p[x]);
}

bool merge(int x, int y){
	x = find(x); y = find(y);
	if(x == y){
		return true;
	}
	if(level[x] > level[y]){
		p[y] = x;
		level[x]++;
	}
	else{
		p[x] = y;
		level[y]++;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	memset(p, -1, sizeof(p));
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		if(merge(a, b)==true){
			cout << i;
			return 0;
		}	 
	}
	cout << "0";
}