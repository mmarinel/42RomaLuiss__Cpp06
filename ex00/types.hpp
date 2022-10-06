/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:33:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/06 12:58:13 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>

# include "../colors.hpp"
# include "utils.hpp"

# define TYPES 4
# define delete(ptr) {delete ptr; ptr = nullptr;}

typedef struct s_type			t_type;
typedef struct s_printable_char	t_printable_char;
typedef struct s_int			t_int;
typedef struct s_float			t_float;
typedef struct s_double			t_double;
typedef struct s_nat			t_nat;

struct s_type
{
	virtual ~s_type();

	//* Conversions
	virtual	t_printable_char	toTPrintChar() const = 0;
	virtual	t_int				toTInt() const = 0;
	virtual	t_float				toTFloat() const = 0;
	virtual	t_double			toTDouble() const = 0;

	//* Exceptions
	class ImpossibleConversion : public std::exception {
		public:
			ImpossibleConversion();
			ImpossibleConversion(const char* sig);
			~ImpossibleConversion() throw();
			virtual const char*	what() const throw();
		private:
			const std::string	msg;
	};
	class NonDisplayableConversion : public std::exception {
		public:
			NonDisplayableConversion();
			NonDisplayableConversion(const char* sig);
			~NonDisplayableConversion() throw();
			virtual const char*	what() const throw();
		private:
			const std::string	msg;
	};
};

struct s_printable_char : public t_type
{
	//* Constructors
	s_printable_char(const char char_repr);

	//* Conversions
	virtual	t_printable_char	toTPrintChar() const;
	virtual	t_int				toTInt() const;
	virtual	t_float				toTFloat() const;
	virtual	t_double			toTDouble() const;

	//* Data
	char value;
};

struct s_int : public t_type
{
	//* Constructors
	s_int(const int int_repr);

	//* Conversions
	virtual	t_printable_char	toTPrintChar() const;
	virtual	t_int				toTInt() const;
	virtual	t_float				toTFloat() const;
	virtual	t_double			toTDouble() const;

	//* Data
	int value;
};

struct s_float : public t_type
{
	//* Constructors
	s_float(const float float_repr);

	//* Conversions
	virtual	t_printable_char	toTPrintChar() const;
	virtual	t_int				toTInt() const;
	virtual	t_float				toTFloat() const;
	virtual	t_double			toTDouble() const;

	//* Data
	float	value;
	bool	nanf;
	bool	posInff;
	bool	negInff;
};

struct s_double : public t_type
{
	//* Constructors
	s_double(const double double_repr);

	//* Conversions
	virtual	t_printable_char	toTPrintChar() const;
	virtual	t_int				toTInt() const;
	virtual	t_float				toTFloat() const;
	virtual	t_double			toTDouble() const;
	
	//* Data
	double value;
	bool	nan;
	bool	posInf;
	bool	negInf;
};

	//* nat = "not a type"
struct s_nat : public t_type
{
	//* Conversions
	virtual	t_printable_char	toTPrintChar() const;
	virtual	t_int				toTInt() const;
	virtual	t_float				toTFloat() const;
	virtual	t_double			toTDouble() const;
};

//* Insertion operators
std::ostream& operator << ( std::ostream& ostream, const t_printable_char& tchar );
std::ostream& operator << ( std::ostream& ostream, const t_int& tint );
std::ostream& operator << ( std::ostream& ostream, const t_float& tfloat );
std::ostream& operator << ( std::ostream& ostream, const t_double& tdouble );
std::ostream& operator << ( std::ostream& ostream, const t_nat& tnan );

#endif /* TYPES_H */