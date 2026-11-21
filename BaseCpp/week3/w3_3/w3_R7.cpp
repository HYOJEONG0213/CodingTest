#include <iostream>
using namespace std;

int arr[7], mx, mn; 

int main(){
	for(int i = 0; i < 7; i++) cin >> arr[i];
	mx = arr[0];
	mn = arr[0];
	
	for(int i = 0 ; i < 7; i++){
		mx = (mx < arr[i] ? arr[i] : mx);
		mn = (mn < arr[i] ? mn : arr[i]);
	}
	
	cout << mx << " " << mn;
}
