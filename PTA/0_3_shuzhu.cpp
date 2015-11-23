#include <vector>
#include <iostream>

using namespace std;

int main() {
    // input data
    int N, M;
    cin >> N >> M;

    vector<int> v;
    while (N--) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    // manipulate
    int ki, kongwei = v[0];
    for (int i = 0; i < M; ++i) {
        for (int j = (ki-1+v.size()) % v.size(); j != ki; ) {
            if (j == ki) continue;
            v[(j + 1) % v.size()] = v[j];
            j = (j-1+v.size()) % v.size();
        }

        ki = (ki + 1) % v.size();
    }

    v[M % v.size()] = kongwei;

    // format output
    bool first = true;
    for (int i = 0; i < v.size(); ++i) {
        if (first) first = false;
        else cout << ' ';

        cout << v[i];
    }
    cout << std::endl;
    return 0;
}
