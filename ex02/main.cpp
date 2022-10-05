/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:25:48 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/05 16:02:55 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <time.h>

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

# define CONCRETE_CLASSES 3

//* custom TYPES
typedef Base*(*t_creation_handle)( void );

//* static Functions
static Base*	generate( void );
static void		identify(Base* p);
static void		identify(Base& p);
static void		identify_by_ref( Base& p, size_t step );
static Base*	makeA(void);
static Base*	makeB(void);
static Base*	makeC(void);
//* end of static declarations

int main( void )
{
	Base*	obj = generate();

	identify(obj);
	identify(*obj);

	delete obj;

	std::cout << "\nTESTS END\n\n";
	return 0;
}

static Base*	generate( void )
{
	static const	t_creation_handle	creation_handle[CONCRETE_CLASSES] = {
		&makeA,
		&makeB,
		&makeC
	};
	static 			bool	first_call = true;

	if (first_call)
	{
		srand(time(NULL));
		first_call = false;
	}
	return creation_handle[rand() % CONCRETE_CLASSES]();
}

static void		identify(Base* p)
{
	if (nullptr != dynamic_cast<A*>(p))
		std::cout << GREEN << "A" << RESET << std::endl;
	else if (nullptr != dynamic_cast<B*>(p))
		std::cout << GREEN << "B" << RESET << std::endl;
	else if (nullptr != dynamic_cast<C*>(p))
		std::cout << GREEN << "C" << RESET << std::endl;
	else
		std::cout << RED << "Not recognized" << RESET << std::endl;
}

static void		identify(Base& p)
{
	identify_by_ref(p, 0);
}

static void		identify_by_ref( Base& p, size_t step )
{
	try
	{
		switch (step)
		{
		case 0:
			std::cout << GREEN << dynamic_cast<A&>(p) << RESET << std::endl;
			break;
		case 1:
			std::cout << GREEN << dynamic_cast<B&>(p) << RESET << std::endl;
			break;
		case 2:
			std::cout << GREEN << dynamic_cast<C&>(p) << RESET << std::endl;
			break;
		default:
			std::cout << RED << "Not recognized" << RESET << std::endl;
			break;
		}
	}
	catch(const std::bad_cast& e)
	{
		identify_by_ref(p, step + 1);
	}
}

static Base*	makeA( void )
{
	return (new A());
}

static Base*	makeB( void )
{
	return (new B());
}

static Base*	makeC( void )
{
	return (new C());
}

std::ostream&	operator<<( std::ostream& stream, const A& obj ) {
	(void) obj;
	stream << "A" << std::endl;

	return (stream);
}

std::ostream&	operator<<( std::ostream& stream, const B& obj ) {
	(void) obj;
	stream << "B" << std::endl;

	return (stream);
}

std::ostream&	operator<<( std::ostream& stream, const C& obj ) {
	(void) obj;
	stream << "C" << std::endl;

	return (stream);
}
