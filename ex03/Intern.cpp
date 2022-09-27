/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:08:50 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/21 18:56:16 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const t_form Intern::form_fact[Intern::forms] = {
	{"ShrubberyCreationForm", &Intern::makeShrubberyCreationForm},
	{"RobotomyRequestForm", &Intern::makeRobotomyRequestForm},
	{"PresidentialPardonForm", &Intern::makePresidentialPardonForm}
};

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}

// Logic
Form*	Intern::makeForm( std::string formName, std::string target )
{
	size_t	idx = makeFuncIndex(formName);

	if (idx == Intern::forms)
	{
		std::cout
			<< BOLDRED
			<< "form "<< formName << " doesn't exists"
			<< RESET << std::endl;
		return (nullptr);
	}
	else
	{
		std::cout
			<< BOLDGREEN
			<< "Intern creates "<< formName
			<< RESET << std::endl;
		return ( (this->*(form_fact[idx].makeFunc)) (target));
	}
}

size_t	Intern::makeFuncIndex( std::string formName )
{
	size_t	i;

	for (i = 0; i < Intern::forms; i++)
		if (0 == formName.compare(Intern::form_fact[i].name))
			break ;
	return (i);
}

Form*	Intern::makeShrubberyCreationForm( std::string target )
{
	return (new ShrubberyCreationForm(target));
}
Form*	Intern::makeRobotomyRequestForm( std::string target )
{
	return (new RobotomyRequestForm(target));
}
Form*	Intern::makePresidentialPardonForm( std::string target )
{
	return (new PresidentialPardonForm(target));
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}
