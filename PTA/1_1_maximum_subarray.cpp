#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> num;
    while (t--) {
        int temp;
        std::cin >> temp;
        num.push_back(temp);
    }

    int sum = 0, maxs = 0;
    for (int i = 0; i < num.size(); ++i) {
        sum += num[i];
        if (sum < 0) sum = 0;
        maxs = std::max(sum, maxs);
    }

    std::cout << maxs << std::endl;
    return 0;
}
