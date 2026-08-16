#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ifstream ifs("C:\\Users\\JEONG\\Documents\\GitHub\\CodingTest\\C++ 200제\\Part3\\Test194.txt");
	if (ifs.good()) {
		cout << "존재";
	}
	else {
		cout << "없음";
	}

}
