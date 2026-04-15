#include <bits/stdc++.h>
using namespace std;

int N;
double ret, a[10004], sum;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N; 
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	sum = a[0];
	ret = a[0];
	
	for(int i = 1; i < N; i++){
		if(a[i] > sum * a[i]) sum = a[i];
		else sum *= a[i];
		
		ret = max(sum, ret);
	}
	
	cout << fixed << setprecision(3) << ret;
}