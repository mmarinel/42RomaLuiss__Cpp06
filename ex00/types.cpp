/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:08:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/30 19:09:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"

static bool	is_digit(std::string arg);
//* end of static declarations

//* Constructors...if the string matches type exactly I convert it, otherwise exceptions are thrown

t_int::s_int( const std::string string_repr ) {
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
		throw ImpossibleConversion("int");
	else
		this->value = static_cast<int>(value);
}

t_printable_char::s_printable_char( const std::string string_repr ) {
	long long	integral_repr;

	if (is_digit(string_repr))
	{
		integral_repr = strtoll(string_repr.c_str(), nullptr, 10);
		if (integral_repr > std::numeric_limits<char>::max()
			|| integral_repr < std::numeric_limits<char>::lowest())//* useless
			throw ImpossibleConversion("char");
		if (false == std::isprint(static_cast<char>(integral_repr)))
			throw NonDisplayableConversion("char");
		this->value = static_cast<char>(integral_repr);
	}
	else
	{
		if (string_repr.length() != 1)
			throw ImpossibleConversion("char");
		if (false == std::isprint(string_repr[0]))
			throw NonDisplayableConversion("char");
		this->value = static_cast<char>(string_repr[0]);
	}
}

t_float::s_float( const std::string string_repr ) {
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
		throw ImpossibleConversion("float");
	else
		this->value = static_cast<float>(value);
}

t_double::s_double( const std::string string_repr ) {
	long double	value;
	char*		repr_endPtr = nullptr;

	std::cout << "string: " << string_repr << std::endl;
	std::cout << "double max: " << std::numeric_limits<double>::max() << " float lowest: " << std::numeric_limits<double>::lowest() << std::endl;
	value = strtold(string_repr.c_str(), &repr_endPtr);
	std::cout << "value: " << value << std::endl;
	if (
		*repr_endPtr
		||
		(value > std::numeric_limits<double>::max()
			|| value < std::numeric_limits<double>::lowest())
	)
		throw ImpossibleConversion("double");
	else
		this->value = static_cast<double>(value);
}

//* insertion operators VERY UGLY i know!
const std::ostream&	operator<<(std::ostream& ostream, const t_printable_char& tchar) {
	ostream << tchar.value;

	return (ostream);
}

const std::ostream&	operator<<(std::ostream& ostream, const t_int& tint) {
	ostream << tint.value;

	return (ostream);
}

const std::ostream&	operator<<(std::ostream& ostream, const t_float& tfloat) {
	ostream << tfloat.value;

	return (ostream);
}

const std::ostream&	operator<<(std::ostream& ostream, const t_double& tdouble) {
	ostream << tdouble.value;

	return (ostream);
}

static bool	is_digit(std::string arg)
{
	if (arg.empty())
		return (false);
	for (size_t i = 0; i < arg.length(); i++)
		if (false == std::isdigit(arg[i]))
			return (false);
	return (true);
}
