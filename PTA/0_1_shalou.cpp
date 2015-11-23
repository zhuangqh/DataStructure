#include <iostream>
#include <cmath>
using namespace std;

void printTuan(int n, char tuan) {
  for (int i = n; i >= 1; --i) {

    for (int j = 0; j < n - i; ++j)
      std::cout << ' ';

    for (int j = 0; j < 2*i - 1; ++j)
      std::cout << tuan;

    std::cout << std::endl;
  }

  for (int i = 2; i <= n; ++i) {

    for (int j = 0; j < n - i; ++j)
      std::cout << ' ';

    for (int j = 0; j < 2*i - 1; ++j)
      std::cout << tuan;

    std::cout << std::endl;
  }
}

int main() {
  int num;
  char tuan;
  std::cin >> num >> tuan;

  int n = static_cast<int>(sqrt((num+1)/2));
  //std::cout << n << std::endl;
  printTuan(n, tuan);

  std::cout << (num + 1 - 2*n*n) << std::endl;
}
