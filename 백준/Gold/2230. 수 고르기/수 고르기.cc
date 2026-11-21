#include <bits/stdc++.h>
using namespace std;

const int MAXNUMBER = 2011111111;
int N, M, arr[100004], ret = MAXNUMBER;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0 ; i < N; i++)  cin >> arr[i];
	
	sort(arr, arr+N);
	
	int l = 0, r = 0;
	while(l <= N){
		if(arr[r]-arr[l] >= M){
			ret = min(ret, arr[r] - arr[l]);
			l++;
		}
		else
			r++;
	}
	
	cout << (ret==MAXNUMBER? 0 : ret);
}