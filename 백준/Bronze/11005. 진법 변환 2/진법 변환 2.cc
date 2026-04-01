#include <bits/stdc++.h>
using namespace std;

int N, B;
string ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> B;
	while(N > 0){
		int temp = N % B;
		N = N / B;
		if(temp < 10){
			ret += temp + '0';
		}
		else{
			ret += temp-10 +'A';
		}
	}
	
	reverse(ret.begin(), ret.end());
	cout << ret;
}