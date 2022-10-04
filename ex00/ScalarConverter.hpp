/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:04:22 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 10:08:24 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

# include "types.hpp"
# include "utils.hpp"

# define TTYPES 4

//*...................Forward-Declarations............*/
class ScalarConverter;

//*											This is a Factory Class that we would like not to be instantiated or extended					*//
class ScalarConverter
{
	typedef t_type*(*makeType)( std::string string_repr );
	typedef bool(*isType)( std::string string_repr );
	
	typedef struct s_creation_handle {
		isType		condition_handle;
		makeType	creation_handle;
	}	t_creation_handle;
	
	public:
		//* Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		//* Destructor
		~ScalarConverter();
		
		//* Operators
		ScalarConverter & operator=(const ScalarConverter &assign);
		
		//* Logic
		t_type*	getScalar( const std::string string_repr );

		//* Exception
		class UnimplementedMethodException : public std::exception {
			public:
				const char*	what() const throw();
		};
	private:
		//* Creation functions
		static t_type*					makeTPrintableChar( const std::string string_repr );
		static t_type*					makeTInt( const std::string string_repr );
		static t_type*					makeTFloat( const std::string string_repr );
		static t_type*					makeTDouble( const std::string string_repr );
		//* Conditions
		static bool						is_Tprintable_char ( const std::string string_repr );
		static bool						is_TInt ( const std::string string_repr );
		static bool						is_TFloat ( const std::string string_repr );
		static bool						is_TDouble ( const std::string string_repr );
		//* Object Status
		static const t_creation_handle	creationHandle[TTYPES];
};

#endif