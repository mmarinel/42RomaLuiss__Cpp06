/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:08:24 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/20 12:04:39 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", false, 25, 5)
{
	// std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;

	this->target.assign("output");
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : Form("PresidentialPardonForm", false, 25, 5)
{
	// std::cout << "\e[0;33mFields Constructor called of PresidentialPardonForm\e[0m" << std::endl;

	this->target.assign(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: Form(
		copy.getName(),
		copy.getIs_signed(),
		copy.getSign_grade().getGrade(),
		copy.getExec_grade().getGrade()
	)
{
	// std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;

	*this = copy;
}


// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	this->target.assign(assign.target);
	this->Form::operator=(assign);

	return (*this);
}


// Logic
void	PresidentialPardonForm::action( void ) const
{
	std::cout
		<< GREEN
		<< this->target << " has been pardoned by Zaphod Beeblebrox"
		<< RESET
		<< std::endl;
}
