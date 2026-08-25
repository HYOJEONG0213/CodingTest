#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector <int> data;
	data.push_back(1);
	
	try{
		if(data.empty()){
			throw "บคลอบ๖";
		}
		
		if(data.size() < 2){
			throw 99;
		}
	}
	catch (char * e){
		cout << "catch char * e : " << e << "\n";
	}
	catch (int e){
		cout << "catch int e : " << e << "\n";
	}
}
