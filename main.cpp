//Tianxin Zhou
//Start at 2:28 PM Sat, March 11
//Data Structure HW6

#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <algorithm>

//Helper function for determin wether a string is digit.
//From http://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c.
bool is_number(const std::string& s)
{
        return( strspn( s.c_str(), "-.0123456789" ) == s.size() );
}

int main(int argc, char* argv[])
{
        //Check the arguments number.
        if(argc !=4)
        {
                std::cerr << "Error in number of arguments" << std::endl;
                return 1;
        }

        //Store arguments in to variables.
        std::ifstream input_str(argv[1]);
        std::ofstream out_str(argv[2]);
        std::string option = argv[3];
        int row, col;
        std::vector<std::string> words_in;
        std::vector<std::string> words_out;

        //Read in the input file.
        std::string temp1, temp2;
        while(input_str >> temp1 >> temp2)
        {
                if(temp1 == "+")
                {
                        words_in.push_back(temp2);
                }
                else if(temp1 == "-")
                {
                        words_out.push_back(temp2);
                }
                else
                if(is_number(temp1) && is_number(temp2))
                {
                        row = atoi(temp1.c_str());
                        col = atoi(temp2.c_str());
                        std::cout << "row,col:" << row << col << std::endl;
                }
                else
                        std::cerr << "The input file contains invalid strings." << std::endl;
        }

        //Debug here
        if(option == "DEBUG")
        {
                for(int i = 0; i < words_in.size(); i++)
                {
                        std::cout << "wordin vector # " << i << " = " << words_in[i] << std::endl;
                }
                for(int i = 0; i < words_out.size(); i++)
                {
                        std::cout << "wordout vector # " << i << " = " << words_out[i] << std::endl;
                }
        }

        else if(option == " one_solution")
        {

        }

        else if(option == " all_solutions")
        {

        }
        else
                std::cerr << " Ivalid option argument" << std::endl;





        return 0;
}
