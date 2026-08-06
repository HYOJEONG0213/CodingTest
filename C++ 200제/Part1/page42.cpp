#include <bits/stdc++.h>
using namespace std;

int f1(int a, int b){
	return a-b;
}
int f2(int a, int b){
	return a+b;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << f1(10,5) << "\n" << f2(5, 3) << "\n";	
 } 
