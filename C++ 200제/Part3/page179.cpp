#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a[10] = {0};
	int b[10] = {0};
	for(int i = 0; i < 10; i++){
		b[i] = i;
	}
	
	fill(a, a+3, 10);
	fill(a+4, a+8, 20);
	fill(b, b+3, 30);
	fill(b, b+3, 30);
	
	for(int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
	
	for(int i = 0; i < 10; i++){
		cout << b[i] << " ";
	}
	cout << "\n";
}
