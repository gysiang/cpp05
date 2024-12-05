/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:29:11 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/05 13:17:29 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", SHRU_SIGN, SHRU_EXE), target("null") {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", SHRU_SIGN, SHRU_EXE), target(target) {
	std::string fileName = target + "_shruberry";
	std::ofstream outFile(fileName);

	if (!outFile)
	{
		std::cerr << "Error: Could not create file " << fileName << std::endl;
		return;
	}

	outFile << asciiTree << std::endl;
	outFile.close();
	std::cout << "Shrubbery has been created in file: " << fileName << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: AForm::AForm(src), target(src.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	AForm::operator=(src);
	target = src.target;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->getN())
		throw FormAlreadySigned();
	if (this->getExeGrade() < executor.getGrade())
		throw GradeTooLowException();
}

const std::string ShrubberyCreationForm::asciiTree = R"(
          &&& &&  & &&
      && &\/&\|& ()|/ @, &&
      &\/(/&/&||/& /_/)_&/_&
   &() &\/&|()|/&\/ '%" & ()
  &_\_&&_\ |& |&&/&__%_/_& &&
&&   && & &| &| /& & % ()& /&&
 ()&_---()&\&\|&&-&&--%---()~
     &&     \|||
             |||
             |||
             |||
       , -=-~  .-^- _
)";
