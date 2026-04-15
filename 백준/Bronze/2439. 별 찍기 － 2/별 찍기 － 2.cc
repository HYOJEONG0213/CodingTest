#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	int T = N;
	int i = N-1;
	while(T--){
		int j = N - i; 
		for(int k = 0; k < i; k++){
			cout << " ";
		}
		for(int k = 0; k < j; k++){
			cout << "*";
		}
		cout << "\n";
		i--;
	}
	
}