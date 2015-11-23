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

    int sum = 0, maxs = 0, pre, post, m_pre, m_post;
    pre = post = 0;
    m_pre = m_post = -1;

    for (int i = 0; i < num.size(); ++i) {
        sum += num[i];
        post = i;
        if (sum < 0) {
            pre = post = i + 1;
            sum = 0;
        }

        if (sum > maxs || (m_pre == -1 && sum == 0)) {
            m_pre = pre;
            m_post = post;
            maxs = sum;
        }
    }

    std::cout << maxs << ' ';
    if (m_pre == -1)
        std::cout << num[0] << ' ' << num[num.size()-1] << std::endl;
    else
        std::cout << num[m_pre] << ' ' << num[m_post] << std::endl;
    return 0;
}
