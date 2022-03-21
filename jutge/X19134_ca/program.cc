#include "LlistaIOParInt.hh"
#include "ParInt.hh"

int main() {
    list<ParInt> l;
    LlegirLlistaParInt(l);

    int n;
    cin >> n;

    list<ParInt>::iterator it = l.begin();
    list<ParInt>::iterator end = l.end();

    int counter = 0, sum = 0;

    while (it != end) {
	if ((*it).primer() == n) {
	    ++counter;
	    sum += (*it).segon();
	}

	++it;
    }

    cout << n << ' ' << counter << ' ' << sum << endl;
}
