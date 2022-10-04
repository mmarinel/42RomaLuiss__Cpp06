/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:04:02 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 16:27:19 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"
# include "ScalarConverter.hpp"


s_type::ImpossibleConversion::ImpossibleConversion()
	: msg("ImpossibleConversion") {}

s_type::NonDisplayableConversion::NonDisplayableConversion()
	: msg("NonDisplayableConversion") {}

s_type::ImpossibleConversion::ImpossibleConversion( const char* sig)
	: msg(std::string(sig) + std::string(":\tImpossibleConversion")) {}

s_type::NonDisplayableConversion::NonDisplayableConversion( const char* sig )
	: msg(std::string(sig) + std::string(":\tNonDisplayableConversion")) {}

const char*	s_type::ImpossibleConversion::what( void ) const throw() {
	return (this->msg.c_str());
}

const char*	s_type::NonDisplayableConversion::what( void ) const throw() {
	return (this->msg.c_str());
}

s_type::ImpossibleConversion::~ImpossibleConversion() throw() {}
s_type::NonDisplayableConversion::~NonDisplayableConversion() throw() {}


const char*	ScalarConverter::UnimplementedMethodException::what() const throw() {
	return ("ScalarConverter: object-related method make no sense to abstract factory class");
}
