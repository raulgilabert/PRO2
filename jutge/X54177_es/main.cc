#include <iostream>

using namespace std;

int main() {
    int n, x;

    cin >> n >> x;

    for (int i = 1; i <= n; ++i) {
	int num, sum = 0;

	while (cin >> num and num != x)
	    sum += num;

	cout << "La suma de la secuencia " << i << " es " << sum << endl;
	sum = 0;
	string blank;
	getline(cin, blank);
    }
}
