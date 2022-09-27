/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:08:24 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/21 12:20:46 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", false, 145, 137)
{
	// std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;

	this->target.assign("output");
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : Form("ShrubberyCreationForm", false, 145, 137)
{
	// std::cout << "\e[0;33mFields Constructor called of ShrubberyCreationForm\e[0m" << std::endl;

	this->target.assign(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	// std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;

	*this = copy;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	this->target.assign(assign.target);
	this->Form::operator=(assign);

	return (*this);
}


// Logic
void	ShrubberyCreationForm::action( void ) const
{
	std::ofstream	target (this->target + "_shrubbery");

	target
	<< "     _-_ \n\
    /~~   ~~\n\
 /~~         ~~\n\
{               } \n\
   _-     -_  / \n\
   ~  \\ //  ~ \n\
_- -   | | _- _ \n\
  _ -  | |   -_ \n\
      // \\ \n\
"
	<< std::endl
	<< "     _-_ \n\
    /~~   ~~ \n\
 /~~         ~~ \n\
{               } \n\
   _-     -_  / \n\
   ~  \\ //  ~ \n\
_- -   | | _- _ \n\
  _ -  | |   -_ \n\
      // \\ \n\
";
	target.close();
}
