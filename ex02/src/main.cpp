/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:24 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/05 16:12:20 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int main()
{
	/**
	 * Test 1: Create all the forms and make sure all are signed and executed.
	 */
	{
		PresidentialPardonForm a("Garden");
		ShrubberyCreationForm b("Garden");
		RobotomyRequestForm c("Garden");
		Bureaucrat mike("Mike", 5);

		try
		{
			std::cout << mike << std::endl;
			std::cout << a << std::endl;
			mike.signForm(a);
			mike.executeForm(a);
			mike.signForm(b);
			mike.executeForm(b);
			mike.signForm(c);
			mike.executeForm(c);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	/**
	 * Test 2: Execute forms without signing.
	 */
	try
	{
		PresidentialPardonForm d("Garden");
		ShrubberyCreationForm e("Garden");
		RobotomyRequestForm f("Garden");
		Bureaucrat bike("Bike", 5);

		bike.executeForm(d);
		bike.executeForm(e);
		bike.executeForm(f);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}
