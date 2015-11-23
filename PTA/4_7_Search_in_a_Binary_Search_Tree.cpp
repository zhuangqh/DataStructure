#include <iostream>
bool is_in_BST(int*, int);

int main() {
  int m, n;
  int keys_seq[150];
  std::cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> keys_seq[j];
    }
    std::cout << (is_in_BST(keys_seq, n) ? "YES" : "NO") << std::endl;
  }
  return 0;
}

bool is_in_BST(int num[], int N) {
  for (int i = 0; i < N - 1; ++i) {
    if (num[i] > num[i + 1]) {
      for (int j = i + 1; j < N; ++j) {
        if (num[i] < num[j]) return false;
      }
    } else {
      for (int j = i + 1; j < N; ++j) {
        if (num[i] > num[j]) return false;
      }
    }
  }
  return true;
}
