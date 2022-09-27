/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:08:25 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/21 18:06:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# include <iostream>
# include <string>

typedef struct s_form	t_form;//* forward declaration

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Logic
		Form*	makeForm( std::string formName, std::string target );
		
		// Operators
		Intern & operator=(const Intern &assign);
		
	private:
		Form*				makeShrubberyCreationForm( std::string target );
		Form*				makeRobotomyRequestForm( std::string target );
		Form*				makePresidentialPardonForm( std::string target );
		size_t				makeFuncIndex( std::string formName );
		static const size_t	forms = 3;
		static const t_form	form_fact[forms];
};

typedef Form*(Intern::*makeFunction)( std::string target );

struct s_form
{
	const char*		name;
	makeFunction	makeFunc;
};

#endif