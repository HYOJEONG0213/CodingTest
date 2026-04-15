#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int a, dp[100004][5][5];
vector <int> A; 

int check(int first, int target){
	//제자리 
	if(first == target) return 1;
	//정가운데인 경우  
	if(first == 0) return 2;
	//끝에서 끝으로 이동하는 경우  
	if(abs(target-first)==2) return 4;
	//인근으로 이동하는 경우 
	return 3; 
}

int go(int idx, int l, int r){
	if(l!=0 && r!= 0 && l==r) return INF;
	if(idx == A.size()) return 0;
	
	int &ret = dp[idx][l][r];
	if(ret != -1) return ret;
	
	ret = INF;
	int lp = check(l, A[idx]);
	int rp = check(r, A[idx]);
	ret = min(go(idx+1, A[idx], r)+lp, go(idx+1, l, A[idx])+rp);
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	while(1){
		cin >> a;
		if(a == 0) break;
		A.push_back(a);
	}
	
	cout << go(0, 0, 0);
}