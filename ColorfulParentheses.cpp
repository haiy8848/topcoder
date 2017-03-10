#include <iostream>

class ColorfulParentheses {
public:
  long count(int color[], int n)
  {
    if (color[0] == color[n-1])
      return 0;
    for (int i = 1; i < n; i++)
      if (color[i] == color[0])
        color[i] = 1;
      else if (color[i] == 1)
        color[i] = 0;
    return count_(color, n, 1, 1);
  }

private:
  long count_(int color[], int n, int c, int i)
  {
    if ((i+1) == n)
      return (c == 1 && color[i] == -1) ? 1 : 0;
    if (c == 0) {
      if (color[i] == -1)
        return 0;
      if (color[i] == 1)
        return count_(color, n, 1, i+1);
      for (int j = i + 1; j < n; j++)
        if (color[j] == color[i])
          color[j] = 1;
      return count_(color, n, 1, i+1);
    } else if (c > 0) {
      if (color[i] == -1)
        return count_(color, n, c-1, i+1);
      if (color[i] == 1)
        return count_(color, n, c+1, i+1);
      int *buf = new int[n];
      for (int j = 0; j < n; j++)
        buf[j] = color[j];
      // calculate case for color[i] == 1
      for (int j = i + 1; j < n; j++)
        if (color[j] == color[i])
          color[j] = 1;
      long n1 = count_(color, n , c+1, i+1);
      // calculate case for color[i] == -1
      for (int j = i + 1; j < n; j++)
        if (buf[j] == color[i])
          buf[j] = -1;
      long n2 = count_(buf, n, c-1, i+1);
      delete[] buf;
      return n1 + n2;
    }
    return 0;
  }
};

int main()
{
  int color[] = {0,1,3,3,4,5,6,7,1,9,10,3};

  ColorfulParentheses cp;
  long c = cp.count(color, 12);
  std::cout << "count: " << c << std::endl;

  return 0;
}
