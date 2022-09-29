/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:04:02 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/29 11:07:34 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"

const char*	s_type::ImpossibleConversion::what( void ) const throw() {
	return (BOLDRED "Impossible" RESET);
}

const char*	s_type::NonDisplayableConversion::what( void ) const throw() {
	return (BOLDRED "Non Displayable" RESET);
}
