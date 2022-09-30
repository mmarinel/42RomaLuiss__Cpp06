/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:08:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/30 16:54:47 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"

static bool	is_digit(std::string arg);
//* end of static declarations

//* Constructors...if the string matches type exactly I convert it, otherwise exceptions are thrown

t_int::s_int( const std::string string_repr ) {
	long long	value;

	// std::cout << "string: " << string_repr << std::endl;
	value = strtoll(string_repr.c_str(), nullptr, 10);
	if (
		(is_digit(string_repr)
			|| (0 == string_repr.substr(0,1).compare("-")
				&& is_digit(string_repr.substr(1)))
		)
		&& (value >= std::numeric_limits<int>::min()
			&& value <= std::numeric_limits<int>::max())
	)
	{
		this->value = static_cast<int>(value);
	}
	else
		throw ImpossibleConversion("int");
}

t_char::s_char( std::string string_repr ) {
	long long	integral_repr;

	if (is_digit(string_repr))
	{
		integral_repr = strtoll(string_repr.c_str(), nullptr, 10);
		if (integral_repr > std::numeric_limits<char>::max()
			|| integral_repr < std::numeric_limits<char>::min())//* useless
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

//* insertion operators VERY UGLY i know!
const std::ostream&	operator<<(std::ostream& ostream, const t_char& tchar) {
	ostream << tchar.value;

	return (ostream);
}

const std::ostream&	operator<<(std::ostream& ostream, const t_int& tint) {
	ostream << tint.value;

	return (ostream);
}

// const std::ostream&	t_float::operator<<(std::ostream& ostream) {
// 	ostream << this->value;
// }

// const std::ostream&	t_double::operator<<(std::ostream& ostream) {
// 	ostream << this->value;
// }

static bool	is_digit(std::string arg)
{
	if (arg.empty())
		return (false);
	for (size_t i = 0; i < arg.length(); i++)
		if (false == std::isdigit(arg[i]))
			return (false);
	return (true);
}
