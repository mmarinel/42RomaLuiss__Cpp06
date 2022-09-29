/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:59:30 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/27 20:29:54 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <limits>

typedef enum e_type
{
	e_CHAR,
	e_INT,
	e_FLOAT,
	e_DOUBLE,
	e_NONE
}	t_type;

static t_type	typeOf(const char* arg);
static bool		is_digit(const char* arg);
static bool		str
//* end of static declarations


int main(int argc, char const *argv[])
{
	return 0;
}

static t_type	typeOf(const char* arg)
{
	bool	dot_found = false;
	bool	f_found = false;

	if (std::strlen(arg) == 1)
		return (e_CHAR);
	if (arg[])
	else if (false == is_digit(arg))
		return (e_NONE);
	else
	{
		if (NULL != std::strchr(arg, '.'))
	}
}

static bool		is_digit(const char* arg)
{
	size_t	i;

	if (NULL == arg)
		return (false);
	i = 0;
	while (arg[i])
	{
		if (0 == std::isdigit(arg[i]))
			return (false);
		i++;
	}
	return (true);
}
