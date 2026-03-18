#include <bits/stdc++.h>
using namespace std;

int B, ret; 
string N;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> B;
	
	int num = 1;
	for(int i = N.size()-1; i >= 0; i--){
		if(N[i] >= '0' && N[i] <= '9'){
			ret += (N[i]-'0') * num;
		}
		else{
			ret += (N[i]-'A'+10) * num;
		}
		num *= B;
	}
	
	cout << ret;
}