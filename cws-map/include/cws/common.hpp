#pragma once

#include <list>
#include <ostream>

/*
 * Coordinates of a cell on the map
 */
struct Coordinates final {
  int x;
  int y;

  friend std::ostream & operator<<(std::ostream & out, const Coordinates & value);
  friend bool operator<(const Coordinates & lhs, const Coordinates & rhs);
  friend bool operator==(const Coordinates & lhs, const Coordinates & rhs);
};

struct Dimension final {
  int width;
  int height;

  friend std::ostream & operator<<(std::ostream & out, const Dimension & value);
  friend bool operator==(const Dimension & lhs, const Dimension & rhs);
};

struct Temperature final {
  double value;

  double get() const { return value; }

  friend Temperature operator+(const Temperature & lhs, const Temperature & rhs);
  friend std::ostream & operator<<(std::ostream & out, const Temperature & value);
  friend bool operator==(const Temperature & lhs, const Temperature & rhs);
};

struct Obstruction final {
  double value;

  double get() const { return value; }

  friend bool operator>(const Obstruction & lhs, const Obstruction & rhs);
  friend Obstruction operator+(const Obstruction & lhs, const Obstruction & rhs);
  friend Obstruction operator-(const Obstruction & lhs, const Obstruction & rhs);
  friend Obstruction operator*(const Obstruction & lhs, const Obstruction & rhs);
};

struct Illumination final {
  int value;

  int get() const { return value; }

  Illumination getActualIllumination(const Obstruction & abs);

  friend Illumination operator+(const Illumination & lhs, const Illumination & rhs);
  friend bool operator==(const Illumination & lhs, const Illumination & rhs);
};

std::list<Coordinates> getNeighbours(Dimension dim, Coordinates p);

std::pair<int, int> getVector(Coordinates p1, Coordinates p2);

int getScalarMultiplication(std::pair<int, int> v1, std::pair<int, int> v2);

int getDistanceSquare(std::pair<int, int> v);
