#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, result;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	result = n;
	for(ll i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			result = result - result / i;
			while(n%i==0){
				n = n/i;
			}
		}
	}
	
	if(n > 1)
		result = result - result / n;
	cout << result; 
}