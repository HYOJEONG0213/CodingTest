#include <bits/stdc++.h>
using namespace std;

constexpr int GetNumber(){
	return 2;
}
constexpr int GetNumber2(int x, int y){
	return x+y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int arr1[GetNumber()];
	int arr2[GetNumber2(2,3)];
	
	cout << sizeof(arr1) << " " << sizeof(arr2) << "\n";
	
}
