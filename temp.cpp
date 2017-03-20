void pre_search(int arow,int acol, std::vector<std::string> aout, std::vector<Words> & afits, std::vector<bool> & help,int index)
{
  for(int j = 0; j< arow; j++)
  {
      for(int k = 0; k < acol; k++)
      {
        for(int i = 1; i<9; i++)
        {
          if(afits[index].search(aout.back(),j,k,i))
          {
            help[index] = true;
            return;
          }
          else
          {
            std::vector<std::string> temp_aout = aout;
            temp_aout.pop_back();
            pre_search(j,k,temp_aout,afits,help,index);

          }
        }
      }
    }
  }





  std::vector<bool> help (false,fit_words.size());
  // for(int i = 0; i< fit_words.size(); i++)
  // {
  //   pre_search(row,col, words_out,fit_words,help,i);
  // }

  std::vector<Words> answer;
  for(int i = 0; i < fit_words.size();i++)
  {
    if(!help[i])
    {
      answer.push_back(fit_words[i]);
    }




























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
