#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <list>
class day7
{
public:
    day7();
	~day7();
    void JigglypuffSwallow();
    std::map<std::string, std::vector<std::string>> m_Tree;
    bool containsShiny( std::string key);
    void JigglypuffSwallow2();

    struct bag 
    { 
        int nbs; 
        std::string bagColor; 
    };
    int CalculNbOfBags(bag key);
    std::map<std::string, std::vector<bag>> m_Tree2;

};;