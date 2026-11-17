#include <iostream>
using namespace std;

int arr1[5]={3,5,2,4,1}, arr2[3][2]={9,8,7,1,3,4}; 
int a;

int main(){
	if(a % 2 == 1){
		for(auto i : arr1) cout << i;
	}
	else{
		for(int i = 0; i < 3; i++){
			for(auto j : arr2[i]){
				cout << j;
			}
			cout << "\n";
		}
	}
}
