/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:08:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 16:48:50 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"


//* Constructors...if the string matches type exactly I convert it, otherwise exceptions are thrown

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
	this->posInff = false;
	this->negInff = false;
	this->nanf = false;
}

t_double::s_double( const double double_repr) {
	this->value = double_repr;
	this->posInf = false;
	this->negInf = false;
	this->nan = false;
}

// * Conversions

	//* nan value
t_printable_char	t_nat::toTPrintChar() const {
	throw ImpossibleConversion("char");
}
t_int				t_nat::toTInt() const {
	throw ImpossibleConversion("int");
}
t_float				t_nat::toTFloat() const {
	t_float	scalar = t_float(0.0f);

	scalar.nanf = true;
	scalar.posInff = false;
	scalar.negInff = false;

	return (scalar);
}
t_double			t_nat::toTDouble() const {
	t_double	scalar = t_double(0.0f);

	scalar.nan = true;
	scalar.posInf = false;
	scalar.negInf = false;

	return (scalar);
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
		|| this->value < std::numeric_limits<char>::lowest())
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

	if (this->negInff || this->posInff || this->nanf)
		throw t_type::ImpossibleConversion("char");
	else
	{
		integral_repr = static_cast<long long int>(this->value);
		if (
			integral_repr > std::numeric_limits<char>::max()
			|| integral_repr < std::numeric_limits<char>::lowest()
		)
			throw ImpossibleConversion("char");
		else if (false == std::isprint(integral_repr))
			throw NonDisplayableConversion("char");
		else
			return (t_printable_char(static_cast<char>(this->value)));
	}
}
t_int				t_float::toTInt() const {
	if (this->posInff || this->negInff || this->nanf)
		throw ImpossibleConversion("int");
	else
	{
		if (
			this->value <= std::numeric_limits<int>::max()
			&& this->value >= std::numeric_limits<int>::lowest()
		)
			return (t_int(static_cast<int>(this->value)));
		else
			throw ImpossibleConversion("int");
	}
}
t_float				t_float::toTFloat() const {
	t_float	scalar = t_float(this->value);

	scalar.nanf = this->nanf;
	scalar.posInff = this->posInff;
	scalar.negInff = this->negInff;

	return (scalar);
}
t_double			t_float::toTDouble() const {
	t_double	scalar = t_double(static_cast<double>(this->value));

	scalar.nan = this->nanf;
	scalar.posInf = this->posInff;
	scalar.negInf = this->negInff;

	return (scalar);
}
	//* double type
t_printable_char	t_double::toTPrintChar() const {
	long long int	integral_repr;

	if (this->posInf || this->negInf || this->nan)
		throw ImpossibleConversion("char");
	else
	{
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
}
t_int				t_double::toTInt() const {
	if (this->posInf ||  this->negInf || this->nan)
		throw ImpossibleConversion("int");
	else
	{
		if (
			this->value <= std::numeric_limits<int>::max()
			&& this->value >= std::numeric_limits<int>::lowest()
		)
			return (t_int(static_cast<int>(this->value)));
		else
			throw ImpossibleConversion("int");
	}
}
t_float				t_double::toTFloat() const {
	t_float	scalar = t_float(static_cast<t_float>(this->value));

	scalar.posInff = this->posInf
		|| this->value > std::numeric_limits<float>::max();
	scalar.negInff = this->negInf
		|| this->value < std::numeric_limits<float>::lowest();
	scalar.nanf = this->nan;

	return (scalar);
}
t_double			t_double::toTDouble() const {
	t_double	scalar = t_double(static_cast<t_double>(this->value));

	scalar.posInf = this->posInf;
	scalar.negInf = this->negInf;
	scalar.nan = this->nan;

	return (scalar);
}

//* insertion operators VERY UGLY, I know!
std::ostream&	operator<<(std::ostream& ostream, const t_printable_char& tchar) {
	ostream << "char:\t" << tchar.value;

	return (ostream);
}

std::ostream&	operator<<(std::ostream& ostream, const t_int& tint) {
	ostream << "int:\t" << tint.value;

	return (ostream);
}

std::ostream&	operator<<(std::ostream& ostream, const t_float& tfloat) {
	if (tfloat.posInff)
		ostream << "float:\t+inff";
	else if (tfloat.negInff)
		ostream << "float:\t-inff";
	else if (tfloat.nanf)
		ostream << "float:\tnanf";
	else
	{
		if (tfloat.value - static_cast<int>(tfloat.value) != 0)
			ostream << "float:\t" << tfloat.value << "f";
		else
			ostream << "float:\t" << tfloat.value << ".0f";
	}
	return (ostream);
}

std::ostream&	operator<<(std::ostream& ostream, const t_double& tdouble) {
	if (tdouble.posInf)
		ostream << "double:\t+inf";
	else if (tdouble.negInf)
		ostream << "double:\t-inf";
	else if (tdouble.nan)
		ostream << "double:\tnan";
	else
	{
		if (tdouble.value - static_cast<int>(tdouble.value) != 0)
			ostream << "double:\t" << tdouble.value;
		else
			ostream << "double:\t" << tdouble.value << ".0";
	}
	return (ostream);
}

//* Destructors

t_type::~s_type() {
}
