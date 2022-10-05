/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:34:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/05 16:03:13 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_H
#define C_H

# include "Base.hpp"

class C : public Base
{
};

std::ostream&	operator<<( std::ostream& stream, const C& obj );
#endif /* C_H */