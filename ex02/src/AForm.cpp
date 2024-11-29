/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:10:56 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/29 15:54:34 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : sign_grade(150), exe_grade(150) {};

AForm::AForm(const std::string name, const int sign_grade, const int exe_grade) :
	name(name), n(0), sign_grade(sign_grade), exe_grade(exe_grade) {
	if (sign_grade < HIGHEST_GRADE || exe_grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	}
	if (sign_grade > LOWEST_GRADE || exe_grade < LOWEST_GRADE) {
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

const int &AForm::getN(void) const {
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

void	AForm::setSignGrade(const int a) {
	sign_grade = a;
}

void	AForm::setExeGrade(const int a) {
	exe_grade = a;
}

char const *AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

char const *AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

char const *AForm::FormAlreadySigned::what(void) const throw() {
	return ("Form has already been signed!");
}

std::ostream	&operator<<(std::ostream &str, AForm const &b) {
	return (str << b.getName() << ", Form sign grade " << b.getSignGrade()
	<< ", Form execute grade " << b.getExeGrade());
}
