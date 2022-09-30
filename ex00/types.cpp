/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:08:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/30 15:59:59 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"

static bool	is_digit(std::string arg);
//* end of static declarations

//* Constructors...if the string matches type exactly I convert it, otherwise exceptions are thrown

t_int::s_int( std::string string_repr ) {
	long long	value;

	if (is_digit(string_repr))
	{
		value = strtoll(string_repr.c_str(), nullptr, 10);
		if (value >= std::numeric_limits<int>::min()
			|| value <= std::numeric_limits<int>::max())
		{
			this->value = static_cast<int>(value);
			return ;
		}
	}
	throw ImpossibleConversion("int");
}

t_char::s_char( std::string string_repr ) {

	if (string_repr.length() == 1
		&& string_repr[0] <= std::numeric_limits<char>::max()
		&& string_repr[0] >= std::numeric_limits<char>::min())
	{
		if (false == std::isprint(string_repr[0] - 48))
			throw NonDisplayableConversion("char");
		this->value = string_repr[0];
	}
	else
		throw ImpossibleConversion("char");
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
