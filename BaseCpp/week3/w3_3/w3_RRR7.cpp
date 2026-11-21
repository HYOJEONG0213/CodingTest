#include <iostream>
using namespace std;

char arr[3][3] = {'a', 'b', 'E', 'E', '2', 'W', '3', '2', '4'};

int main(){
	for(int i = 0 ; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(isupper(arr[i][j])) cout << (char)(arr[i][j]-'A'+'a')<< " ";
			else if(islower(arr[i][j])) cout << (char)(arr[i][j]-'a'+'A') << " ";
			else cout << arr[i][j]-'0'+5 << " ";
		}
		cout << "\n";
	}
}
