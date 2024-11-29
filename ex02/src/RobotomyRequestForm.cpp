/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:55 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/29 15:55:49 by gyong-si         ###   ########.fr       */
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

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->getN())
		throw FormAlreadySigned();
	if (this->getExeGrade() < executor.getGrade())
		throw GradeTooLowException();
	int n = rand() % 2 + 1;
	std::cout << "Make some drilling noises....." << std::endl;
	if (n == 1)
		std::cout << target << ": has been robotomized" << std::endl;
	else
		std::cout << target << ": robotomy has failed." << std::endl;
}
