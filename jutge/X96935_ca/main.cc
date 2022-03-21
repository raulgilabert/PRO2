#include <iostream>
#include <stack>

using namespace std;


stack<int> read() {
    int n;
    cin >> n;

    stack<int> data;

    bool extra = (n%2 == 1);

    n /= 2;

    for (int i = 0; i < n; ++i) {
	int num;
	cin >> num;
	data.push(num);
    }

    if (extra) {
	int num;
	cin >> num;
    }

    return data;
}

bool check_palindrome(stack<int>& data) {
    bool found = false;

    while (not found and not data.empty()) {
	int num;
	cin >> num;

	if (num != data.top())
	    found = true;

	data.pop();
    }

    return not found;
}


int main() {
    stack<int> data = read();
    bool palindrome = check_palindrome(data);

    if (palindrome)
	cout << "SI" << endl;
    else
	cout << "NO" << endl;
}
