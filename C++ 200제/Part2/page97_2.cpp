#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int offset = 0;
	for(int i = 1; i <= 15; i+=offset){
		for(int j = 1; j <= 9; j++){
			for(int k = i; k <=i+offset; k++){
				cout << k << "*" << j << "=" << k*j << "\t\t";
			}
			cout << "\n";
		}
		offset++;
		cout << "\n";
	}
}
