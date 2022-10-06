/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:04:02 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/06 15:07:02 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"
# include "ScalarConverter.hpp"


s_type::ImpossibleConversion::ImpossibleConversion()
	: msg(RED "Impossible Conversion" RESET) {}

s_type::NonDisplayableConversion::NonDisplayableConversion()
	: msg(RED "NonDisplayable Conversion" RESET) {}

s_type::ImpossibleConversion::ImpossibleConversion( const char* sig)
	: msg(std::string(sig) + std::string(":\t" RED "Impossible Conversion" RESET)) {}

s_type::NonDisplayableConversion::NonDisplayableConversion( const char* sig )
	: msg(std::string(sig) + std::string(":\t" RED "Non-Displayable Conversion" RESET)) {}

const char*	s_type::ImpossibleConversion::what( void ) const throw() {
	return (this->msg.c_str());
}

const char*	s_type::NonDisplayableConversion::what( void ) const throw() {
	return (this->msg.c_str());
}

s_type::ImpossibleConversion::~ImpossibleConversion() throw() {}
s_type::NonDisplayableConversion::~NonDisplayableConversion() throw() {}


const char*	ScalarConverter::UnimplementedMethodException::what() const throw() {
	return ( "ScalarConverter: " RED "object-related method makes no sense to abstract factory class" RESET);
}
