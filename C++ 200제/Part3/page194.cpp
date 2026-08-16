#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ifstream read;
	read.open("Test194.txt", ifstream::in);
	char line = read.get();
	while(read.eof() == false){
		cout << line;
		line = read.get();
	}
	
	cout << "\n";
	read.close();
}
