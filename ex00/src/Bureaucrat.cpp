/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:22 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/26 12:50:29 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	}
	if (grade > LOWEST_GRADE) {
		throw GradeTooLowException();
	}
};

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		grade = src.grade;
	}
	return (*this);
}

const std::string &Bureaucrat::getName() const {
	return (name);
}

const int &Bureaucrat::getGrade() const {
	return (grade);
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat) {
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
