/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:08:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 12:28:34 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"


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

t_printable_char::s_printable_char( const char char_repr) {
	
	if (false == std::isprint(char_repr))
		throw NonDisplayableConversion("char");
	else
		this->value = char_repr;
}

t_int::s_int( const int int_repr) {
	this->value = int_repr;
}

t_float::s_float( const float float_repr) {
	this->value = float_repr;
}

t_double::s_double( const double double_repr) {
	this->value = double_repr;
}

// * Conversions

t_printable_char	t_nan::toTPrintChar() const {
	throw ImpossibleConversion("char");
}
t_int				t_nan::toTInt() const {
	throw ImpossibleConversion("int");
}
t_float				t_nan::toTFloat() const {
	throw ImpossibleConversion("float");
}
t_double			t_nan::toTDouble() const {
	throw ImpossibleConversion("double");
}

	//* t_printable_char type
t_printable_char	t_printable_char::toTPrintChar() const {
	return (t_printable_char(this->value));
}
t_int				t_printable_char::toTInt() const {
	return (t_int(static_cast<int>(this->value)));
}
t_float				t_printable_char::toTFloat() const {
	return (t_float(static_cast<float>(this->value)));
}
t_double			t_printable_char::toTDouble() const {
	return (t_double(static_cast<double>(this->value)));
}
	//* t_int type
t_printable_char	t_int::toTPrintChar() const {
	if (this->value > std::numeric_limits<char>::max()
		|| this->value < std::numeric_limits<char>::min())
		throw ImpossibleConversion("char");
	if (false == std::isprint(static_cast<char>(this->value)))
		throw NonDisplayableConversion("char");
	return (t_printable_char(this->value));
}
t_int				t_int::toTInt() const {
	return (t_int(this->value));
}
t_float				t_int::toTFloat() const {
	return (t_float(static_cast<float>(this->value)));
}
t_double			t_int::toTDouble() const {
	return (t_double(static_cast<double>(this->value)));
}
	//* t_float type
t_printable_char	t_float::toTPrintChar() const {
	long long int	integral_repr;

	integral_repr = static_cast<long long int>(this->value);
	if (
		integral_repr >= std::numeric_limits<char>::max()
		&& integral_repr <= std::numeric_limits<char>::lowest()
		&& std::isprint(integral_repr)
	)
		return (t_printable_char(static_cast<char>(this->value)));
	else
		throw t_type::ImpossibleConversion("char");
}
t_int				t_float::toTInt() const {
	if (
		this->value <= std::numeric_limits<int>::max()
		&& this->value >= std::numeric_limits<int>::lowest()
	)
		return (t_int(static_cast<int>(this->value)));
	else
		throw ImpossibleConversion("int");
}
t_float				t_float::toTFloat() const {
	return (t_float(this->value));
}
t_double			t_float::toTDouble() const {
	return (t_double(static_cast<double>(this->value)));
}
	//* double type
t_printable_char	t_double::toTPrintChar() const {
	long long int	integral_repr;

	integral_repr = static_cast<long long int>(this->value);
	if (
		integral_repr >= std::numeric_limits<char>::max()
		&& integral_repr <= std::numeric_limits<char>::lowest()
		&& std::isprint(integral_repr)
	)
		return (t_printable_char(static_cast<char>(this->value)));
	else
		throw t_type::ImpossibleConversion("char");
}
t_int				t_double::toTInt() const {
	if (
		this->value <= std::numeric_limits<int>::max()
		&& this->value >= std::numeric_limits<int>::lowest()
	)
		return (t_int(static_cast<int>(this->value)));
	else
		throw ImpossibleConversion("int");
}
t_float				t_double::toTFloat() const {
	return (t_float(static_cast<t_float>(this->value)));
}
t_double			t_double::toTDouble() const {
	return (t_double(static_cast<t_double>(this->value)));
}

//* insertion operators VERY UGLY i know!
std::ostream&	operator<<(std::ostream& ostream, const t_printable_char& tchar) {
	ostream << "char: " << tchar.value;

	return (ostream);
}

std::ostream&	operator<<(std::ostream& ostream, const t_int& tint) {
	ostream << "int: " << tint.value;

	return (ostream);
}

std::ostream&	operator<<(std::ostream& ostream, const t_float& tfloat) {
	if (tfloat.value - static_cast<int>(tfloat.value) != 0)
		ostream << "float: " << tfloat.value << "f";
	else
		ostream << "float: " << tfloat.value << ".0f";
	return (ostream);
}

std::ostream&	operator<<(std::ostream& ostream, const t_double& tdouble) {
	if (tdouble.value - static_cast<int>(tdouble.value) != 0)
		ostream << "double: " << tdouble.value;
	else
		ostream << "double: " << tdouble.value << ".0";
	return (ostream);
}

//* Destructors

t_type::~s_type() {
}
