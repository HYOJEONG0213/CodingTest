#include <iostream>
using namespace std;

int arr1[6] = {10,50,40,20,30,40}, arr2[6];
int ret[6];

int main(){
	for(int i = 0 ; i < 6; i++){
		cin >> arr2[i];
		for(int j = 0; j < 6; j++){
			if(arr1[j]>arr2[i]){
				ret[i]++;
			}
		}
	}
	
	for(int i = 0 ; i < 6; i++) cout << ret[i] << " ";
}
