#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fs::remove("Test194.txt");
	fs::remove("Test205.txt");
	ofstream file("Test194.txt", ifstream::out);
	file << "Test1";
	file << "Test2";
	file.close();
	fs::copy("Test194.txt", "Test205.txt");

}
