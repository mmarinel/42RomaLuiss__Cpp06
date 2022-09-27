/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:04:12 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/21 14:59:35 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include "Form.hpp"

# include <iostream>
# include <string>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>

class RobotomyRequestForm : public Form
{
	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm( const std::string target );
		
		// Destructor
		~RobotomyRequestForm();

		// Exceptions
		class RobotomizationFail : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);
		
	private:
		std::string			target;
		mutable bool		success;
		// Logic
		void	action ( void ) const;
};

#endif