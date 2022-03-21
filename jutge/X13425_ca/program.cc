#include "CuaIOParInt.hh"


void divide(queue<ParInt>& data, queue<ParInt>& first, queue<ParInt>& second) {
    int first_counter = 0, second_counter = 0;


    while (not data.empty()) {
	ParInt user = data.front();

	if (first_counter + user.segon() <= second_counter + user.segon()) {
	    first.push(user);
	    first_counter += user.segon();
	    
	}
	else {
	    second.push(user);
	    second_counter += user.segon();
	}

	data.pop();
    }
}


int main() {
    queue<ParInt> data;
    llegirCuaParInt(data);

    queue<ParInt> first;
    queue<ParInt> second;

    divide(data, first, second);

    escriureCuaParInt(first);
    cout << endl;
    escriureCuaParInt(second);
}
