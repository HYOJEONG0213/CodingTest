#include <bits/stdc++.h>
using namespace std;

int G, P, g[100004], ret, tree[100004], p[100004];

int find(int x){
	if(p[x] == -1) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x==y) return;
	p[x] = y;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> G;
	cin >> P;
	for(int i = 1; i <= P; i++){
		cin >> g[i];
	}
	for(int i = 1; i <= P; i++){
		int temp = find(g[i]);
		if(temp == 0){
			break;
		}
		else{
			ret++;
			merge(temp, temp-1);
		}
	}
	cout << ret;
}