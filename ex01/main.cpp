/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:01:51 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/06 15:34:05 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"
# include "../colors.hpp"

# include <iostream>
# include <string>
# include <cstdint>

static uintptr_t	serialize(Data* ptr);
static Data*		deserialize(uintptr_t raw);
//* end of static declarations

int	main( void )
{
	Data	data = {"Clegg", "Corporal"};

	std::cout << "Printing structure before pointer magic" << std::endl;
	std::cout << YELLOW << data << RESET << std::endl;
	std::cout << "Printing structure after pointer magic" << std::endl;
	Data*	newPtr = deserialize(serialize(&data));
	std::cout << YELLOW << *newPtr << RESET << std::endl;

	if (newPtr == &data)
		std::cout << "Pointer Check: " << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << "Pointer Check: " << RED << "NOT OK" << RESET << std::endl;
	std::cout << std::endl;
	return 0;
}

static uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

static Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

std::ostream&	operator<<( std::ostream& stream, const Data& obj)
{
	stream << obj.rank << " " << obj.name;

	return (stream);
}
