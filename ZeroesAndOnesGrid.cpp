#include <vector>
#include <string>

using namespace std;

class ZeroesAndOnesGrid {
public:
  int minMovesCount(vector<string> table)
  {
    int count = 0;
    while (flipTable(table))
      count++;
    return count;
  }

private:
  bool flipTable(vector<string>& table)
  {
    int row = -1, col = -1;
    for (size_t i = 0; i < table.size(); i++) {
      for (size_t j = 0; j < table.at(i).length(); j++) {
        if (table.at(i)[j] == '1') {
          if ((int)j >= col) {
            row = i;
            col = j;
          }
        }
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (table.at(i)[j] == '0') {
          table.at(i)[j] = '1';
        } else {
          table.at(i)[j] = '0';
        }
      }
    }
    return (row != -1) ? true : false;
  }

};
