/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:50:40 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/04 19:12:22 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

# include <iostream>

typedef struct s_Data
{
	const char*	name;//* Clegg
	const char*	rank;//* Corporal (caporale)
}	Data;

std::ostream&	operator<<( std::ostream& stream, const Data& obj);

#endif /* TYPES_H */
