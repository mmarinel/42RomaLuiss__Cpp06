/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:59:30 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/30 15:53:39 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include <cctype>
// #include <limits>

#include "types.hpp"
//* end of static declarations


int main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		t_char	pippo(argv[1]);
		std::cout << pippo;
	}
}
