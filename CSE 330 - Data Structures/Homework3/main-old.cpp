#include <iostream>
#include <list>
#include <iterator>

using namespace std;



template<class Itr>
void inplaceMerge( Itr low, Itr mid, Itr high)
{

	//int dist = distance(low,high);
	list<typename iterator_traits<Itr>::value_type> temp; //(dist);
	Itr i = low;
	Itr j = mid;
	Itr k = temp.begin();

	while (*i < *mid && *j < *high)
		if (*i < *j) {
			*k = *i;
			k++;
			i++;
		}
		else
        {
			*k = *j;
            k++;
            j++;
		}
	while (*i < *mid)
    {
        *k = *i;
        k++;
        i++;
    }
	while (*j < *high)
    {
        *k = *j;
        k++;
        j++;
    }
	for (k = temp.begin(), i = low; k != temp.end(); k++, i++)
		*i = *k;

} // inplaceMerge


template <class Itr>
void m_sort(Itr start, unsigned int low, unsigned int high)
{
	if (low + 1 < high) {
		unsigned int center = (low + high) / 2;
		m_sort(start, low, center);
		m_sort(start, center, high);
		Itr L = next( start,low );
		Itr C = next( start,center );
		Itr H = next( start,high );
		inplaceMerge( L,C,H );
	}
} // m_sort

template <class T>
void mergeSort(list<T> & s)
{
	m_sort(s.begin(), 0, s.size());
} // mergeSort


int main()
{
    list<int> v;
	int temp;

	while (cin >> temp)
		v.push_back(temp);

	mergeSort(v);

	for (unsigned int i = 0; i < v.size(); i++) {
		cout << v.front() << ' ';
		v.pop_front();
	}
	cout << endl;
} // main
