#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int here = 1;
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 9; j++){
			for(int k = here; k <=here+i-1; k++){
				cout << k << "*" << j << "=" << k*j << "\t\t";
			}
			cout << "\n";
		}
		here+=i;
		cout << "\n";
	}
}
