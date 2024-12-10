/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:10:56 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 12:16:58 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

AForm::AForm() : sign_grade(150), exe_grade(150) {};

AForm::AForm(const std::string name, const int sign_grade, const int exe_grade) :
	name(name), n(0), sign_grade(sign_grade), exe_grade(exe_grade) {
	if (sign_grade < HIGHEST_GRADE || exe_grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	}
	if (sign_grade > LOWEST_GRADE || exe_grade > LOWEST_GRADE) {
		throw GradeTooLowException();
	}
}

// copy operator
AForm::AForm(const AForm &src) : name(src.name), sign_grade(src.sign_grade),
exe_grade(src.exe_grade) {
	*this = src;
}

// copy assignment operator
AForm &AForm::operator=(const AForm &src) {
	n = src.n;
	return (*this);
}

AForm::~AForm() {};

// getters
const std::string &AForm::getName() const {
	return (name);
}

const int &AForm::getSignGrade(void) const {
	return (sign_grade);
}

const int &AForm::getExeGrade(void) const {
	return (exe_grade);
}

int AForm::getN(void) const {
	return (n);
}

void	AForm::beSigned(Bureaucrat &a) {
	if (a.getGrade() > sign_grade)
		throw GradeTooLowException();
	else
	{
		n = 1;
		std::cout << a.getName() << " successfully signed " << name << std::endl;
	}
}

void	AForm::execute(const Bureaucrat &executor) const {
	if (!this->getN())
		throw FormNotSigned();
	else if (this->exe_grade < executor.getGrade())
		throw GradeTooLowException();
	else
	{
		this->beExecuted(executor);
		std::cout << executor.getName() << " executes form: " << this->getName() << std::endl;
	}
}


void	AForm::setSignGrade(const int a) {
	sign_grade = a;
}

void	AForm::setExeGrade(const int a) {
	exe_grade = a;
}

AForm	*AForm::makeForm(const std::string &type, const std::string &target) {
	AForm *n;

	n = NULL;
	n = ShrubberyCreationForm::makeForm(n, type, target);
	n = PresidentialPardonForm::makeForm(n, type, target);
	n = RobotomyRequestForm::makeForm(n, type, target);
	return (n);
}

char const *AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

char const *AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

char const *AForm::FormNotSigned::what(void) const throw() {
	return ("Form has not been signed!");
}

char const *AForm::FormAlreadySigned::what(void) const throw() {
	return ("Form has already been signed!");
}

char const *AForm::FormInvalid::what(void) const throw() {
	return ("Invalid Form.");
}

std::ostream	&operator<<(std::ostream &str, AForm const &b) {
	return (str << b.getName() << ", Form sign grade " << b.getSignGrade()
	<< ", Form execute grade " << b.getExeGrade());
}
