/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:06:58 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/27 20:17:00 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

// Constructors
Converter::Converter() :
	literal(""),
	__char_repr(0),
	__int_repr(0),
	__float_repr(0.0f),
	__double_repr(0.0)
{
}

Converter::Converter(const Converter &copy) :
	literal(copy.literal),
	__char_repr(copy.__char_repr),
	__int_repr(copy.__int_repr),
	__float_repr(copy.__float_repr),
	__double_repr(copy.__double_repr)
{
}

Converter::Converter(const char* literal) :
	literal(literal),
	__char_repr(_toChar()),
	__int_repr(_toInt()),
	__float_repr(_toFloat()),
	__double_repr(_toDouble())
{
}


// Destructor
Converter::~Converter()
{
}

//Logic
char	Converter::_toChar( void )
{
	if (this->literal.length() != 1)
		this.
}


// Operators
Converter & Converter::operator=(const Converter &assign)
{
	this->~Converter();
	new (this) Converter(assign);

	return *this;
}


// Stream operators
std::ostream&	Converter::operator<<(std::ostream &stream)
{
	stream
		<< "char: " << __char_repr << std::endl
		<< "int: " << __int_repr << std::endl
		<< "float: " << __float_repr << std::endl
		<< "double: " << __double_repr << std::endl;
	return stream;
}
