/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:59:30 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 10:50:00 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include <cctype>
// #include <limits>

#include	"types.hpp"
# include	"ScalarConverter.hpp"
//* end of static declarations


int main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		t_type*	scalar = ScalarConverter::getScalar(argv[1]);
		std::cout << scalar->toTFloat();
	}
}
