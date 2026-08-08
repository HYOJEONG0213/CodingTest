#include <bits/stdc++.h>
using namespace std;

int ret[14];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ret[1]=1; ret[2]=1;
	for(int i = 3; i<10; i++){
		ret[i] = ret[i-2]+ret[i-1];
	}
	
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < i+1; j++){
			cout << ret[j] << ", ";
		}
		cout << "\n";
	}
}
