/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:44:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/23 11:54:34 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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
			std::cout << std::endl;
			form = read_form();
			bur->signForm(*form);
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
	std::string	name;
	int			sign_grade;
	int			exec_grade;

	repeat = true;
	while (repeat)
	{
		read_string(name, "choose form name");
		read_input(&sign_grade, int, "choose form grade to sign");
		read_input(&exec_grade, int, "choose form grade to execute");
		try
		{
			form = new Form(name, false, sign_grade, exec_grade);
			repeat = false;
		}
		catch(const std::exception& e)
		{
			std::cout << "Invalid Form data: " << e.what();
			std::getchar();
			std::cout  << std::endl;
		}
	}
	return (form);
}
