#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a = "The Jin state was formed in southern Korea by the 3rd century BC";
	int ret = 0;
	for(int i = 0 ; i < a.size(); i++){
		if(a[i]=='a') ret++;
	}
	cout << ret;

}
