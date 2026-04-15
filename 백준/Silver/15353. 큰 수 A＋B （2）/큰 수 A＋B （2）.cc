#include <bits/stdc++.h>
using namespace std;

#define prev fffff

string A, B, ret;
int sum;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> A >> B;
	
	while(A.size() || B.size() || sum){
		if(A.size()){
			sum += A.back() - '0';
			A.pop_back();
		}
		if(B.size()){
			sum += B.back() - '0';
			B.pop_back();
		}
		
		ret += (sum % 10) + '0'; 
		sum = sum / 10;
	}
	
	reverse(ret.begin(), ret.end());
	
	cout << ret;
}