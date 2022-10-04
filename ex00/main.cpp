/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:59:30 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 13:29:15 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include <cctype>
// #include <limits>

#include	"types.hpp"
# include	"ScalarConverter.hpp"

static void	printScalar( const t_type* scalar, size_t level );
//* end of static declarations

int main(int argc, char const *argv[])
{
	t_type*	scalar;

	if (argc == 2)
	{
		scalar = ScalarConverter::getScalar(argv[1]);
		printScalar(scalar, 0);
		delete scalar;
	}
	else
		std::cout
			<< RED
			<< "Converter: Wrong number of arguments (1 expected)"
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
		// case 3:
		// 	std::cout << scalar->toTDouble() << std::endl;
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