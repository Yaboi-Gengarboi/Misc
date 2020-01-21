//Vector.hpp
//Justyn P. Durnford
//Created on 1/18/2020
//Last Updated on 1/21/2020
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Point.hpp"

#include <array>
#include <string>

class Vector
{
	double _x = 0.0;
	double _y = 0.0;
	double _z = 0.0;

	public:

		//Constructors
		Vector();
		Vector(double x, double y, double z);
		Vector(double vec_arr[3]);
		Vector(const std::array<double, 3>& vec_arr);
		Vector(const Point& pt);
		Vector(const Point& pt1, const Point& pt2);

		//Destructor
		~Vector();

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

		//Sets the value _z to z.
		void set_z(double z);

		//Clears the values of the Vector.
		void clear();

		//Returns the length or magnitude of the Vector.
		double length();

		//Adds the given Vector vec onto the Vector.
		void add(const Vector& vec);

		//Subtracts the given Vector vec from the Vector.
		void subtract(const Vector& vec);

		//Multiplies the given scalar onto the Vector.
		void scale(double scalar);

		//Returns a new Vector copy of the Vector.
		Vector copy() const;

		//Returns a Point representation of the Vector.
		Point to_point() const;

		//Returns an std::array representation of the Vector.
		std::array<int, 3> to_arr() const;

		//Returns an std::string representation of the Vector.
		std::string to_str() const;
};

//Returns the dot-product of Vector vec1 and vec2.
double dot_product(const Vector& vec1, const Vector& vec2);

//Returns the cross-product of Vector vec1 and vec2.
Vector cross_product(const Vector& vec1, const Vector& vec2);

//Returns the scalar projection of Vector vec1 onto vec2.
double scal_proj(const Vector& vec1, const Vector& vec2);

//Returns the vector projection of Vector vec1 onto vec2.
Vector vec_proj(const Vector& vec1, const Vector& vec2);

#endif //#ifndef VECTOR_HPP