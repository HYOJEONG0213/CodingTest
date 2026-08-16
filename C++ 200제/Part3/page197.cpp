#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ifstream ifs("Test194.txt");
	stringstream ss;
	ss << ifs.rdbuf();
	ifs.close();
	
	string read = "";
	while(!ss.eof()){
		ss >> read;
		cout << read;
	}
	
	cout << "\n\n";
	read = ss.str();
	cout << read;
	
}
