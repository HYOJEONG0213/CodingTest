#include <iostream>
using namespace std;

int arr[6];

int main(){
	for(int i = 0 ; i < 6; i++) cin >> arr[i];
	for(int i = 0 ; i <6; i++){
		int mx = arr[i];
		int mxIdx = i;
		for(int j = i+1; j < 6; j++){
			if(mx < arr[j]){
				mx = arr[j];
				mxIdx = j;
			}
		}
		swap(arr[mxIdx], arr[i]);
	}
	for(int i = 0; i <6; i++) cout << arr[i] << " ";
}
