#include <iostream>
using namespace std;

char arr[2][6] = {'4','5','7','1','3','2','D','F','Q','W','G','Z'};
int a;
int main(){
	cin >> a;
	for(int i = 0; i < 6; i++){
		if(arr[0][i]-'0'==a) cout << (char)arr[1][i];
	}	
}
