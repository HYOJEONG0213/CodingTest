#include <bits/stdc++.h>
using namespace std;

#define prev pppp

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 1; i < 10; i++){
		int cur = 1;
		int prev = 0;
		
		for(int j = 1; j < i+1; j++){
			cout << cur << ", ";
			
			int temp = cur;
			cur += prev;
			prev = temp;
		}
		cout << "\n";
	}
}
