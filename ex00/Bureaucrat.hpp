/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:51:53 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/27 14:44:44 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define BC_MAX_GRADE 1
# define BC_MIN_GRADE 150
# define BC_INC_FACTOR -1
# define BC_HIGHER <
# define BC_LESSER >

# include "types.hpp"
# include "Grade.hpp"
# include "utils.hpp"

# include <iostream>
# include <string>

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat( const Bureaucrat &copy );
		Bureaucrat( const std::string name, int grade );

		// Destructor
		~Bureaucrat();

		// Operators
		Bureaucrat & operator=( const Bureaucrat &assign );
		
		// Getters / Setters
		const std::string	getName() const;
		const Grade			getGrade() const;

		// Logic
		void	increment	( void );
		void	decrement	( void );
		// void	signForm	( Form &form ); //* If this was declared but never called, compiler would give no errors!

		// Exceptions
		class GradeTooHighException : public Grade::GradeTooHighException {
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public Grade::GradeTooLowException {
		public:
			virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		Grade				_grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif