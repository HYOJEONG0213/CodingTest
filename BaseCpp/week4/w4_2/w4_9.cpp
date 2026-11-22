#include <iostream>
using namespace std;

char arr[4][5];

int main(){
	for(int i = 0 ; i < 4; i++){
		cin >> arr[i];
		int j = 0;
		bool flagA = false, flagB = false;
		
		while(arr[i][j] != '\0'){
			if(arr[i][j]=='A') flagA = true;
			if(arr[i][j]=='B') flagB = true;
			j++;
		}
		
		if(flagA && flagB) cout << "대발견\n";
		else if(flagA || flagB) cout <<"중발견\n";
		else cout << "미발견\n";
	}
}
