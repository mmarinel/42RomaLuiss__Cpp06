/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:59:30 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 18:35:15 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include <cctype>
// #include <limits>

/*
	................................................................
Float max: 3.40282e+38
Float min: -3.40282e+38
Double max: 1.79769e+308
Double min: -1.79769e+308
Int max: 2147483647
Int min: -2147483648
Char max: 127
Char min: -128
................................................................
*/
#include	"types.hpp"
# include	"ScalarConverter.hpp"

static void	printScalar( const t_type* scalar, size_t level );
//* end of static declarations

int main(int argc, char const *argv[])
{
	t_type*	scalar;
	// std::cout << "................................................................" << std::endl;
	// std::cout << "Float max: " << std::numeric_limits<float>::max() << std::endl;
	// std::cout << "Float min: " << std::numeric_limits<float>::lowest() << std::endl;
	// std::cout << "Double max: " << std::numeric_limits<double>::max() << std::endl;
	// std::cout << "Double min: " << std::numeric_limits<double>::lowest() << std::endl;
	// std::cout << "Int max: " << std::numeric_limits<int>::max() << std::endl;
	// std::cout << "Int min: " << std::numeric_limits<int>::lowest() << std::endl;
	// std::cout << "Char max: " << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
	// std::cout << "Char min: " << static_cast<int>( std::numeric_limits<char>::lowest()) << std::endl;
	// std::cout << "................................................................" << std::endl;
	if (argc == 2)
	{
		scalar = ScalarConverter::getScalar(argv[1]);
		printScalar(scalar, 0);
		delete scalar;
	}
	else
		std::cout
			<< "Converter: "
			<< RED
			<< "Wrong number of arguments (1 expected)"
			<< RESET
			<< std::endl;
}

static void	printScalar( const t_type* scalar, size_t level )
{
	try
	{
		switch (level)
		{
		case 0:
			std::cout << scalar->toTPrintChar() << std::endl;
		case 1:
			std::cout << scalar->toTInt() << std::endl;
		case 2:
			std::cout << scalar->toTFloat() << std::endl;
		case 3:
			std::cout << scalar->toTDouble() << std::endl;
		break ;
		}
	}
	catch(const t_type::ImpossibleConversion& e)
	{
		std::cout << e.what() << '\n';
		printScalar(scalar, level + 1);
	}
	catch(const t_type::NonDisplayableConversion& e)
	{
		std::cout << e.what() << '\n';
		printScalar(scalar, level + 1);
	}
}