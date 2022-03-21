#include <iostream>
#include <queue>

using namespace std;


void calc(queue<int> data) {
    if (data.empty())
	cout << 0 << endl;
    else {
	int num = data.front(), min = num, max = num, size = data.size(), 
	    sum = num;

	data.pop();

	while (not data.empty()) {
	    num = data.front();

	    if (num > max)
		max = num;
	    else if (num < min)
		min = num;

	    sum += num;

	    data.pop();
	}

	cout << "min " << min << "; max " << max << "; media " <<
	    sum/double(size) << endl;
    }
}


int main() {
    queue<int> data;

    int num;
    cin >> num;

    while (num >= -1001 and num < 1001) {
	if (num != -1001)
	    data.push(num);
	else if (num == -1001 and not data.empty())
	    data.pop();

	calc(data);

	cin >> num;
    }
}
