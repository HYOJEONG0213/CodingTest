#include <iostream>
using namespace std;

char c[3][6] = {"POTIO","ABCDE","YOURE"};
int a,b;

int main(){
	cin >> a >> b;
	for(int j = 0 ; j < 3; j++){
		for(int i = a; i <= b; i++){
			cout << c[j][i];
		}
	}
}
