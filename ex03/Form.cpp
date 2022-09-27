/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:44:05 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/23 10:37:17 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form()
	: _name("nameless"),
	_sign_grade(Grade::_min_grade), _exec_grade(Grade::_min_grade)
{
	// std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;

	_is_signed = false;
}

Form::Form(const Form &copy)
	: _name(copy._name),
	_sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
	// std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;

	_is_signed = copy.getIs_signed();
}

Form::Form(
	const std::string name,
	bool is_signed,
	const int sign_grade,
	const int exec_grade
)
	try
		: _name(name),
		_sign_grade(sign_grade), _exec_grade(exec_grade)
{
	// std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;

	_is_signed = is_signed;
}
catch (const Form::GradeTooLowException &e) {
	throw ;//! Subject is dumb and made me do this!
}
catch (const Form::GradeTooHighException &e) {
	throw ;//! Subject is dumb and made me do this!
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	(void) assign;
	// ::new(this) Form(assign);//* We can only instantiate a abstract class as a subobject. 
	//* But here we do not have the ability if we are being used as a subobject or not.
	//* Calling new results in calling the constructor (in this case on pre-allocated memory),
	//* and you can't call constructor of abstract classes excpet in the ones of a derived class
	//* (which you do explicitely or happens automatically).
	return *this;
}


// Getters / Setters
const std::string Form::getName() const
{
	return _name;
}
bool Form::getIs_signed() const
{
	return _is_signed;
}
const Grade Form::getSign_grade() const
{
	return _sign_grade;
}
const Grade Form::getExec_grade() const
{
	return _exec_grade;
}

// Logic
void	Form::beSigned( const Bureaucrat &signer )
{
	if (Grade::compare(signer.getGrade(), this->_sign_grade) < 0)
		throw SignGradeTooLowException();
	else
		this->_is_signed = true;
}
void	Form::execute(Bureaucrat const & executor) const
{
	if (false == this->_is_signed)
		throw ExecFormNotSignedException();
	if ( Grade::compare(executor.getGrade(), this->_exec_grade) < 0 )
		throw ExecGradeTooLowException();
	this->action();
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
{
	stream
		<< "{\n"
		<< "\tform name: "<< object.getName() << ",\n"
		<< "\tis signed: " << object.getIs_signed() << ",\n"
		<< "\tgrade to sign: " << object.getSign_grade().getGrade() << ",\n"
		<< "\tgrade to execute: " << object.getExec_grade().getGrade() << ",\n"
		<< "}\n"
		<< std::endl;
	return stream;
}
