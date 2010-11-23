#include <list>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

typedef list<int> array;
typedef shared_ptr<array> array_ptr;

static array_ptr
merge(array_ptr a, array_ptr b)
{
	array_ptr c(new array());
	while (!a->empty() && !b->empty()) {
		if (a->front() > b->front()) {
			c->push_back(b->front());
			b->pop_front();
		} else {
			c->push_back(a->front());
			a->pop_front();
		}
	}
	while (!a->empty()) {
		c->push_back(a->front());
		a->pop_front();
	}
	while (!b->empty()) {
		c->push_back(b->front());
		b->pop_front();
	}
	return c;
}

static array_ptr
mergesort(const array_ptr a)
{
	array::size_type n = a->size();
	if (n <= 1) {
		return a;
	}
	
	array_ptr l1(new array());
	array_ptr l2(new array());
	array::size_type i = 0;
	array::const_iterator it = a->begin();
	while (i < n / 2) {
		l1->push_back(*it);
		i++;
		it++;
	}
	while (i < n) {
		l2->push_back(*it);
		i++;
		it++;
	}
	
	l1 = mergesort(l1);
	l2 = mergesort(l2);
	return merge(l1, l2);
}

/* static void
print_array(array_ptr a)
{
	array::const_iterator it;
	for (it = a->begin(); it != a->end(); it++) {
		printf("%d\n", *it);
	}
} */

int
main()
{
	int numbers[] = { 47448054, 1106251565, 1208921855, 170086026, 840395770, 444281018, 1297307905, 1613614128, 357068250, 1829657695, 654555439, 1261773796, 1821640729, 449683981, 1062536538, 96076061, 1387478498, 1835855315, 364455615, 4830124, 864633601, 289493189, 471351435, 435996916, 1366312031, 888420407, 1923379522, 735726044, 1094401518, 245520239, 109946712, 1107893495, 592868510, 700148765, 273016388, 343881444, 420725947, 1259049694, 1692920986, 71271532, 1154617350, 593508009, 1106700528, 430204045, 1045928775, 1330476642, 49983990, 1451164767, 1175404600, 644832496, 365016297, 1048732794, 503615317, 217186301, 1176160338, 1183622513, 81711049, 1720671278, 1393072097, 1315236388, 1451774341, 92848458, 271000544, 1667871288, 380233084, 1053079658, 1249341507, 1276652307, 1722015039, 1243698025, 178813868, 1449271074, 1994327579, 270972819, 1043379189, 1592595484, 462468972, 1464773315, 1994172406, 997300623, 46405283, 1614271949, 447907123, 317292284, 378291676, 1253835093, 523476912, 1606023999, 59263848, 1234358080, 140981643, 1828471854, 1197394207, 1317927546, 878287915, 334576359, 982149842, 642878238, 1024064999, 1834342299 };
	
	array_ptr a(new array());
	unsigned int i;
	for (i = 0; i < sizeof(numbers) / sizeof(int); i++) {
		a->push_back(numbers[i]);
	}
	
	i = 0;
	while (i < 3000) {
		mergesort(a);
		i++;
	}
	return 0;
}