#include <bits/stdc++.h>
using namespace std;
#define rank rrr 

int n, m, a, b, num, tree[1000004], rank[1000004];

int getNum(int x){
	if(tree[x] == x){
		return x;
	}
	
	return x = getNum(tree[x]);
}

void merge(int a, int b){
	a = getNum(a); b = getNum(b);
	if(a==b) return;
	else{
		if(rank[a] < rank[b]){
			tree[a] = b;
		}
		else{
			tree[b] = a;
			if(rank[a] == rank[b]){
				rank[a]++;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	cin >> n >> m;
	for(int i = 0; i <= n; i++){
		tree[i] = i;
	}
	for(int i = 0; i < m; i++){
		cin >> num >> a >> b;
		if(num == 0){
			merge(a, b);
		}
		else{
			cout << (getNum(a)==getNum(b) ? "YES\n" : "NO\n");
		}
	}
}