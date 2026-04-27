#include <bits/stdc++.h>
using namespace std;

int n, tree[100004], pos1;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	pos1= 1;
	for(int i = 1; i<=n; i++){
		// 새 값 넣고  
		tree[i] = i;
		// i를 맨앞으로 스왑
		while(pos1 != 1){
			swap(tree[pos1/2], tree[pos1]);
			pos1 = pos1/2;
		} 
		// 새값과 i를 swap
		swap(tree[pos1], tree[i]);
		pos1 = i; 
	}
	
	for(int i = 1; i<=n; i++){
		cout << tree[i] << " ";
	}
}