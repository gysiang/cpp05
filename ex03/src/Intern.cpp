/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:06 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 13:21:38 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src) {
	(void) src;
	return (*this);
}

AForm *Intern::makeForm(std::string const &type, std::string const &target) {
	AForm *n;

	n = AForm::makeForm(type, target);
	// if the form returns null throw exception
	if (!n)
		throw (AForm::FormInvalid());
	else
		std::cout << "Intern created form: " << n->getName() << " with target: " << n->getTarget() << std::endl;
	return (n);
}
