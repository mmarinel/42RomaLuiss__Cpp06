/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:05:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 10:17:42 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


const ScalarConverter::t_creation_handle	ScalarConverter::creationHandle[TTYPES] = {
	{&ScalarConverter::is_Tprintable_char, &ScalarConverter::makeTPrintableChar},
	{&ScalarConverter::is_TInt, &ScalarConverter::makeTInt},
	{&ScalarConverter::is_TFloat, &ScalarConverter::makeTFloat},
	{&ScalarConverter::is_TDouble, &ScalarConverter::makeTDouble}
};

//* Main Exposed Functions
t_type*	ScalarConverter::getScalar( const std::string string_repr ) {
	for (size_t i = 0; i < TTYPES; i++)
		if (true == ScalarConverter::creationHandle[i].condition_handle(string_repr))
			return (ScalarConverter::creationHandle[i].creation_handle(string_repr));
	return (new s_nan());
}

//* Conditions
bool	ScalarConverter::is_Tprintable_char( const std::string string_repr ) {
	long long	integral_repr;
	
	if (is_digit(string_repr))
	{
		integral_repr = strtoll(string_repr.c_str(), nullptr, 10);
		if (integral_repr > std::numeric_limits<char>::max()
			|| integral_repr < std::numeric_limits<char>::lowest())//* useless with currrent semantics of is_digit but useful if we'll change it
			return (false);
		if (false == std::isprint(static_cast<char>(integral_repr)))
			return (false);
		else
			return (true);
	}
	else
	{
		if (string_repr.length() != 1)
			return (false);
		if (false == std::isprint(string_repr[0]))
			return (false);
		else
			return (true);
	}
}
bool	ScalarConverter::is_TInt( const std::string string_repr ) {
	long long	value;

	value = strtoll(string_repr.c_str(), nullptr, 10);
	if (
		false == is_digit(string_repr)
		|| (0 == string_repr.substr(0,1).compare("-")
				&& false == is_digit(string_repr.substr(1))
			)
		|| (value > std::numeric_limits<int>::max()
				|| value < std::numeric_limits<int>::lowest()
			)
	)
		return (false);
	else
		return (true);
}
bool	ScalarConverter::is_TFloat( const std::string string_repr ) {
	long double	value;
	char*		repr_endPtr = nullptr;

	// std::cout << "float max: " << std::numeric_limits<float>::max() << " float lowest: " << std::numeric_limits<float>::lowest() << std::endl;
	value = strtold(string_repr.c_str(), &repr_endPtr);
	if (
		(*repr_endPtr && 0 != std::strcmp(repr_endPtr, "f"))
		||
		(value > std::numeric_limits<float>::max()
			|| value < std::numeric_limits<float>::lowest())
	)
		return (false);
	else
		return (true);
}
bool ScalarConverter::is_TDouble( std::string string_repr ) {
	long double	value;
	char*		repr_endPtr = nullptr;

	// std::cout << "string: " << string_repr << std::endl;
	// std::cout << "double max: " << std::numeric_limits<double>::max() << " float lowest: " << std::numeric_limits<double>::lowest() << std::endl;
	value = strtold(string_repr.c_str(), &repr_endPtr);
	// std::cout << "value: " << value << std::endl;
	if (
		*repr_endPtr
		||
		(value > std::numeric_limits<double>::max()
			|| value < std::numeric_limits<double>::lowest())
	)
		return (false);
	else
		return (true);
}

//* Conversions
t_type*	ScalarConverter::makeTPrintableChar( const std::string string_repr ) {
	t_printable_char*	scalar;
	long long			integral_repr;

	if (is_digit(string_repr))
	{
		integral_repr = strtoll(string_repr.c_str(), nullptr, 10);
		scalar = new t_printable_char(static_cast<char>(integral_repr));
	}
	else
	{
		scalar = new t_printable_char(static_cast<char>(string_repr[0]));
	}

	return (scalar);
}
t_type*	ScalarConverter::makeTInt( const std::string string_repr ) {
	t_int*		scalar;
	long long	integral_repr;

	integral_repr = strtoll(string_repr.c_str(), nullptr, 10);
	scalar = new t_int(static_cast<int>(integral_repr));

	return (scalar);
}
t_type*	ScalarConverter::makeTFloat( const std::string string_repr ) {
	t_float*	scalar;
	long double	value;

	value = strtold(string_repr.c_str(), nullptr);
	scalar = new t_float(static_cast<float>(value));

	return (scalar);
}
t_type*	ScalarConverter::makeTDouble( const std::string string_repr ) {
	t_double*	scalar;
	long double	value;

	value = strtold(string_repr.c_str(), nullptr);
	scalar = new t_double(static_cast<double>(value));

	return (scalar);
}


//* Canonical Form shit
// Constructors
ScalarConverter::ScalarConverter()
{
	throw ScalarConverter::UnimplementedMethodException();
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
	throw (ScalarConverter::UnimplementedMethodException());
}


// Destructor
ScalarConverter::~ScalarConverter()
{
}


// Operators
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	throw (ScalarConverter::UnimplementedMethodException());

	return (*this);
}
