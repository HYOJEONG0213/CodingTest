#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a = 100;
	int b = 200;
	int c = 300;
	int ret = 0;
	if(a > b && a > c){
		ret=a;
	}
	else if(b > a && b > c){
		ret = b;
	}
	else if(c > a && c > b){
		ret = c;
	}
	else{
		cout << "없음";
		return 0;
	}
	cout << "가장 큰 수 :" << ret; 

}
