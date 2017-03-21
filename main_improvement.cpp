//Tianxin Zhou
//Start at 2:28 PM Sat, March 11
//34s version: 3.52pm Tue, March 21
//Data Structure HW6
#include "Words.h"
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
#include <assert.h>
#include <list>



//for the compare length http://stackoverflow.com/questions/18831470/sorting-a-string-vector-based-on-the-string-size
struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() < second.size();
    }
};

//Helper function for determin wether a string is digit.
//From http://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c.
bool is_number(const std::string& s)
{
  if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

  char * p ;
  strtol(s.c_str(), &p, 10) ;

  return (*p == 0) ;
}

//Filling the matrix in all possible ways.
void fill_words(int arow, int acol, std::vector<std::string> ain, std::vector<Words> & afits, Words temp)
{
  if(ain.size() == 0)
  {
    afits.push_back(temp);
    return;
  }
  else
  {
    for(int i = 0; i< arow; i++)
    {

      for(int j= 0; j< acol; j++)
      {
        for(int k = 1; k<9; k++)
        {
          Words temp1 = temp;
          if(temp1.insert(ain.back(),i,j,k))
          {
            std::vector<std::string> ain_temp;
            ain_temp = ain;
            ain_temp.pop_back();
            fill_words(arow,acol, ain_temp,afits,temp1);
          }
        }

      }
    }
  }
}

//Search the unwanting words and delete them.
bool pre_searchb(int arow,int acol, const std::vector<std::string>& aout, Words temp,int & key)
{
  for(int j = 0; j<aout.size(); j++)
  {
    for(int i = 1; i<9; i++)
    {
      if(temp.search(aout[j],arow,acol,i))
      {
        key = 1;
        return true;
      }
    }
  }

  if(acol+1<temp.get_col()&&key==0)
  {
    return pre_searchb(arow,acol+1,aout,temp,key);
  }
  else if(arow+1<temp.get_row()&&key==0)
  {
    return pre_searchb(arow+1,0,aout,temp,key);
  }
  else
  return false;
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
        std::vector<Words> fit_words;
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
                //Read the row and column numbers.
                if(is_number(temp1) && is_number(temp2))
                {
                        col = atoi(temp1.c_str());
                        row = atoi(temp2.c_str());
                }
                else
                        std::cerr << "The input file contains invalid strings." << std::endl;
        }

        //Debug mode.
        if(option == "DEBUG")
        {
                std::cout << "row,col:" << row << col << std::endl;
                for(int i = 0; i < words_in.size(); i++)
                {
                        std::cout << "wordin vector # " << i << " = " << words_in[i] << std::endl;
                }
                for(int i = 0; i < words_out.size(); i++)
                {
                        std::cout << "wordout vector # " << i << " = " << words_out[i] << std::endl;
                }

                Words test(2,3);
                std::cout << "test" << std::endl;


        }

        else if(option == "all_solutions"||option == "one_solution")
        {
          //Sort the input vector by the length of words.
          compare c;
          std::sort(words_in.begin(), words_in.end(), c);
          std::sort(words_out.begin(), words_out.end(), c);
          Words begin(row,col);
          fill_words(row,col, words_in,fit_words,begin);

          std::list<Words> answer(fit_words.begin(), fit_words.end());

          for (std::list<Words>::iterator i = answer.begin(); i != answer.end();)
          {
            int k = 0;
            if(pre_searchb(0,0, words_out,*i,k))
            {
              i = answer.erase(i);
            }
            else
              i++;
          }
          //From http://stackoverflow.com/questions/12850181/stdunique-and-removing-duplicates-from-a-container-of-objects
          answer.erase(unique(answer.begin(), answer.end()), answer.end());


          //Pre check with the words_out
          char alph[] = "abcdefghijklmnopqrstuvwxyz";
          std::vector<char> alphabet( alph, alph+sizeof(alph)-1 ) ;
          for(int i = 0; i < words_out.size(); i++)
          {
            for(int j=0; j<alphabet.size(); j++)
            {
              if((words_out[i].size() == 1) && (words_out[i][0]== alphabet[j]))
              {
                alphabet.erase (alphabet.begin()+j);
              }
            }
          }


          //Filling the blank with a-z
          for (std::list<Words>::iterator i = answer.begin(); i != answer.end();)
          {
            int outrow,outcol;
            if(i->check_blank(outrow,outcol))
            {

              for(int j = 0; j<alphabet.size();j++)
              {
                Words temp = *i;
                temp.add(outrow,outcol,alphabet[j]);
                answer.push_back(temp);

              }
              i = answer.erase(i);
            }
            else
              i++;
          }
          //Deleting the unwanting words again
          for (std::list<Words>::iterator i = answer.begin(); i != answer.end();)
          {
            int k = 0;
            if(pre_searchb(0,0, words_out,*i,k))
            {
              i = answer.erase(i);
            }
            else
              i++;
          }
          //From http://stackoverflow.com/questions/12850181/stdunique-and-removing-duplicates-from-a-container-of-objects
          //Deleting the duplicated Words.
          answer.erase(unique(answer.begin(), answer.end()), answer.end());

          //If one_solution then only print one.
          if(option == "one_solution")
          {
            answer.begin()->print_out(out_str);
          }
          //all_solutions, print all.
          else
          {
            out_str<<answer.size() <<" solution(s) "<<std::endl;
            for(std::list<Words>::iterator i = answer.begin(); i != answer.end();i++)
            {
              i->print_out(out_str);
            }
          }
        }
        else
                std::cerr << " Ivalid option argument" << std::endl;

        return 0;
}
