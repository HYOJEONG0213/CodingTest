#include <iostream>
using namespace std;

int sum(int a, int b){
	return a+b;
}

int comp(int a, int b){
	return abs(a-b);
}

void print(int t1, int t2){
	cout << t1 << " " << t2;
}

int main(){
	int a, b;
	cin >> a >> b;
	print(sum(a,b), comp(a,b));
}
