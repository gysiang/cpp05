/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:22 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/05 12:00:51 by gyong-si         ###   ########.fr       */
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

// copy assignment operator
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

void	Bureaucrat::signForm(AForm &form) {
	try
	{
		form.beSigned(*this);
		std::cout << name << " signs " << form.getName() << " successfully." << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << name << " cannot sign " << form.getName() << " because of " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {

	try
	{
		form.execute(*this);
		std::cout << name << " executes " << form.getName() << " successfully." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " cannot execute " << form.getName() << " because of " << e.what() << std::endl;
	}
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &b) {
	return (str << b.getName() << ", bureaucrat grade " << b.getGrade());
}
