/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:44:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/23 11:56:05 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

static Bureaucrat*	read_bureaucrat( void );
static void			bur_modify_grade( Bureaucrat* bur );
static void			bur_inc ( Bureaucrat *bur );
static void			bur_dec ( Bureaucrat *bur );
//* end of static declarations

int	main()
{
	Bureaucrat	*bur = nullptr;

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::eofbit);
	try {
			bur = read_bureaucrat();
			std::cout << std::endl << *bur << std::endl;
			bur_modify_grade(bur);
	}
	catch (std::istream::failure &e) {
		std::cout << "eof caught or stream broken" << std::endl;
	}
	_delete(bur);
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

static void			bur_modify_grade( Bureaucrat* bur )
{
	int	selection;
	do
	{
		std::cout << "/* Choose operation to be performed on bureaucrat*/" << std::endl;
		read_input(&selection, int,\
			"\n\
			1. increment Bureaucrat grade\n \
			2. decrement Bureaucrat grade\n \
			3. exit\
			\n");
		switch (selection)
		{
		case 1:
			bur_inc(bur);
			break;
		case 2:
			bur_dec(bur);
			break;
		
		default:
			break;
		}
	} while (selection != 3);
}

static void	bur_inc ( Bureaucrat *bur )
{
	try
	{
		bur->increment();
		std::cout << GREEN << *bur << RESET;
	}
	catch(const Grade::GradeTooHighException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		std::cout << "Press any key to retry...";
		std::getchar();
		std::cout << std::endl;
	}
}

static void	bur_dec ( Bureaucrat *bur )
{
	try
	{
		bur->decrement();
		std::cout << GREEN << *bur << RESET;
	}
	catch(const Grade::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Press any key to retry...";
		std::getchar();
		std::cout << std::endl;
	}
}
