/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:10:56 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/26 22:19:51 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form(const std::string name, const int sign_grade, const int exe_grade) :
	name(name), sign_grade(sign_grade), exe_grade(exe_grade) {};


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
