/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:34:09 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/05 16:03:10 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_H
#define B_H

# include "Base.hpp"

class B : public Base
{
};

std::ostream&	operator<<( std::ostream& stream, const B& obj );

#endif /* B_H */