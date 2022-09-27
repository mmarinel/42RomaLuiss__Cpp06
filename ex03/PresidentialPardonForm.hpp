/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:04:12 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/20 14:41:23 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "Form.hpp"

# include <iostream>
# include <string>

class PresidentialPardonForm : public Form
{
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm( const std::string target );
		
		// Destructor
		~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		
	private:
		std::string							target;
		// Logic
		void	action ( void ) const;
};

#endif