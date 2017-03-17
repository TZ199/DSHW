//Tianxin Zhou
//Header file for Words class
#include <vector>
#include <string>

class Words{
private:
  int row, col;
  std::vector<std::vector<char> > data;

public:
  Words();
  Words(int arow, int acol);
};
