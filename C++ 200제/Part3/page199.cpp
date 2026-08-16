#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	const string file_name = "Test199";
	
	ofstream file_out;
	file_out.open(file_name, iostream::out);
	
	file_out << "Test1 \n";
	file_out << "Test2 \n";
	
	file_out.close();
	
	ifstream file_in;
	file_in.open(file_name, ifstream::in);
	string line;
	while(getline(file_in, line)){
		cout << line << "\n";
	}
	
}
