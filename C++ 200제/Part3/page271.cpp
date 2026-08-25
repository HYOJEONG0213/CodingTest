#include <bits/stdc++.h>
using namespace std;

class InputError : public runtime_error{
public:
	InputError(int idx, string msg) : runtime_error(""){
		cout << idx << " 해당 인덱스에 잘못된 입력값 들어감 : " << msg << "\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector <int> data;
	data.push_back(1);
	
	int idx = 10;
	int value = 20;
	
	try{
		if(idx >= data.size())
			throw InputError(idx, to_string(value));
		
		data.at(idx) = 99; 
	}
	catch (InputError e){
		cout << " hi";
		cout << e.what();
	}
}
