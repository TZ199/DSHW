//Tianxin Zhou
//Helper function for HW6
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
#include <math.h>


Words::Words()
{
  row = 0;
  col = 0;
}

Words::Words(int arow, int acol)
{
  row = arow;
  col = acol;
  for(int i = 0; i < arow; i++)
  {
    std::vector<char> temp(acol,'_');
    data.push_back(temp);
  }
}

//Direction 1:up 2:down 3:left 4:right 5:up_left 6:up_right 7:down_left 8:down_right
bool Words::insert(std::string word, int arow, int acol, int direct)
{
  //1:up
  if(direct == 1)
  {
    if(word.size() > arow)
    {
      return false;
    }
    else
    {
      for(int i = 0; i < word.size(); i++)
      {
        if(data[arow-i][acol] == '_')
          data[arow-i][acol] = word[i];
        else
        {
          if(data[arow-i][acol] != word[i])
            return false;
        }
      }
      return true;
    }
  }
  //2:down
  else if(direct == 2)
  {
    if(word.size()+arow>row)
    {
      return false;
    }
    else
    {
      for(int i = 0; i<word.size(); i++)
      {
        if (data[arow+i][acol] == '_') {
            data[arow+i][acol] = word[i];
        }
        else
        {
          if(data[arow+i][acol] != word[i])
            return false;
        }
      }
      return true;
    }
  }
  //3:left
  else if(direct == 3)
  {
    if(word.size() > acol)
    {
      return false;
    }
    else
    {
      for(int i = 0; i < word.size(); i++)
      {
        if(data[arow][acol-i] == '_')
          data[arow][acol-i] = word[i];
        else
        {
          if(data[arow][acol-i] != word[i])
            return false;
        }
      }
      return true;
    }
  }
  //4:right
  else if(direct == 4)
  {
    if(word.size()+acol>col)
    {
      return false;
    }
    else
    {
      for(int i = 0; i<word.size(); i++)
      {
        if (data[arow][acol+i] == '_') {
            data[arow][acol+i] = word[i];
        }
        else
        {
          if(data[arow][acol+i] != word[i])
            return false;
        }
      }
      return true;
    }
  }
  //5:up_left
  else if(direct == 5)
  {
    if(word.size() > arow || word.size() > acol)
    {
      return false;
    }
    else
    {
      for(int i = 0; i < word.size(); i++)
      {
        if(data[arow-i][acol-i] == '_')
          data[arow-i][acol-i] = word[i];
        else
        {
          if(data[arow-i][acol-i] != word[i])
            return false;
        }
      }
      return true;
    }

  }
  //6:up_right
  else if(direct == 6)
  {
    if(word.size() > arow || word.size()+acol>col)
    {
      return false;
    }
    else
    {
      for(int i = 0; i<word.size(); i++)
      {
        if (data[arow-i][acol+i] == '_') {
            data[arow-i][acol+i] = word[i];
        }
        else
        {
          if(data[arow-i][acol+i] != word[i])
            return false;
        }
      }
      return true;
    }
  }
  //7:down_left
  else if(direct == 7)
  {
    if(word.size()+arow>row || word.size() > acol )
    {
      return false;
    }
    else
    {
      for(int i = 0; i<word.size(); i++)
      {
        if (data[arow+i][acol-i] == '_') {
            data[arow+i][acol-i] = word[i];
        }
        else
        {
          if(data[arow+i][acol-i] != word[i])
            return false;
        }
      }
      return true;
    }
  }
  //8:down_right
  else if(direct == 8)
  {
    if(word.size()+arow>row || word.size()+acol>col )
    {
      return false;
    }
    else
    {
      for(int i = 0; i<word.size(); i++)
      {
        if (data[arow+i][acol+i] == '_') {
            data[arow+i][acol+i] = word[i];
        }
        else
        {
          if(data[arow+i][acol+i] != word[i])
            return false;
        }
      }
      return true;
    }
  }
  //Unknown error
  else{
    std::cerr << "Unknown error" << std::endl;
    return false;
  }
}
