#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a = 10;
	int i = 0;
	do{
		i++;
		if(i%3==0) continue;
		cout << i << " ";
	}while(i < a);
}
