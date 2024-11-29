/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:55 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/29 11:15:43 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", ROBO_SIGN, ROBO_EXE), target("null") {}

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", ROBO_SIGN, ROBO_EXE), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
: AForm::AForm(src), target(src.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	AForm::operator=(src);
	target = src.target;
	return (*this);
}
