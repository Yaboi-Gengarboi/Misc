//Point.hpp
//Justyn P. Durnford
//Created on 1/13/2020
//Last Updated on 1/31/2020
//https://github.com/Yaboi-Gengarboi/Misc/blob/master/JLib/Point.hpp

/*
This class allows for the representation of a single point
in 3-dimensional space.
A Point can be constructed by default, with values for each
dimension, with a C-array or an std::array.
Points are not capable of arithmetic on their own due to
their static nature, but there are functions that work with
points, and points can be compared to eachother.
A Point can be represented as an std::array or an std::string
with the to_arr and to_str respectively.
*/

#ifndef POINT_HPP
#define POINT_HPP

#include <array>
#include <string>

class Point
{
	double _x = 0.0;
	double _y = 0.0;
	double _z = 0.0;

	public:

		//Constructors.
		Point();
		Point(double x, double y, double z);
		Point(double pt_arr[3]);
		Point(const std::array<double, 3>& pt_arr);

		//Destructor.
		~Point();

		//Returns _x.
		double get_x() const;

		//Sets the value of _x to x.
		void set_x(double x);

		//Returns _y.
		double get_y() const;

		//Sets the value of _y to y.
		void set_y(double y);

		//Returns _z.
		double get_z() const;

		//Sets the value of _z to z.
		void set_z(double z);

		//Returns a std::array representation of the Point.
		std::array<double, 3> to_arr() const;

		//Returns a std::string representation of the Point.
		std::string to_str() const;
};

//Uses the distance formula to calculate the distance between
//the two given points.
double distance(const Point& pt1, const Point& pt2);

//Returns true if the three given points are all located
//on the same line.
bool are_collinear(const Point& pt1, const Point& pt2, const Point& pt3);

//Equality operator
bool operator == (const Point& pt1, const Point& pt2);

//Inequality operator
bool operator != (const Point& pt1, const Point& pt2);

#endif //#ifndef POINT_HPP