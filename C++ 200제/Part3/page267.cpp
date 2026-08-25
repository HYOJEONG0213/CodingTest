#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector <int> data;
	int num = 0;
	
	try{
		num = data.at(10);
	}
	catch (exception e){
		cout << e.what() << "\n";
	}
}
