/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:41 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/05 12:24:37 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm::AForm("PresidentialPardonForm", PRES_SIGN, PRES_EXE), target("null") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm::AForm("PresidentialPardonForm", PRES_SIGN, PRES_EXE), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
: AForm::AForm(src), target(src.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	AForm::operator=(src);
	target = src.target;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getN())
		throw FormAlreadySigned();
	if (this->getExeGrade() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox."<< std::endl;
}
