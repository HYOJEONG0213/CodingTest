#include <iostream>
using namespace std;

char arr1[2][5];
char arr2[12];
int arr2Idx;

int main(){
	for(int i = 0 ; i < 2; i++){
		cin >> arr1[i];
		
		int j = 0;
		while(arr1[i][j] != '\0'){
			arr2[arr2Idx++] = arr1[i][j];
			j++;
		}
	}
	
	for(int i = 0; i < arr2Idx; i++) cout << arr2[i];
}
