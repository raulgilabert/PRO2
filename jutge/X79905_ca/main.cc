#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> frequency;

    char func;
    string name;

    while (cin >> func >> name) {
	if (func == 'a')
	    ++frequency[name];
	else if (func == 'e') {
	    if (frequency[name] <= 1)
		frequency.erase(name);
	    else
		--frequency[name];
	}
	else
	    if (frequency.find(name) != frequency.end())
		cout << frequency[name] << endl;
	    else
		cout << 0 << endl;
    }
}
