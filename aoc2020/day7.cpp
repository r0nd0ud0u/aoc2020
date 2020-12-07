#include "day7.h"
#include <sstream>
#include "utils.h"
#include "math.h"

using namespace std;

struct tree 
{ 
	string value; 
	std::vector<tree> children; 
};


day7::day7()
{
}

day7::~day7()
{

}

void day7::JigglypuffSwallow()
{
    ifstream file("puzzles/puzzle_day07.txt", ios::in);
    int result = 0;
	if (file.is_open())
	{
        string line;
        
		while (getline(file, line))
        {
            vector<string> bags;
            utils::split(line,' ',bags);
            for(int i=5;i<bags.size();i=i+4)
            {
                m_Tree[bags[0]+' '+bags[1]].push_back(bags[i]+ " " + bags[i+1]);
            }
        }

        for(auto it : m_Tree)
        {
            for(auto it2 : it.second)
            {
                bool isShiny = containsShiny(it2);
                if(isShiny)
                {
                    result++;
                    break;
                }
            }
        }
        cout << result << endl;
        file.close();  
	}
}

bool day7::containsShiny( string key)
{
    string str = "shiny gold";
    vector<string> value = m_Tree[key];
    if(key == str)
        return true;
    for(auto it : m_Tree[key])
    {
        if(it == "other bags.")
                continue;
        if(it == str)
                return true;
        bool isShiny = containsShiny(it);
        if(isShiny)
            return true;
    }
    return false;
}

void day7::JigglypuffSwallow2()
{
    ifstream file("puzzles/puzzle_day07.txt", ios::in);
    int result2 = 0;
	if (file.is_open())
	{
        string line;
        
		while (getline(file, line))
        {
            vector<string> bags;
            utils::split(line,' ',bags);
            
            for(int i=4;i<bags.size();i=i+4)
            {
                bag bag;
                bag.bagColor = bags[i+1]+ " " + bags[i+2];
                bag.nbs = atoi(bags[i].c_str());
                m_Tree2[bags[0]+' '+bags[1]].push_back(bag);

            }
        }

        for(auto it : m_Tree2["shiny gold"])
        {
            result2 += it.nbs + it.nbs*CalculNbOfBags(it);
        }
        cout << result2 << endl;
        file.close();  
	}
}

int day7::CalculNbOfBags(bag key)
{
    int nb =0;
    for(auto it : m_Tree2[key.bagColor])
    {
        if(it.bagColor == "other bags.")
            return 0;
        nb += it.nbs + it.nbs*CalculNbOfBags(it);
        cout <<key.bagColor<<"  :"<< nb << endl;
    }
    return nb;
}