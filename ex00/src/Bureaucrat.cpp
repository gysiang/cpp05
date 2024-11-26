/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:22 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/26 11:01:55 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat : " << name << " with grade " << grade
	<< " is created." << std::endl;
};


Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat : " << this->getName() << " with grade " << this->getGrade()
	<< " is destroyed." << std::endl;
}
