/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:24 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 13:36:11 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"


int main()
{
	Intern		ivan;
	Bureaucrat	joe("Joe", 5);
	AForm		*form;

	// Test 1: Let the intern create the forms
	try
	{
		form = ivan.makeForm("robotomy request", "a");
		delete form;
		form = ivan.makeForm("presidential pardon", "b");
		delete form;
		form = ivan.makeForm("shrubbery creation", "c");
		delete form;
		// create an invalid form.
		form = ivan.makeForm("random form", "d");
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// Test 2: sign the form and execute them
	std::cout << "----------------------------" << std::endl;
	try
	{
		form = ivan.makeForm("presidential pardon", "mike");
		joe.signForm(*form);
		joe.executeForm(*form);
		delete form;

		std::cout << "----------------------------" << std::endl;
		form = ivan.makeForm("robotomy request", "nike");
		joe.signForm(*form);
		joe.executeForm(*form);
		delete form;

		std::cout << "----------------------------" << std::endl;
		form = ivan.makeForm("shrubbery creation", "kike");
		joe.signForm(*form);
		joe.executeForm(*form);
		delete form;

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
