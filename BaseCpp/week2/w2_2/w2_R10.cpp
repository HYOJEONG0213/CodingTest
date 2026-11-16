#include <iostream>
using namespace std;

char arr[3];
char mx;

int main(){
	for(int i = 0 ; i <3; i++) cin >> arr[i];
	mx = arr[0];
	for(int i = 1; i < 3; i++){
		if(mx < arr[i]){
			cout << "¿ÇÁö ¾ÊÀ½";
			return 0;
		}
	}
	
	cout << "¿Ç´Ù"<<mx; 
	
}
