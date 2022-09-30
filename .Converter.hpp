/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:06:52 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/27 16:51:10 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>

class Converter
{
	public:
		// Constructors
		Converter();
		Converter(const Converter &copy);
		Converter(const char* literal);
		
		// Destructor
		~Converter();
		
		// Operators
		Converter&		operator=(const Converter &assign);
		std::ostream&	operator<<(std::ostream &stream);
		
	private:
		const std::string	literal;
		const char			__char_repr;
		const int			__int_repr;
		const float			__float_repr;
		const double		__double_repr;
		
		// Logic
		char	_toChar( void );
		int		_toInt( void );
		float	_toFloat( void );
		double	_toDouble( void );
};

// Stream operators

#endif