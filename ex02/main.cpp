/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:44:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/23 11:54:50 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

#include <fstream>
#include <iostream>
#include <string>

static Bureaucrat*	read_bureaucrat( void );
static Form*		read_form( void );
//* end of static declarations

int	main()
{
	Bureaucrat	*bur = nullptr;
	Form		*form = nullptr;
	bool		repeat;

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::eofbit);
	repeat = true;
	while (repeat)
	{
		try {
			bur = read_bureaucrat();
			form = read_form();
			bur->signForm(*form);
			bur->executeForm(*form);
			repeat = false;
		}
		catch (std::istream::failure &e) {
			std::cout << BOLDRED << "eof caught or stream broken" << RESET << std::endl;
			repeat = false;
		}
		catch (std::exception &e) {
			std::cout << "\npress any key to retry..." << std::endl;
			getchar();
		}
		_delete(bur);
		_delete(form);
	}
	return 0;
}

static Bureaucrat*	read_bureaucrat( void )
{
	Bureaucrat*	bur = nullptr;
	bool		repeat;
	std::string	bur_name;
	int			bur_grade;

	repeat = true;
	while (repeat)
	{
		read_string(bur_name, "enter bureaucrat name");
		read_input(&bur_grade, int, "insert bureaucrat grade");
		try {
			bur = new Bureaucrat(bur_name, bur_grade);
			repeat = false;
		}
		catch (std::exception& e) {
			std::cout << "Invalid bureaucrat data: " << e.what() << std::endl;
			std::cout << "Press any key to retry...";
			std::getchar();
			std::cout  << std::endl;
		}
	}
	return (bur);
}

static Form*	read_form( void )
{
	Form*		form = nullptr;
	bool		repeat;
	int			selection;
	std::string	target;

	repeat = true;
	while (repeat)
	{
		do
		{
			read_input(\
				&selection,\
				int,\
				"choose form type:\n|\t1. ShrubberyCreation\t2. RobotomyRequest\t 3. PresidentialPardon|\n"
			);
		} while (selection < 1 || selection > 3);
		read_string(target, "choose target name");
		try
		{
			switch (selection)
			{
			case 1:
				form = new ShrubberyCreationForm(target);
				break;
			case 2:
				form = new RobotomyRequestForm(target);
				break;
			case 3:
				form = new PresidentialPardonForm(target);
				break;

			default:
				break;
			}
			repeat = false;
		}
		catch(const std::exception& e)
		{
			std::cout << "Invalid Form data: " << e.what();
			std::getchar();
			std::cout  << std::endl;
		}
	}
	return  (form);
}
