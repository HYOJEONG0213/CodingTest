#include <bits/stdc++.h>
using namespace std;
int N, a[100004], sum, ret=-987654321;



int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
		sum += a[i];
		ret = max(ret, sum);
		if(sum < 0) {
			sum = 0;
		}
	}
	
	
	cout << ret;
}