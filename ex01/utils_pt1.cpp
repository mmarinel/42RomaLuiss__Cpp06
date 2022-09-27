/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt1.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:39:02 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/21 10:39:46 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	print_line(const char *str, const char *color)
{
	std::cout << color
		<< str
		<< RESET
		<< std::endl;
}

void	print_funcName(const char *funcName)
{
	std::cout
		<< YELLOW
		<< "in " << funcName << ": "
		<< RESET;
}

char	*str_concat(const char *s1, const char *s2)
{
	char	*s_cat = new char[std::strlen(s1) + std::strlen(s2) + 1];

	std::memset(s_cat, '\000', std::strlen(s1) + std::strlen(s2) + 1);
	std::strcat(s_cat, s1);
	std::strcat(s_cat, s2);

	return (s_cat);
}

void	read_string(std::string &str, const char *msg)
{
	do
	{
		std::cout << msg << ": ";
		std::getline(std::cin, str, '\n');
	} while (str.empty());
}
