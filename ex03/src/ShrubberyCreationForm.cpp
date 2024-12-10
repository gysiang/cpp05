/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:29:11 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 12:33:26 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", SHRU_SIGN, SHRU_EXE), target("null") {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", SHRU_SIGN, SHRU_EXE), target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: AForm::AForm(src), target(src.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	AForm::operator=(src);
	target = src.target;
	return (*this);
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &bureaucrat) const {
	std::string fileName = target + "_shrubberry";
	std::ofstream outFile(fileName.c_str());

	if (!outFile)
	{
		std::cerr << "Error: Could not create file " << fileName << std::endl;
		return;
	}

	outFile << asciiTree << std::endl;
	outFile.close();
	std::cout << bureaucrat.getName() << " successfully created a shrubbery" << std::endl;
}

AForm	*ShrubberyCreationForm::makeForm(AForm *form, std::string const &type, std::string const &target) {

	if (form == NULL && type == "shrubbery creation") {
		return new ShrubberyCreationForm(target);
	}
	return (form);
}

std::string const &ShrubberyCreationForm::getTarget() const {
	return (target);
}

const std::string ShrubberyCreationForm::asciiTree =
"          &&& &&  & &&\n"
"      && &/&||& ()|/ @, &&\n"
"      &/(/&/&||/& /_/)_&/_&\n"
"   &() &/&|()|/&/ '% & ()\n"
"  &_|_&&_|_|& |&&/&__%_/_& &&\n"
"&&   && & &| &| /& & % ()& /&&\n"
" ()&_---()&_|||&&-&&--%---()~\n"
"     &&      |||\n"
"             |||\n"
"             |||\n"
"             |||\n"
"       , -=-~  .-^- _\n";

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form) {
	return (str << form.getName() << " form signed " << form.getN() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExeGrade());
}
