#include <iostream>
using namespace std;

int vect[7] = {3,5,1,1,2,3,2};
int a[4], b;

int main(){
	for(int i = 0; i < 4; i++){
		cin >> b;
		for(int j = 0; j < 7; j++){
			if(vect[j]==b){
				a[i]++;
			}
		}
	}
	
	for(int i = 0; i < 4; i++) {
		cout << a[i] << " ";
	}
}
