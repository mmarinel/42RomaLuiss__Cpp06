/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:08:13 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/21 15:01:00 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Grade.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"

// Grade
const char * Grade::GradeTooHighException::what() const throw()
{
	return BOLDRED "Grade: grade too high" RESET;
}
const char * Grade::GradeTooLowException::what() const throw()
{
	return BOLDRED "Grade: grade too low" RESET;
}

// Bureaucrat
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return BOLDRED "Bureaucrat: grade too high" RESET;
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return BOLDRED "Bureaucrat: grade too low" RESET;
}

// Form
const char * Form::GradeTooLowException::what() const throw()
{
	return (BOLDRED "Form: grade too low for creation" RESET);
}
const char * Form::GradeTooHighException::what() const throw()
{
	return (BOLDRED "Form: grade too high for creation" RESET);
}
const char * Form::SignGradeTooLowException::what() const throw()
{
	return (BOLDRED "Form: grade too low for signing" RESET);
}
const char * Form::ExecGradeTooLowException::what() const throw()
{
	return (BOLDRED "Form: grade too low for executing" RESET);
}
const char * Form::ExecFormNotSignedException::what() const throw()
{
	return (BOLDRED "Form: cannot execute before signing" RESET);
}
const char * RobotomyRequestForm::RobotomizationFail::what() const throw()
{
	return (BOLDRED "RobotomyRequestForm: robotomization failed" RESET);
}
