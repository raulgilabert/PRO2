#include <iostream>
#include <stack>
#include <vector>

using namespace std;







int main() {
    int n;
    cin >> n;

    vector<stack<string> > data(n);

    int function;
    cin >> function;

    while (function != -4) {
	if (function == -1) {
	    string name;
	    int id;

	    cin >> name >> id;
	    data[id - 1].push(name);
	}
	else if (function == -2) {
	    int n, id;
	    cin >> n >> id;

	    for (int i = 0; i < n; ++i)
		data[id - 1].pop();
	}
	else {
	    int id;
	    cin >> id;

	    stack<string> tmp = data[id - 1];

	    int size = tmp.size();

	    cout << "Pila de la categoria " << id << endl;

	    for (int i = 0; i < size; ++i) {
		cout << data[id - 1].top() << endl;
		data[id - 1].pop();
	    }

	    data[id - 1] = tmp;
	    
	    cout << endl;
	}

	cin >> function;
    }
}
