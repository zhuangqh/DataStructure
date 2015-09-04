#include <iostream>
#include <vector>
#include <set>

using namespace std;

class disjointSet {
private:
	vector<int> father;
public:
	explicit disjointSet(int n) {
		father.resize(n);
		for (int i = 0; i <= n; ++i) {
			father[i] = i;
		}
	}
	int findRoot(int x);
	void join(int x, int y);
};

int disjointSet::findRoot(int x) {
	int root = x;
	// find root
	while (father[root] != root) {
		root = father[root];
	}
	
	// reset the destructure of this disjointSet
	int ptr = x;
	while (ptr != root) {
		int temp = father[ptr];
		father[ptr] = root;
		ptr = temp;
	}
	
	return root;
}

void disjointSet::join(int x, int y) {
	int fx = findRoot(x), fy = findRoot(y);
	if (fx != fy)
		father[fx] = fy;
}

int main() {
	int n;
	cin >> n;
	
	disjointSet ss(n);
	
	char op;
	while (cin >> op && op != 'S') {
		int x, y;
		cin >> x >> y;

		if (op == 'C') {
			if (ss.findRoot(x) != ss.findRoot(y))
				cout << "no\n";
			else
				cout << "yes\n";
		} else if (op == 'I') {
			ss.join(x, y);
		}
	}
	
	set<int> count;
	for (int i = 1; i <= n; ++i) {
		count.insert(ss.findRoot(i));
	}
	
	if (count.size() == 1) {
		cout << "The network is connected.\n";
	} else {
		cout << "There are " << count.size() << " components.\n";
	}
}
