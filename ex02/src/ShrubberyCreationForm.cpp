/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:29:11 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/28 16:26:52 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), target("null") {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), target(target) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {}
