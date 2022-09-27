/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grade.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:54:53 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/23 10:30:22 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grade.hpp"

const Grade Grade::_max_grade = Grade(1);
const Grade Grade::_min_grade = Grade(150);
const int	Grade::_inc_factor = -1;

// Constructors
Grade::Grade()
{
	this->_grade = Grade::_min_grade.getGrade();

	std::cout << "\e[0;33mDefault Constructor called of Grade\e[0m" << std::endl;
}

Grade::Grade(const Grade &copy)
{
	// std::cout << "\e[0;33mCopy Constructor called of Grade\e[0m" << std::endl;

	this->_grade = copy._grade;
}

Grade::Grade( int grade )
{
	std::cout << "\e[0;33mFields Constructor called of Grade\e[0m" << std::endl;

	this->_grade = grade;
	if (this != &Grade::_min_grade && this != &Grade::_max_grade)
	{
		if (Grade::compare(*this, Grade::_max_grade) > 0)
			throw Grade::GradeTooHighException();
		if (Grade::compare(*this, Grade::_min_grade) < 0)
			throw Grade::GradeTooLowException();
	}
}

// Destructor
Grade::~Grade()
{
	std::cout << "\e[0;31mDestructor called of Grade\e[0m" << std::endl;
}

// Operators
Grade & Grade::operator=(const Grade &assign)
{
	_grade = assign.getGrade();
	return *this;
}

bool	Grade::operator==(const Grade &other)
{
	return (this->_grade == other._grade);
}

bool	Grade::operator!=(const Grade &other)
{
	return (this->_grade != other._grade);
}


// Getters / Setters
int Grade::getGrade() const
{
	return _grade;
}

//Logic
int	Grade::compare( const Grade& g1, const Grade& g2 )
{
	return (-1) * (g1.getGrade() - g2.getGrade());
}

void	Grade::increment( void )
{
	if (Grade::compare(*this, Grade::_max_grade) >= 0)
		throw Grade::GradeTooHighException();
	else
		this->_grade += Grade::_inc_factor;
}

void	Grade::decrement( void )
{
	if (Grade::compare(*this, Grade::_min_grade) <= 0)
		throw Grade::GradeTooLowException();
	else
		this->_grade -= Grade::_inc_factor;
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Grade &object)
{
	stream << "grade: " << object.getGrade() << std::endl;
	return stream;
}
