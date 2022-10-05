/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:34:03 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/05 16:03:07 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H
#define A_H

# include "Base.hpp"

class A : public Base
{
};

std::ostream&	operator<<( std::ostream& stream, const A& obj );

#endif /* A_H */