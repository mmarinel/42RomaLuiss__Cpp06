/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:37:43 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/23 11:54:18 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

# define _delete(ptr) {delete ptr; ptr = nullptr;}
# define read_input(ptr, type, msg) {\
	std::string	_;\
	\
	std::cout << msg << ": ";\
	std::cin >> *((type *)ptr);\
	getline(std::cin, _, '\n');/* When Preprocessor expands all occurrences, compiler will throw an error if this is cast is invalid!*/\
}

# include "../colors.hpp"
# include <iostream>

	//* utils

void	print_line(const char *str, const char *color);
void	print_funcName(const char *funcName);
char	*str_concat(const char *s1, const char *s2);
void	read_string(std::string &str, const char *msg);

#endif /* COMMON_UTILS_H */