#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> data;

    bool error = false;

    char symbol;
    cin >> symbol;

    while (not error and symbol != '.') {
	if (symbol == '(' or symbol == '[')
	    data.push(symbol);
	else {
	    if (not (data.empty() or (symbol == ')' and data.top() != '(') or 
		    (symbol == ']' and data.top() != '[')))
		data.pop();
	    else
		error = true;
	}

	cin >> symbol;
    }

    if (error or not data.empty())
	cout << "Incorrecte" << endl;
    else
	cout << "Correcte" << endl;

}
