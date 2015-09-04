#include <iostream>
#include <vector>

using namespace std;
vector<int> arr;

int hole;
int cursize;

void insert(int x) {
	hole = ++cursize;
	
	for ( ; x < arr[hole / 2]; hole /= 2) {
		arr[hole] = arr[hole/2];
	}
	
	arr[hole] = x;
}

int main() {
	// initialize
	int n, query;
	cin >> n >> query;
	arr.assign(n+1, 0);
	cursize = 0;
	arr[0] = -100000;

	// read in data
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		insert(temp);
	}
	
	// query
	for (int i = 0; i < query; ++i) {
		int index;
		cin >> index;
		bool isfirst = true;

		while (index >= 1) {
			if (isfirst) isfirst = false;
			else cout << " ";
			cout << arr[index];
			
			index /= 2;
		}
		cout << endl;
	}
	return 0;
}
