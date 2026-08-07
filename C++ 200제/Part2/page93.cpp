#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a = 10;
	int i = 0;
	while(i <= a){
		if(i%3==0) {
			i++;
			continue;
		}
		cout << i << " ";
		i++;
	}
}
