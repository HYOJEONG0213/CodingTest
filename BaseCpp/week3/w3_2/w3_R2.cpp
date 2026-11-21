#include <iostream>
#include <vector>
using namespace std;

char arr[5];
int cnt;
vector <int> v;

int main(){
	for(int i = 0 ; i < 5; i++) {
		cin >> arr[i];	
		if(arr[i]=='A') {
			cnt++;
			v.push_back(i);
		}
	}
	cout << cnt << "\n";
	for(auto i : v) cout << i << "\n";
	
}
