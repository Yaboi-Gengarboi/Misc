//Point.hpp
//Justyn P. Durnford
//Created on 1/13/2020
//Last Updated on 1/13/2020

#ifndef POINT_HPP
#define POINT_HPP

#include <array>
#include <string>

class Point
{
	double Point_x = 0.0;
	double Point_y = 0.0;
	double Point_z = 0.0;

	public:

		//Default Constructor.
		Point();

		//Primary Constructor.
		Point(double x, double y, double z);

		//Seconsary Constructor.
		Point(std::array<double, 3> pt_arr);

		//Returns Point_x.
		double get_x() const;

		//Sets the value of Point_x to x.
		void set_x(const double& x);

		//Returns Point_y.
		double get_y() const;

		//Sets the value of Point_y to y.
		void set_y(const double& y);

		//Returns Point_z.
		double get_z() const;

		//Sets the value of Point_z to z.
		void set_z(const double& z);

		//Returns a string representation of the Point.
		std::string to_str() const;
};

//Uses the distance formula to calculate the distance between
//the two given points.
double distance(const Point& pt1, const Point& pt2);

//Returns true if the three given points are all located
//on the same line.
bool are_collinear(const Point& pt1, const Point& pt2, const Point& pt3);

#endif //#ifndef POINT_HPP