#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 0; i < 4; i++){
		for(int j = 3-i; j >= 0; j--){
			cout << " ";
		}
		for(int j = 0; j < 2*i+1; j++){
			cout << "*";
		}
		cout << "\n";
	}
}
