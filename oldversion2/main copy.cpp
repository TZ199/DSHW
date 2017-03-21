//Tianxin Zhou
//Start at 2:28 PM Sat, March 11
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


//Helper function for determin wether a string is digit.
//From http://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c.
bool is_number(const std::string& s)
{
  if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

  char * p ;
  strtol(s.c_str(), &p, 10) ;

  return (*p == 0) ;
}





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
        std::cout << "Proving alive" << std::endl;
        Words temp1,temp2, temp3,temp4,temp5,temp6,temp7,temp8;
        temp1 = temp,temp2 = temp,temp3 = temp,temp4 = temp,temp5 = temp,temp6 = temp,
        temp7 = temp,temp8 = temp;
        std::vector<std::string> ain_temp;
        if(temp1.insert(ain.back(),i,j,1))
        {
          ain_temp = ain;
          ain_temp.pop_back();
          fill_words(arow,acol, ain_temp,afits,temp1);
        }
        if(temp2.insert(ain.back(),i,j,2))
        {
          ain_temp = ain;
          ain_temp.pop_back();
          fill_words(arow,acol, ain_temp,afits,temp2);
        }
        if(temp3.insert(ain.back(),i,j,3))
        {
          ain_temp = ain;
          ain_temp.pop_back();
          fill_words(arow,acol, ain_temp,afits,temp3);
        }
        if(temp4.insert(ain.back(),i,j,4))
        {
          ain_temp = ain;
          ain_temp.pop_back();
          fill_words(arow,acol, ain_temp,afits,temp4);
        }
        if(temp5.insert(ain.back(),i,j,5))
        {

          ain_temp = ain;
          ain_temp.pop_back();
          fill_words(arow,acol, ain_temp,afits,temp5);
        }
        if(temp6.insert(ain.back(),i,j,6))
        {

          ain_temp = ain;
          ain_temp.pop_back();
          fill_words(arow,acol, ain_temp,afits,temp6);
        }
        if(temp7.insert(ain.back(),i,j,7))
        {

          ain_temp = ain;
          ain_temp.pop_back();
          fill_words(arow,acol, ain_temp,afits,temp7);
        }
        if(temp8.insert(ain.back(),i,j,8))
        {

          ain_temp = ain;
          ain_temp.pop_back();
          fill_words(arow,acol, ain_temp,afits,temp8);
        }

      }
    }
  }
}



void pre_search(int arow,int acol, const std::vector<std::string>& aout, std::vector<Words> & afits, std::vector<bool> & help,int index)
{
  for(int j = 0; j<aout.size(); j++)
  {
    for(int i = 1; i<9; i++)
    {
      if(afits[index].search(aout[j],arow,acol,i))
      {
        help[index] = true;
        return;
      }
    }
  }

  if(acol+1<afits[index].get_col())
  {
    pre_search(arow,acol+1,aout,afits,help,index);
  }
  else if(arow+1<afits[index].get_row())
  {
    pre_search(arow+1,0,aout,afits,help,index);
  }
  else
  return;



}



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
                assert(test.insert("ONE", 0,2,3));
                std::cout << "test2" << std::endl;
                test.print_out();

        }

        // else if(option == "one_solution")
        // {
        //   std::cout << "Not complete" << std::endl;
        // }

        else if(option == "all_solutions"||option == "one_solution")
        {
          // for(int i = 0; i < words_in.size(); i++)
          // {
          //         std::cout << "wordin vector # " << i << " = " << words_in[i] << std::endl;
          // }
          fill_words(row,col, words_in,fit_words,Words(row,col));
          // Words(row,col).print_out();

          std::vector<bool> help (fit_words.size(), false);
          for(int i = 0; i< fit_words.size(); i++)
          {
            pre_search(0,0, words_out,fit_words,help,i);
          }

          //First attemp to delete the unwanting words.
          std::vector<Words> preanswer;
          // std::cout<<"size" << fit_words.size() << std::endl;
          for(int i = 0; i < fit_words.size();i++)
          {
            if(!help[i])
            {
              preanswer.push_back(fit_words[i]);
            }
          }
          // std::cout<<"preanswer:" << preanswer.size() << std::endl;

          std::list<Words> answer(preanswer.begin(), preanswer.end());
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

          // for(int i = 0; i<alphabet.size(); i++)
          // {
          //   std::cout<<alphabet[i] << " " << std::endl;
          // }

          // //Filling the blank with a-z
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

          answer.erase(unique(answer.begin(), answer.end()), answer.end());
          // std::cout<<"Testing" << "size" << answer.size()<<std::endl;
          // for(std::list<Words>::iterator i = answer.begin(); i != answer.end();i++)
          // {
          //   i->print_out();
          // }
          if(option == "one_solution")
          {
            answer.begin()->print_out(out_str);
          }
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
