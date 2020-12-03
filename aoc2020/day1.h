//#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
class day1
{
public:
	day1();
	~day1();
	int CalculStar1(const std::vector<int> & vect);
	int CalculStar2(const std::vector<int> & vect);

	int CalculStar1better(std::vector<int> & vect);
	int CalculStar2better(std::vector<int> & vect);
	void JigglypuffSing();
};

