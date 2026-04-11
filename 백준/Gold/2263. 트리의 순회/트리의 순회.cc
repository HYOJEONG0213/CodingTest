#include <bits/stdc++.h>
using namespace std;

int n, A[100004], B[100004], Aidx[100004], Bidx[100004];

void divide(int iL, int iR, int pL, int pR){
	if(iL > iR || pL > pR){
		return;
	}
	
	int root = B[pR];
	cout << root << " ";
	int rootIdx = Aidx[root];
	int leftSize = rootIdx - iL;
	
	divide(iL, rootIdx-1, pL, pL + leftSize - 1);
	divide(rootIdx+1, iR, pL+leftSize, pR-1);	//현재 루트노드 빼야제.. 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n ; i++){
		cin >> A[i];
		Aidx[A[i]] = i;
	}
	for(int i = 0; i < n ; i++){
		cin >> B[i];
		Bidx[B[i]] = i;
	}
	
	divide(0, n-1, 0, n-1);
}