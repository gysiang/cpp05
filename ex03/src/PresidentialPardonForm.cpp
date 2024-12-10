/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:41 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 12:32:45 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
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

AForm	*PresidentialPardonForm::makeForm(AForm *form, std::string const &type, std::string const &target) {

	if (form == NULL && type == "presidential pardon") {
		return new PresidentialPardonForm(target);
	}
	return (form);
}

void PresidentialPardonForm::beExecuted(Bureaucrat const &Bureaucrat) const {
	(void) Bureaucrat;
	std::cout << "\033[1;33m" << target << " has been pardoned by Zaphod Beeblebrox.\033[0m"<< std::endl;
}

std::string const &PresidentialPardonForm::getTarget() const {
	return (target);
}

std::ostream &operator<<(std::ostream &str, PresidentialPardonForm const &form) {
	return (str << form.getName() << " form signed " << form.getN() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExeGrade());
}
