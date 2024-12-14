/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:24 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/14 22:49:11 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
	/**
	 * Test 1: Create a bureaucrat with too high grade
	 */
	{
		try
		{
			Bureaucrat Ivan("Ivan", 0);
			std::cout << Ivan << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	/**
	 * Test 2: Create a bureaucrat with too low grade
	 */
	std::cout << "\n";
	{
		try
		{
			Bureaucrat Ivan("Ivan", 152);
			std::cout << Ivan << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	/**
	 * Test 3: Create a bureaucrat with a valid grade
	 */
	std::cout << "\n";
	{
		try
		{
			Bureaucrat Ivan("Ivan", 149);
			std::cout << Ivan << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	/**
	 * Test 4: Create a bureaucrat with a min grade then gradeDown
	 */
	std::cout << "\n";
	{
		try
		{
			Bureaucrat Mike("Mike", 149);
			Mike.gradeDown();
			std::cout << Mike << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}



}
