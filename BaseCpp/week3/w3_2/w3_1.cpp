#include <iostream>
using namespace std;

int arr[8] = {4,3,6,1,3,1,5}, a, cnt;

int main(){
	cin >> a;
	for(int i= 0; i < 8; i++){
		if(arr[i]==a) cnt++;
	}
	cout << cnt;
}
