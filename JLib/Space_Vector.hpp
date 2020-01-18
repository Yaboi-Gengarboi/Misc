//Space_Vector.hpp
//Justyn P. Durnford
//Created on 1/18/2020
//Last Updated on 1/18/2020
//

#ifndef SPACE_VECTOR_HPP
#define SPACE_VECTOR_HPP

#include <array>
#include <string>

class Space_Vector
{
	double _x = 0.0;
	double _y = 0.0;
	double _z = 0.0;

	public:

		//Constructors
		Space_Vector();
		Space_Vector(double x, double y, double z);
		Space_Vector(double sp_arr[3]);
		Space_Vector(std::array<double, 3> sp_arr);

		//Destructor
		~Space_Vector();
};

#endif //#ifndef SPACE_VECTOR_HPP