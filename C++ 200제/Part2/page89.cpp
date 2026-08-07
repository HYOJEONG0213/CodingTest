#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int data[10] = {5,19,76,3,10,89,54,43,2,17};
	for(int i = 0; i < 10; i++){
		if(data[i]%2==0) cout << "Â¦¼ö ";
		else cout << "È¦¼ö ";
	}
}
