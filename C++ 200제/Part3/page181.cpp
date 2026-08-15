#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a[10] = {0};
	int b[10] = {0};
	for(int i = 0; i < 10; i++){
		b[i] = i;
	}
	
	fill_n(a, 2, 10);
	fill_n(a+4, 3, 20);
	fill_n(b, 4, 40);
	fill_n(b+4, 3, 30);
	fill_n(b+7, 1, 7);
	
	for(int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
	
	for(int i = 0; i < 10; i++){
		cout << b[i] << " ";
	}
	cout << "\n";
}
