//Tianxin Zhou
//Header file for Words class
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

class Words{
private:
  int row, col;
  std::vector<std::vector<char> > data;

public:
  Words();
  Words(int arow, int acol);
  //Modifer.
  bool insert(std::string word, int arow, int acol, int direct);

  //Printer.
  void print_out()
  {
    std::cout<< "PRINTING" << "Words row = "<<row <<" col = "<< col <<std::endl;

    for(int i=0; i<row;i++)
    {
      for(int j= 0; j < col; j++)
      {
        std::cout<<data[i][j] << " " ;
        if(j == col -1)
        {
          std::cout << std::endl;
        }
      }
    }
  }
  void print_out(std::ofstream &out_str)
  {
    out_str<< "Board:"<<std::endl;
    for(int i=0; i<row;i++)
    {
      out_str<<"  ";
      for(int j= 0; j < col; j++)
      {
        out_str<<data[i][j];
        if(j == col -1)
        {
          out_str <<std::endl;
        }
      }
    }
  }
  bool search(const std::string &word, int arow, int acol, int direct);

  int get_col(){
    return col;
  }
  int get_row(){
    return row;
  }


};
