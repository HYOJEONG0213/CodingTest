#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fs::create_directory("temp");
	fs::copy("temp", "temp2");
	fs::remove("temp");
	fs::remove(temp2);

}
