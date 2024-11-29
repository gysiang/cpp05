/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:28:41 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/29 12:02:37 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm::AForm("PresidentialPardonForm", PRES_SIGN, PRES_EXE), target("null") {}

PresidentialPardonForm::PresidentialPardonForm()
: AForm::AForm("PresidentialPardonForm", PRES_SIGN, PRES_EXE), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
: AForm::AForm(src), target(src.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	AForm::operator=(src);
	target = src.target;
	return (*this);
}
