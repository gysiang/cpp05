/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:41 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/05 16:05:50 by gyong-si         ###   ########.fr       */
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

void PresidentialPardonForm::beExecuted(Bureaucrat const &Bureaucrat) const {
	(void) Bureaucrat;
	std::cout << "\033[1;33m" << target << " has been pardoned by Zaphod Beeblebrox.\033[0m"<< std::endl;
}
