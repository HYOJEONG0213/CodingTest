#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num1[3] = {10, 20, 30};
	int * p1 = num1;
	
	int a = 1, b = 2, c = 3;
	int * p2[3] = {&a, &b, &c};
	
	for(int i = 0; i < 3; i++){
		cout << p1[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i < 3; i++){
		cout << *p2[i] << " ";
	}
}
