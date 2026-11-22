#include <iostream>
using namespace std;

string s;

int main(){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		int mn = s[i], mnIdx = i;
		for(int j = i+1; j < s.size(); j++){
			if(mn > s[j]){
				mn = s[j];
				mnIdx = j;
			}
		}
		swap(s[i], s[mnIdx]);
	}
	
	cout << s;
}
