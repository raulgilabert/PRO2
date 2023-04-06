#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> frequency;

    string func, name;

    while (cin >> func >> name) {
	if (func == "a")
	    ++frequency[name];
	else
	    if (frequency.find(name) != frequency.end())
		cout << frequency[name] << endl;
	    else
		cout << 0 << endl;
    }
}
