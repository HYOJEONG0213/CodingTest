#include <bits/stdc++.h>
using namespace std;

int n, x[100004], y[100004];
int treeX[1000004], treeY[1000004];
vector <int> xlist, ylist;

void update(int *tree, int s, int e){
	while(s <= e){
		tree[s] ++;
		s++;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		x[i] += 500000;
		y[i] += 500000;
		xlist.push_back(x[i]);
		ylist.push_back(y[i]);
	}
	
	x[n] = x[0];
	y[n] = y[0];
	for(int i = 1; i <= n; i++){
		if(x[i-1]!=x[i]){
			int startX = min(x[i-1], x[i]);
			int endX = max(x[i-1], x[i]);
			update(treeX, startX+1, endX);
		}
		if(y[i-1]!=y[i]){
			int startY = min(y[i-1], y[i]);
			int endY = max(y[i-1], y[i]);
			update(treeY, startY+1, endY);
		}
	}
	
	
	
	
	int ret = 0;
	for(int i : ylist){
		ret = max(ret, treeY[i]);
	}
	for(int i : xlist){
		ret = max(ret, treeX[i]);
	}
	cout << ret;
}