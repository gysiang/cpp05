/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:24 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/26 15:19:08 by gyong-si         ###   ########.fr       */
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
			Bureaucrat Ivan("Ivan", -2);
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



}
