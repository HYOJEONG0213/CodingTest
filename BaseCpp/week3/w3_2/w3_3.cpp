#include <iostream>
using namespace std;

char arr[6] = {'A', 'F', 'G', 'A', 'B', 'C'};
char a, b;
bool flag1 = false, flag2 = false; 

int main(){
	cin >> a >> b;
	
	for(int i = 0 ; i < 6; i++){
		if(arr[i] == a) flag1 = true;
		else if(arr[i]==b) flag2 = true;
	}
	if(flag1+flag2 == 2) cout << "와2개";
	else if(flag1+flag2 == 1) cout << " 오1개";
	else cout << "우0개";
}
