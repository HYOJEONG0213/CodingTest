#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string directory = "C:\\Program Files";
	for(auto & name : fs::directory_iterator(directory)){
		cout << name << "\n";
	} 

}
