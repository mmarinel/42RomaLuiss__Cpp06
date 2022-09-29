/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:33:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/29 19:35:27 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <iostream>
# include <string>
# include "../colors.hpp"

# define TYPES 4
# define delete(ptr) {delete ptr; ptr = nullptr;}

typedef struct s_type	t_type;
typedef struct s_char	t_char;
typedef struct s_int	t_int;
typedef struct s_float	t_float;
typedef struct s_double	t_double;

struct s_type
{
	//* Conversion operators
	virtual	operator t_char() const = 0;
	virtual	operator t_int() const = 0;
	virtual	operator t_float() const = 0;
	virtual	operator t_double() const = 0;

	//* Insertion operator
	const std::ostream&	operator <<	(std::ostream& ostream);

	//* Exceptions
	class ImpossibleConversion : public std::exception {
		public:
			virtual const char*	what() const throw();
	};
	class NonDisplayableConversion : public std::exception {
		public:
			virtual const char*	what() const throw();
	};
};

struct s_char : public t_type
{
	//* Constructors
	s_char(std::string arg);

	//* Insertion operator
	const std::ostream& operator << (std::ostream& ostream);

	//* Data
	char value;
};

struct s_int : public t_type
{
	//* Constructors
	s_int(std::string arg);

	//* Insertion operator
	const std::ostream& operator << (std::ostream& ostream);

	//* Data
	int value;
};

struct s_float : public t_type
{
	//* Constructors
	s_float(std::string arg);

	//* Insertion operator
	const std::ostream& operator << (std::ostream& ostream);

	//* Data
	float value;
};

struct s_double : public t_type
{
	//* Constructors
	s_double(std::string arg);

	//* Insertion operator
	const std::ostream& operator << (std::ostream& ostream);

	//* Data
	double value;
};

typedef t_type&(t_type::*t_cast)( void );

typedef struct t_cast_handle {
	const char*	name;
	t_cast		handle;
};

#endif /* TYPES_H */