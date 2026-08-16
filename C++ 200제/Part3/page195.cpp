#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ifstream file;
	file.open("Test194.txt", ifstream::in);
	string line ;
	while(getline(file, line)){
		cout << line << "\n";
	}
	
	file.close();
}
