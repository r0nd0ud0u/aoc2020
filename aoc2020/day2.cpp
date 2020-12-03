#include "day2.h"
#include <sstream>

using namespace std;
day2::day2()
{

}

void day2::JigglypuffCharm()
{
    cout << "I will use all my charm todayyyyyyyyyyyyyy <3" << endl;
    int goodPasswords =0;
    vector<string> passwords;
    ifstream file("puzzles/puzzle_day02.txt", ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
			split(line,' ',passwords);
        file.close();  
	}
    for(int i =0; i<passwords.size();i+=3)
    {
        int nb = count((passwords[i+2]).begin(), passwords[i+2].end(), passwords[i+1][0]);
        vector<string> nbs;
        split(passwords[i],'-',nbs);
        if(nb>=atoi(nbs[0].c_str()) && nb <=atoi(nbs[1].c_str()))
            goodPasswords++;
    }
    cout << goodPasswords << endl;

    goodPasswords = 0;
    for(int i =0; i<passwords.size();i+=3)
    {
        vector<string> nbs;
        split(passwords[i],'-',nbs);
        int nb1 = atoi(nbs[0].c_str());
        int nb2 = atoi(nbs[1].c_str());
        int fndChar(0);
        if(passwords[i+2][nb1-1] == passwords[i+1][0])
            fndChar++;
        if(passwords[i+2][nb2-1] == passwords[i+1][0])
            fndChar++;
        if(fndChar == 1)
            goodPasswords++;
    }
    cout << goodPasswords << endl;

}

day2::~day2()
{

}


void day2::split(const string &content, char pattern, vector<string> &elements)
{
    stringstream ss(content);
    string str;
    while (getline(ss, str, pattern))
    {
        elements.push_back(str);
    }
}