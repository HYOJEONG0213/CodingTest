#include <iostream>
using namespace std;

char arr[8], big[8], small[8];
int b, s;

int main(){
	for(int i = 0 ; i < 8; i++) cin >> arr[i];
	
	for(int i = 0 ; i < 8; i++){
		if(isupper(arr[i])){
			big[b++] = arr[i];
		}
		else{
			small[s++] = arr[i];
		}
	}
	
	for(int i = 0 ; i < b; i++) cout << big[i];
	cout << "\n";
	for(int i = 0 ; i < s; i++) cout << small[i];
}
