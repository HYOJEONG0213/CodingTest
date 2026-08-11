#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum  = 0;
	time_t start = time(NULL);
	time_t end = time(NULL);
	
	time(&start);
	
	for(int i = 0; i < 1000000000; i++){
		sum++;
	}
	
	time(&end);
	cout << "걸린시간 : " << difftime(end, start);
}
