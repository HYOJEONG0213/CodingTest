#include <iostream>
using namespace std;

char arr[3], cnt;

int main(){
	for(int i = 0; i < 3; i++){
		cin >> arr[i];
		if(isupper(arr[i])) cnt++;
	}
	
	if(cnt == 3) cout << "풍족하다";
	else if(cnt >=1 && cnt <=2) cout << "적절하다";
	else cout << "부족하다 ";
}
