#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	int arr[5] = {3,9,12,15,55};
	cin >> a >> b >> c;
	
	int sum = a+b+c;
	if(sum > 10) cout << arr[4];
	else cout << arr[0];
	
}

