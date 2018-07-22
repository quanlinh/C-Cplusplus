// Learn new things today, explicit keyword will turn off implicit conversion to happens
// such as create a point d = (2.0)(2.0) and assigne it to c = d; and if we use explicit
// we are not allow them to convert
class Point
{
public:
  // constructor with one arguments
  // Point(double u) : x(u), y(0.0) {}
  // Point(double v) : x(0.0), y(v) {}
  // Point(double u, double v) : x(u), y(v) {}
  Point(int u, int v) : x(u), y(v) {}

  double x, y;
  
  bool operator==(Point other) const
  {
    return (x == other.x && y == other.y);
  }
  // This overload operator favor sorted base on X-coordinatate, 
  // If there is a type we break it by y
  
};