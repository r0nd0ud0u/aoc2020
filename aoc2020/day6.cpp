#include "day6.h"
#include <sstream>
#include "utils.h"
#include "math.h"

using namespace std;




day6::day6()
{
}

day6::~day6()
{

}

void day6::JigglypuffEchoedVoice()
{
    ifstream file("puzzles/puzzle_day06.txt", ios::in);
    
	if (file.is_open())
	{
        string line;
        map<int,int> yesAnswerList;
        int result1(0), result2(0);
        int nbs = 0;
		while (getline(file, line))
        {
            for(auto it : line)
            {
                if(yesAnswerList.find(it) == yesAnswerList.end())
                    yesAnswerList[it] = 1;  
                else
                {
                    yesAnswerList[it] += 1; 
                }    
            }
            if(line.length()==0)
            {
                result1 += yesAnswerList.size();
                for(auto it2 :yesAnswerList )
                {
                    if(it2.second == nbs)
                        result2++;
                }
                nbs =0;
                yesAnswerList.clear();
            }
            else
            {
                nbs++;
            }    
        }
        if(yesAnswerList.size()>0)
        {
            result1 += yesAnswerList.size();
             for(auto it2 :yesAnswerList )
            {
                if(it2.second == nbs)
                    result2++;
            }
        }
        cout <<"result1 "<< result1<<endl;
        cout <<"result2 "<< result2<<endl;
        file.close();  
	}
}