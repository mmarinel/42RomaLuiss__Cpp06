/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:51:17 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 10:42:27 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.hpp"


bool	is_digit(std::string arg)
{
	if (arg.empty())
		return (false);
	for (size_t i = 0; i < arg.length(); i++)
		if (false == std::isdigit(arg[i]))
			return (false);
	return (true);
}
