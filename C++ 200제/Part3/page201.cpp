#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

// c++17 부터 되네.. 

int main()
{
	if (fs::exists("C:\\Target")) {
		cout << "존재";
	}
	else {
		cout << "ㄴㄴ";
	}
}

