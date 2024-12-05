/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:55 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/05 16:02:48 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", ROBO_SIGN, ROBO_EXE), target("null") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", ROBO_SIGN, ROBO_EXE), target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
: AForm::AForm(src), target(src.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	AForm::operator=(src);
	target = src.target;
	return (*this);
}

void RobotomyRequestForm::beExecuted(const Bureaucrat &bureaucrat) const {
	(void) bureaucrat;
	srand(time(NULL));
	int n = rand() % 2 + 1;
	std::cout << n << std::endl;
	std::cout << "Make some drilling noises....." << std::endl;
	if (n == 1)
		std::cout << target << ": has been robotomized" << std::endl;
	else
		std::cout << target << ": robotomy has failed." << std::endl;
}
