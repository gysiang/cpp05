/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:24 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/05 15:53:27 by gyong-si         ###   ########.fr       */
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
	 * Test 1: Create a shruberry form and check if the shruberry is created
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

}
