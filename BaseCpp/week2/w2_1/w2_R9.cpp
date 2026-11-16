#include <iostream>
using namespace std;

int a, b, arr[5] ;


int main(){
	cin >> a >> b;
	arr[0] = a;
	for(int i = 1; i < 5; i++){
		arr[i] = a + b*i;
	}
	
	for(int i = 0 ; i < 5; i++) cout << arr[i] << " ";
}
