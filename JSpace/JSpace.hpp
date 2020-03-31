// JSpace.hpp
// Justyn Durnford
// Created on 2/18/2020
// Last Updated on 3/26/2020
//

#ifndef JSPACE_HPP
#define JSPACE_HPP

#include <string>
#include <vector>

namespace JSpace
{
	


	// This class allows an "exact" representation of the quotient
	// of two integers by storing them and allowing the use of the
	// individual integers or the actual result.
	// A Fraction can be constructed by default, with two individual
	// integers or a C-array.
	// Fraction objects are also capable of arithmetic with integers
	// other Fraction objects.
	// A Fraction can be represented as a std::string with the to_str method.
	// Note that any method that can assign or otherwise modify
	// _denominator will never allow it to be set to 0 and will result
	// in _denominator remaining at its default value of 1.
	class JFraction
	{
		int _numerator = 0;
		int _denominator = 1;

		public:

			// Constructors.
			JFraction();
			JFraction(int numerator, int denominator);
			JFraction(int frac_arr[2]);
			JFraction(const JFraction& frac);

			// Destructor.
			~JFraction();

			// Returns _numerator.
			int getNumerator() const;

			// Returns _denominator.
			int getDenominator() const;

			// Sets _numerator to numer.
			void setNumerator(int numer);

			// Sets _denominator to denom.
			void setDenominator(int denom);

			// Returns the integer division of the fraction.
			int intResult() const;

			// Returns the decimal division of the fraction.
			double doubleResult() const;

			// Adds num onto the fraction.
			void add(int num);

			// Subtracts num onto the fraction.
			void subtract(int num);

			// Multiplies num onto the fraction.
			void multiply(int num);

			// Divides num onto the fraction.
			void divide(int num);

			// Adds frac onto the fraction.
			void add(const JFraction& frac);

			// Subtracts frac onto the fraction.
			void subtract(const JFraction& frac);

			// Multiplies frac onto the fraction.
			void multiply(const JFraction& frac);

			// Divides frac onto the fraction.
			void divide(const JFraction& frac);

			// Returns an std::string representation of the fraction.
			std::string toString() const;
	};

	JFraction operator + (const JFraction& fr, int num);
	JFraction operator + (const JFraction& fr1, const JFraction& fr2);

	JFraction operator - (const JFraction& fr, int num);
	JFraction operator - (const JFraction& fr1, const JFraction& fr2);

	JFraction operator * (const JFraction& fr, int num);
	JFraction operator * (const JFraction& fr1, const JFraction& fr2);

	JFraction operator / (const JFraction& fr, int num);
	JFraction operator / (const JFraction& fr1, const JFraction& fr2);

	JFraction& operator += (const JFraction& fr, int num);
	JFraction& operator += (const JFraction& fr1, const JFraction& fr2);

	// This class allows for the representation of a single point
	// in 3-dimensional space.
	// A Point can be constructed by default, with a std::vector or
	// with a 
	// JPoints are not capable of arithmetic on their own due to
	// their static nature, but there are functions that work with
	// points, and points can be compared to eachother.
	// A JPoint can be represented as a std::string with the to_str method.
	class JPoint
	{
		std::vector<float> _vals;

		public:

			// Constructors.
			JPoint();
			JPoint(const std::vector<float>& vals);

			JPoint& operator = (const std::vector<float>& vals);
			JPoint& operator = (const std::initializer_list<float>& init_list);
			JPoint& operator = (const JPoint& pt);

			// Destructor.
			~JPoint();

			// Returns _x.
			float getX() const;

			// Returns _y.
			float getY() const;

			// Returns _z.
			float getZ() const;

			// Sets the value of _x to x.
			void setX(float x);

			// Sets the value of _y to y.
			void setY(float y);

			// Sets the value of _z to z.
			void setZ(float z);

			// Returns a std::string representation of the Point.
			std::string toString() const;

			// Returns a std::vector representation of the Point.
			std::vector<float> toVector() const;
	};

	class Vector
	{

	};
}

#endif //JSPACE_HPP