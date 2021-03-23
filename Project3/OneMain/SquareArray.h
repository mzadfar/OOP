#ifndef _SQUAREARRAY_H_
#define _SQUAREARRAY_H_

class SquareArray
{
  public:
    Square ary[3];

    double sumAreas()
    {
      double sum = 0;

      for (int i = 0; i < 3; i++)
      {
        sum += ary[i].computeArea();
      }

      return (sum);
    }

    double sumCircumferences()
    {
      double sum = 0;

      for (int i = 0; i < 3; i++)
      {
        sum += ary[i].computeCircumference();
      }

      return (sum);
    }
};
#endif // _SQUAREARRAY_H_
