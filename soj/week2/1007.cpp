#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  int v[26] = {2, 2*2, 2*3, 3, 3*2, 3*3, 4, 4*2, 4*3, 5, 5*2, 5*3,
               6, 6*2, 6*3, 7, 7*2, 7*3, 7*4, 8, 8*2, 8*3, 9, 9*2,
               9*3, 9*4};
  while (t--) {
    char str[200];
    scanf("%s", str);
    int sum = 0;
    for (int i = 0; i < strlen(str); ++i) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        sum += v[str[i] - 'a'];
      } else {
        sum += v[str[i] - 'A'];
      }
    }

    printf("%d\n", sum);
  }
}
