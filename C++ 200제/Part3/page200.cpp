#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

// dev c++ gcc 버전이 너무 낮아서 실행이 안됌 ㅜㅜ  
// 비주얼가서 c++17 로 설정 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fs::current_path();

}
