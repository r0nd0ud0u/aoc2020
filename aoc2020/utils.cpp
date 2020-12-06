#include "utils.h"
#include <sstream>

using namespace std;
utils::utils()
{
}

utils::~utils()
{

}

void utils::split(const string &content, char pattern, vector<string> &elements)
{
    stringstream ss(content);
    string str;
    while (getline(ss, str, pattern))
    {
        elements.push_back(str);
    }
}