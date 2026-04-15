#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, a, retList[3];
ll ret = 1e11;
vector <ll> A;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	for(int i = 0; i < N; i++){
		int l = i+1, r = N-1;
		while(l < r){
			ll temp = A[i] + A[l] + A[r];
			if(ret > abs(temp)){
				ret = abs(temp);
				retList[0] = A[i];
				retList[1] = A[l];
				retList[2] = A[r];
			}
			if(temp < 0) l++;
			else r--;
		}
	}
	
	for(int i : retList)
		cout << i << " ";
}