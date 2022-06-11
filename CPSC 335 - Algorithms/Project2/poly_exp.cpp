
///////////////////////////////////////////////////////////////////////////////
// poly_exp.cpp
//
// Definitions for two algorithms:
//
// soccer_exhaustive
// soccer_dyn_prog
//
///////////////////////////////////////////////////////////////////////////////

#include "poly_exp.hpp"
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

int algorithms::soccer_exhaustive(const std::vector<std::string> field)
{

  if (field.size() == 0)
  {
    throw std::invalid_argument("empty string");
  }

  if (field[0].size() == 0)
  {
    throw std::invalid_argument("empty column detected");
  }

  int row = field.size();
  int col = field[0].size();
  int len = row + col - 2;
  int counter = 0;

  if (len > 31)
  {
    throw std::invalid_argument("len too large");
  }

  for (int i = 0; i < field.size(); i++)
  {
    if (col != field[i].size())
    {
      throw std::invalid_argument("column with different size detected");
    }

    for (char c : field[i])
    {
      if (c != '.' && c != 'X')
      {
        throw std::invalid_argument("invalid character detected");
      }
    }
  }

  if (field[0][0] == 'X')
  {
    return 0;
  }

  if (field[row - 1][col - 1] == 'X')
  {
    return 0;
  }

  int n = std::pow(2, len) - 1;
  int n2 = len - 1;

  for (int bits = 0; bits <= n; bits++)
  {
    std::vector<int> cand{};

    for (int k = 0; k <= n2; k++)
    {
      bool bit = (bits >> k) & 1;

      if (bit == 1)
      {
        cand.push_back(1);
      }
      else
      {
        cand.push_back(0);
      }
    }

    bool invalid = false;
    int posR = 0;
    int posC = 0;

    for (int i = 0; i < cand.size(); i++)
    {
      if (field[posR][posC] != '.')
      {
        invalid = true;
        break;
      }

      if (posR == (row - 1) && posC == (col - 1))
      {
        break;
      }

      if (cand[i] == 1 && posC < col - 1)
      {
        posC++;
      }
      else if (cand[i] == 0 && posR < row - 1)
      {
        posR++;
      }
      else
      {
        invalid = true;
        break;
      }
    }

    if (invalid == false)
    {
      counter++;
    }
  }

  return counter;
}

int algorithms::soccer_dyn_prog(const std::vector<std::string> field)
{
  if (field.size() == 0)
  {
    throw std::invalid_argument("empty string");
  }

  if (field[0].size() == 0)
  {
    throw std::invalid_argument("empty column detected");
  }

  for (int i = 0; i < field.size(); ++i)
  {
    if (field[0].size() != field[i].size())
    {
      throw std::invalid_argument("different column size detected");
    }

    for (char c : field[i])
    {
      if (c != '.' && c != 'X')
      {
        throw std::invalid_argument("invalid character detected");
      }
    }
  }

  if (field[0][0] == 'X')
  {
    return 0;
  }

  int rows = field.size();
  int cols = field[0].size();
  std::vector<std::vector<int>> A(rows, std::vector<int>(cols, 0));

  A[0][0] = 1;

  int n1 = field.size() - 1;
  int n2 = field[0].size() - 1;

  for (int i = 0; i <= n1; i++)
  {
    for (int j = 0; j <= n2; j++)
    {

      if (field[i][j] == 'X')
      {
        A[i][j] = 0;
        continue;
      }

      int above = 0;
      int left = 0;

      if (i > 0 && field[i - 1][j] == '.')
      {
        above = A[i - 1][j];
      }

      if (j > 0 && field[i][j - 1] == '.')
      {
        left = A[i][j - 1];
      }

      A[i][j] += above + left;
    }
  }

  return A[field.size() - 1][field[0].size() - 1];
}
