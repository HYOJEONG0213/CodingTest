#include <bits/stdc++.h>
using namespace std;

int L, K, C, a, r1=1e09+4, r2;
vector <int> k;

bool check(int X){
	// X : 가장 긴 조각의 길이 
	int here = L;
	int cnt = 0;
	int firstCut = 0;
	while(here > X){
		int next = here - X;
		auto iter = lower_bound(k.begin(), k.end(), next);
		if(iter==k.end() || *iter >= here) return false;
		
		here = *iter;
		firstCut = here;
		cnt++;
	}
	if(cnt > C) return false;
	
	if(cnt < C) firstCut = k[0];
	
	if(r1 > X || (r1==X && r2 > firstCut)){
		r1 = X;
		r2 = firstCut;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> L >> K >> C;
	for(int i = 0; i < K; i++){
		cin >> a;
		k.push_back(a);
	}
	sort(k.begin(), k.end());
	
	int l = 1, r = L;
	while(l <= r){
		int mid = (l+r)/2;
		if(check(mid)){
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	cout << r1 << " " << r2;
}