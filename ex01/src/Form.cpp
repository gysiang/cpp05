/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:10:56 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/27 17:47:41 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(const std::string name, const int sign_grade, const int exe_grade) :
	name(name), n(0), sign_grade(sign_grade), exe_grade(exe_grade) {
	if (sign_grade < HIGHEST_GRADE || exe_grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	}
	if (sign_grade > LOWEST_GRADE || exe_grade < LOWEST_GRADE) {
		throw GradeTooLowException();
	}
}

// copy operator
Form::Form(const Form &src) : name(src.name), sign_grade(src.sign_grade),
exe_grade(src.exe_grade) {
	*this = src;
}

// copy assignment operator
Form &Form::operator=(const Form &src) {
	n = src.n;
	return (*this);
}

Form::~Form() {};

// getters
const std::string &Form::getName() const {
	return (name);
}

const int &Form::getSignGrade(void) const {
	return (sign_grade);
}

const int &Form::getExeGrade(void) const {
	return (exe_grade);
}

void	Form::beSigned(Bureaucrat &a) {
	if (a.getGrade() > sign_grade)
		throw GradeTooLowException();
	else
	{
		n = 1;
		std::cout << a.getName() << " successfully signed " << name << std::endl;
	}
}

char const *Form::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

char const *Form::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &str, Form const &b) {
	return (str << b.getName() << ", Form sign grade " << b.getSignGrade()
	<< ", Form execute grade " << b.getExeGrade());
}
