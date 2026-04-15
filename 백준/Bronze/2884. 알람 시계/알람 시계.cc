#include <bits/stdc++.h>
using namespace std;

int H, M;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> H >> M;
	
	if(H == 0 && M-45 < 0){
		H = 23;
		M = 60 + M - 45;
	}
	else if(M-45 < 0){
		H--;
		M = 60 + M - 45;
	}
	else{
		M -= 45;
	}
	
	cout << H << " " << M;
}