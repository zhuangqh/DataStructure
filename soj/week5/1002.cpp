#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > ans;
        vector<int> temp;

void comb(int cur, int k, int level) {
    if (level > m || k < 0) {
        return;
    }

    if (k == 0) {
        ans.push_back(temp);
        return;
    }

    for (int i = cur; i > 0; --i) {
        temp.push_back(i);
        comb(i, k-i, level+1);
        temp.pop_back();
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        temp.clear();
        cin >> n >> m;
        comb(n, n, 0);

        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < ans[i].size(); ++j)
                cout << ans[i][j];

            if (ans[i].size() < m) {
                for (int j = ans[i].size(); j < m; ++j)
                    cout << 0;
            }
            cout << endl;
        }
    }
}