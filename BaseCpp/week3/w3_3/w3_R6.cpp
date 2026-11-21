#include <iostream>
using namespace std;

int arr[7] = {3,4,1,3,2,7,3}, a;
bool flag = false;

int main(){
	cin >> a;
	for(int i = 0;  i < 7; i++){
		if(arr[i]==a){
			flag = true;
			break;
		}
	}
	cout << (flag ? "발견" : "미발견");
}
