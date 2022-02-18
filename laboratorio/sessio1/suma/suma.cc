#include <iostream>
using namespace std;

int main() {
    int num;

    while (cin >> num) {
	int sum = 0;

	while (num != 0) {
	    sum += num;
	    cin >> num;
	}

	cout << sum << endl;
    }
}
