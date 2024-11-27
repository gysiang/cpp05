/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:24 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/27 17:50:20 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
	/**
	 * Test 1: Create a form with too high grade
	 */
	{
		try
		{
			Form a("Form One", 0, 150);
			std::cout << a << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	/**
	 * Test 2: Create a form and sign it normally
	 */
	{
		try
		{
			Bureaucrat Ivan("Ivan", 140);
			Form b("Form Two", 150, 150);
			Ivan.signForm(b);
			std::cout << Ivan << std::endl;
			std::cout << b << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	/**
	 * Test 3: Create a form and but fail to sign it because of grade
	 */
	{
		try
		{
			Bureaucrat Mike("Mike", 140);
			Form b("Form Two", 100, 100);
			Mike.signForm(b);
			std::cout << b << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}


}
