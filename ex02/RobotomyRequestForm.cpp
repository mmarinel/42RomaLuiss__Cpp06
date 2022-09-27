/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:08:24 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/20 12:04:39 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", false, 72, 45)
{
	// std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;

	srand(time(NULL));
	this->success = rand() % 2 == 0 ? false : true;
	this->target.assign("output");
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target )
	: Form("RobotomyRequestForm", false, 72, 45)
{
	// std::cout << "\e[0;33mFields Constructor called of RobotomyRequestForm\e[0m" << std::endl;

	srand(time(NULL));
	this->success = rand() % 2 == 0 ? false : true;
	this->target.assign(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: Form(
		copy.getName(),
		copy.getIs_signed(),
		copy.getSign_grade().getGrade(),
		copy.getExec_grade().getGrade()
	)
{
	// std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;

	srand(time(NULL));
	this->success = rand() % 2 == 0 ? false : true;
	*this = copy;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	this->target.assign(assign.target);
	this->Form::operator=(assign);

	return (*this);
}


// Logic
void	RobotomyRequestForm::action( void ) const
{
	std::cout << "drill drullulul drll drill drill drll drll drill drill" << std::endl;
	this->success = !(this->success);
	if (true == this->success)
		std::cout
			<< GREEN
			<< this->target << " has been robotomized successfully"
			<< RESET
			<< std::endl;
	else
	{
		std::cout
			<< RED
			<< this->target << " robotomization failed"
			<< RESET
			<< std::endl;
		throw RobotomyRequestForm::RobotomizationFail();
	}
}
