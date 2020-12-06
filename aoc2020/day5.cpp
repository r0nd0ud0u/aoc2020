#include "day5.h"
#include <sstream>
#include "utils.h"
#include "math.h"

using namespace std;




day5::day5()
{
}

day5::~day5()
{

}

void day5::JigglypuffRest()
{
    int seatID =0;
    ifstream file("puzzles/puzzle_day05.txt", ios::in);
    
	if (file.is_open())
	{
        string line;
        int result = 0;
        std::vector<uint32_t> ids;
		while (getline(file, line))
        {
            int nbChars(7);
            int nbEnd(3);
            int indRow1= 0;
            int indRow2 = pow (2, nbChars);
            int indexFromEnd = line.size();
            int indColumn1 =0;
            int indColumn2 = pow (2, nbEnd);

            int indexRow = 0;
            int minRow =0;
            int minColumn = 0;
            for(string::iterator it = line.begin(); it !=line.end(); ++it)
            {
                if(indexRow < 7)
                {
                    nbChars--;
                    if(*it == 'F')
                        indRow2 -=pow (2, nbChars);
                    if(*it == 'B')
                        indRow1 +=pow (2, nbChars);
                    //cout << "indRow2 : "<< indRow2<< endl;
                    //cout << "nbChars : "<< nbChars<< endl;
                    indexRow++;

                }
                else
                {
                    nbEnd--;
                    if(*it == 'L')
                        indColumn2 -=pow (2, nbEnd);
                    if(*it == 'R')
                        indColumn1 +=pow (2, nbEnd);

                }
            }
            minRow = min(indRow2,indRow1);
            minColumn = min(indColumn1, indColumn2);
            int tmpResult = minRow*8 + minColumn;
            ids.push_back(tmpResult);
            //cout << "indRow1 : "<< indRow1<< endl;
            result = max(result, tmpResult);
            
        }	
        cout << "result : "<< result<< endl;
        sort(ids.begin(), ids.end());
        for (int i = 0; i < ids.size(); ++i) 
        {
            if (ids[i] + 1 != ids[i + 1])
            {
                cout << "result2 : "<< ids[i] + 1<< endl;
                break;
            }
        }
        file.close();  
	}
    

}