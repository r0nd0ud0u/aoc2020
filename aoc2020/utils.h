#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
class utils
{
public:
    utils();
	~utils();
    static void split(const std::string &content, char pattern, std::vector<std::string> &elements);
};;