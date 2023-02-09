#include <iostream>
#include <vector>
using namespace std;
#include "Header.h"
int main()
{
	multiset m;
	m.insert(100);
	m.insert(150);
	m.insert(113);
	m.insert(-123);
	m.insert(100);
	m.insert(-200);
	cout <<"multiset: "<< m;
	m.erase(-200);
	cout <<"multiset after erase: "<< m;
	//cout <<"Number of 1:"<< m.find(1) << endl;
	cout << "Number of 100:"<<m.find(100) << endl;
	//m.get();
	//m.load();
	//cout << "multiset: " << m;	
}