#include <vector>
using namespace std;

struct parint {int prim, seg;};

parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    parint value;

    int num = v.size();

    value.prim = value.seg = v[0];

    for (int i = 1; i < num; ++i) {
	if (v[i] < value.prim)
	    value.seg = v[i];
	else if (v[i] > value.seg)
	    value.prim = v[i];
    }

    return value;
}

pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    pair<int, int> value;

    int num = v.size();

    value.first = value.second = v[0];

    for (int i = 1; i < num; ++i) {
	if (v[i] < value.second)
	    value.second = v[i];
	else if (v[i] > value.first)
	    value.first = v[i];
    }

    return value;
}

void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    int num = v.size();

    x = y = v[0];

    for (int i = 1; i < num; ++i) {
	if (v[i] < y)
	    y = v[i];
	else if (v[i] > x)
	    x = v[i];
    }
}
