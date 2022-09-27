/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:30:48 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/23 10:37:05 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "types.hpp"
# include "Grade.hpp"
# include "Bureaucrat.hpp"

# include <iostream>
# include <string>

class Form
{
	protected:
		virtual void	action( void ) const = 0;
	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(const std::string name, bool is_signed,
			const int sign_grade, const int exec_grade);
		
		// Destructor
		virtual ~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		
		// Getters / Setters
		const std::string	getName() const;
		bool 				getIs_signed() const;
		const Grade			getSign_grade() const;
		const Grade			getExec_grade() const;

		// Logic
		void	beSigned( const Bureaucrat &signer );
		void	execute(Bureaucrat const & executor) const;

		// Exceptions
		class GradeTooHighException : public Grade::GradeTooHighException {
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public Grade::GradeTooLowException {
		public:
			virtual const char* what() const throw();
		};
		
		class SignGradeTooLowException : public Grade::GradeTooLowException {
		public:
			virtual const char* what() const throw();
		};
		class ExecGradeTooLowException : public Grade::GradeTooLowException {
		public:
			virtual const char* what() const throw();
		};
		class ExecFormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		
	private:
		const std::string _name;
		bool _is_signed;
		const Grade _sign_grade;
		const Grade _exec_grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object);

#endif