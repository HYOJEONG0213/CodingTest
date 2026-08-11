#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "rabbit";
	string b = "rabbit";
	string c = "rebbit";
	
	if(a==b){
		cout << "같다!\n";
	}
	else{
		cout << "다르다! \n"; 
	}
	
	if(a==c){
		cout << "같다!\n";
	}
	else{
		cout << "다르다! \n"; 
	}
	
	if(a.compare(b)==0){
		cout << "같다!\n";
	}
	else{
		cout << "다르다! \n"; 
	}
}
