/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:04:02 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/30 15:53:02 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"


s_type::ImpossibleConversion::ImpossibleConversion()
	: msg("ImpossibleConversion") {}

s_type::NonDisplayableConversion::NonDisplayableConversion()
	: msg("NonDisplayableConversion") {}

s_type::ImpossibleConversion::ImpossibleConversion( const char* sig)
	: msg(std::string(sig) + std::string(" : ImpossibleConversion")) {}

s_type::NonDisplayableConversion::NonDisplayableConversion( const char* sig )
	: msg(std::string(sig) + std::string(" : NonDisplayableConversion")) {}

const char*	s_type::ImpossibleConversion::what( void ) const throw() {
	return (this->msg.c_str());
}

const char*	s_type::NonDisplayableConversion::what( void ) const throw() {
	return (this->msg.c_str());
}

s_type::ImpossibleConversion::~ImpossibleConversion() throw() {}
s_type::NonDisplayableConversion::~NonDisplayableConversion() throw() {}