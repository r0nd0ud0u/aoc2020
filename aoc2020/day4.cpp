#include "day4.h"
#include <sstream>
#include "utils.h"

using namespace std;




day4::day4()
{
}

day4::~day4()
{

}

void day4::JigglyPuffHyperVoice()
{
    ifstream file("puzzles/puzzle_day04.txt", ios::in);
    vector<map<string,string>> allPassports;
    int validPassports = 0;
    if (file.is_open())
    {
        string line;
        map<string,string> passport;
        while(getline(file, line))
        {
            vector<string> couplesData;
            vector<string> keysValues;
            utils::split(line, ' ',couplesData);
            for(auto it : couplesData)
            {
                utils::split(it, ':',keysValues);
                passport[keysValues[0]] = keysValues[1];
                keysValues.clear();
            }
            if(line == "")
            {
                
                if(passport.size() == 8 ||
                 (passport.size() == 7 && passport.count("cid") ==0))
                 {
                    validPassports++;
                    allPassports.push_back(passport);
                    }
                passport.clear();
            }
        }
        if(passport.size() == 8 ||
                 (passport.size() == 7 && passport.count("cid") ==0))
                 {
                    validPassports++;
                    allPassports.push_back(passport);
                    passport.clear();
                    }
        file.close();  
    }
    cout <<"valid passports puzzle 1 :" <<validPassports << endl;
    int newValidation(0);
    for(auto it:allPassports)
    {
        if(JigglyPuffHyperVoice2(it))
            newValidation++;
    }
    cout <<newValidation<<endl;
    
}

bool day4::JigglyPuffHyperVoice2( map<string,string>  &passport)
{
    vector<string> listEyeColor = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    string hcl ="abcdef0123456789";
    string pid = "0123456789";
    for( map<string,string>::iterator it = passport.begin(); it != passport.end(); ++it)
    {
        if(it->first == "byr")
            if(atoi(it->second.c_str())<1920 ||atoi(it->second.c_str())>2002 )
                return  false;
        if(it->first == "iyr")
            if(atoi(it->second.c_str())<2010 ||atoi(it->second.c_str())>2020 )
                return  false;
        if(it->first == "eyr")
            if(atoi(it->second.c_str())<2020 ||atoi(it->second.c_str())>2030)
                return  false;
        if(it->first == "hgt")
        {
            int hgt =atoi(it->second.substr(0,it->second.size()-2).c_str());
            string type = it->second.substr(it->second.size()-2);
            if( type== "in" )
            {
                if(hgt<59 || hgt > 76)
                    return  false;
            }
            else if( type== "cm")
            {
                if(hgt<150 || hgt > 193)
                   return  false;
            }
            else
            {
                return false;
            }
            
        }
        if(it->first == "pid")
        {
            if(it->second.length() != 9)
                return  false;
            bool inside = true;
            for(auto it2 :it->second )
            {
                if(find(pid.begin(), pid.end(),it2)==pid.end())
                    inside = false;
            }
            if(!inside)
                return  false;
        }
        if(it->first == "ecl")
        {
            if(find(listEyeColor.begin(), listEyeColor.end(),it->second) ==listEyeColor.end())
                return  false;
        }
        if(it->first == "hcl")
        {
            if(it->second[0] != '#')
                return  false;
            bool inside = true;
            string toTest = it->second.substr(1);
            for(auto it2 :toTest )
            {
                if(find(hcl.begin(), hcl.end(),it2)==hcl.end())
                    inside = false;
            }
            if(!inside)
                return  false;
        }  
    }
    return true;
}
