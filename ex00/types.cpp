/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:08:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/29 19:26:40 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.hpp"

const std::ostream&	s_type::operator<<(std::ostream& ostream) {
	const t_cast_handle casts[TYPES] = {
		{"char", &t_type::operator t_char},
		{"int", &s_type::to_tint},
		{"float", &s_type::to_tfloat},
		{"double", &s_type::to_tdouble}
	};
}