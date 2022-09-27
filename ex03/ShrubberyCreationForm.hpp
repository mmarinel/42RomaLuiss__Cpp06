/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:04:12 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/20 12:04:51 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

# include <fstream>
# include <iostream>
# include <string>

class ShrubberyCreationForm : public Form
{
	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm( const std::string target );
		
		// Destructor
		~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		
	private:
		std::string	target;
		// Logic
		void	action ( void ) const;
};

#endif