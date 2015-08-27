#include <iostream>
#include <vector>
#include <string>
int main() {
    std::string num;
    std::cin >> num;

    int digits[10] = {0};

    for (int i = 0; i < num.size(); ++i) {
        ++digits[num[i] - '0'];
    }

    int jinwei = 0;
    for (int i = num.size()-1; i >= 0; --i) {
        int temp = (num[i] - '0') * 2 + jinwei;
        --digits[temp % 10];
        num[i] = temp % 10 + '0';
        jinwei = temp / 10;
    }

    --digits[jinwei];

    bool flag = true;
    for (int i = 1; i <= 9; ++i) {
        if (digits[i]) {
            flag = false;
            break;
        }
    }
    std::cout << (flag ? "Yes\n" : "No\n");
    if (jinwei) std::cout << jinwei;
    std::cout << num << std::endl;
}
