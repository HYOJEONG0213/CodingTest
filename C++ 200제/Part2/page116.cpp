#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	time_t now = time(NULL);
	tm * ptm = localtime(&now);
	
	char buffer[64];
	strftime(buffer, 64, "현재 %Y.%m.%d, %H::%M::%S 이다. (%p)\n", ptm);
	
	cout << buffer;
}
