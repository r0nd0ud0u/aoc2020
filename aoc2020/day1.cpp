#include "day1.h"

using namespace std;
day1::day1()
{
}


day1::~day1()
{
}


void day1::JigglypuffSing()
{
	int result1(0), result2 = 0;
	vector<int> listNumbers;
	ifstream file("puzzles/puzzle_day1.txt", ios::in);
	if (file)
	{
		string line;
		while (getline(file, line))
			listNumbers.push_back(atoi(line.c_str()));
	}
	result1 = CalculStar1(listNumbers);
	result2 = CalculStar2(listNumbers);
	int result1Faster = CalculStar1better(listNumbers);
	int result2Faster = CalculStar2better(listNumbers);
	cout << "Hi I am Jigglypuff, a Balloon Pokemon. I have a large friendly eyes and  sing a pleasant song " << endl;
	cout << result1 << " " << result2 << endl;
	cout << result1Faster << endl;
	cout << result2Faster << endl;
}


int day1::CalculStar1(const vector<int> & vect)
{
	for (auto i : vect)
	{
		if (i >= 2020)
			break;
		for (auto j : vect)
		{
			if (i + j == 2020)
				return i * j;
		}
	}
	return 0;
}


int day1::CalculStar2(const vector<int> & vect)
{
	for (auto i : vect)
	{
		if (i >= 2020)
			continue;
		for (auto j : vect)
		{
			if (i + j >= 2020)
				continue;
			for (auto k : vect)
			{
				if (i + j + k == 2020)
					return i * j * k;
			}
		}
	}
	return 0;
}

int day1::CalculStar1better(vector<int> & v)
{
	for (int i = 0; i < v.size(); i++) {
		std::vector<int>::iterator it = find(v.begin(), v.end(), 2020 - v[i]);
		if (it != v.end())
			return v[i] * (*it);
	}

	return 0;
}

int day1::CalculStar2better(vector<int> & v)
{
	for (int i = 0; i < v.size(); i++) {
		for (int j = i; j < v.size(); j++)
		{
			vector<int>::iterator it = find(v.begin(), v.end(), 2020 - v[i] - v[j]);
			if (it != v.end())
				return v[i] * v[j] * (*it);
		}
	}
	return 0;
}