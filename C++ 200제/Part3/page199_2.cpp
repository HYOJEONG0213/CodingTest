#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	const string file_path = "Test199.txt";
	ofstream ofs(file_path, ifstream::out);
	ofs << "Test1\n";
	ofs << "Test2\n";
	ofs.close();
	
	ifstream ifs(file_path, ifstream::in);
	string line="";
	while(getline(ifs, line)){
		cout << line << "\n";
	}
	ifs.close();
}
