#include "day3.h"
#include <sstream>

using namespace std;
day3::day3()
{
}

int day3::JigglypuffSweetKiss1(int right, int down)
{
    //cout << "I will use all my charm todayyyyyyyyyyyyyy <3" << endl;
    int goodPasswords =0;
    vector<string> passwords;
    ifstream file("puzzles/puzzle_day03.txt", ios::in);
    
    int nbSquare(0), nbTree(0);
    int x(0);
	if (file.is_open())
	{
		string line;
        getline(file, line);
        if(down==2)
            getline(file, line);
        int len = line.length();
		while (getline(file, line))
        {
            x +=right;
            if(x >=len)
                x = x - len ;
            if(line[x] =='#')
                nbTree++; 
            if(down==2)
                getline(file, line);
        }	
        file.close();  
	}
    cout << "number of trees : "<< nbTree<< endl;
    return  nbTree;

}

void day3::JigglypuffSweetKiss2()
{
    int64_t result =JigglypuffSweetKiss1(1,1)
                *JigglypuffSweetKiss1(3 ,1)
                * JigglypuffSweetKiss1(5,1)
                *JigglypuffSweetKiss1(7,1);
    cout << result*JigglypuffSweetKiss1(1,2) << endl;
    

}

day3::~day3()
{

}

