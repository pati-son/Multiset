#pragma once
/*–еализовать multiset.
bool insert(int value)
int find(int value) //возвращает количество
void erase(int value) //удал€ет один экземпл€р записи  
operator<< дл€ вывода на экран*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class multiset
{
private:
	std::vector <int> v;

public:
	multiset();
	~multiset();
	bool insert(int value);
	int find(int value); 
	void erase(int value);
	void load();// загружает multiset из файла
	int cap();
	friend ostream& operator<<(ostream& out, const multiset& m)
	{
		for (int i = 0; i < m.v.size(); i++)
		{
			out << m.v[i] << " ";
		}
		out << endl;
		return out;
	};
	/*friend istream& operator>>(istream& cin, multiset& m)
	{
		cin >> m.v.pop_back();
		return cin;
	}*/
	
	void sort();
};

multiset::multiset()
{
	v.reserve(1);
}

multiset::~multiset()
{
	v.clear();
}



bool multiset::insert(int value)
{
	if (v.size() < v.capacity())
	{
		v.push_back(value);
		if (v.size() == v.capacity())
		{
			v.reserve(v.capacity() * 2);
		}
		sort();
		return true;
	}
	else return false;
}

int multiset::find(int key)
{
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == key)
			count++;
	}
	return count;
}

void multiset::erase(int value)
{
	for (int i = 0; i <= v.size() - 1; i++)
	{
		int k = 0;
		if (v[i] == value)
		{
			int j;
			for (j = i; j <= v.size() - 2; j++) {
				swap(v[j + 1], v[j]);  // 1 3 6 7 4       5   j = 4 
			}
			
			v.pop_back();
			k = 1;
		}
		if (k == 1)
		{
			break;
		}
	}
}

void multiset::sort()
{
	for (int i = 0; i < v.size() - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[j] < v[min])
			{
				min = j;
			}
		}
	
		swap(v[i], v[min]);
	}
}

int multiset::cap()
{
	return v.capacity();
}

void multiset::load()
{
	ifstream file;
	file.open("C:\\Users\\User\\source\\repos\\lab_18_a\\lab_18_a\\elements.txt");
	if (!file.is_open())
	{
		cout << "error";
	}
	while (!file.eof())
	{
		int a;
		file >> a;
		v.push_back(a);

	}
	file.close();
	/*for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}*/
}

