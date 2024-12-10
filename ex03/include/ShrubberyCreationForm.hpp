/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:23:29 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 12:47:22 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRY_CREATION_FORM_HPP
# define SHRUBERRY_CREATION_FORM_HPP

# include "AForm.hpp"

# define SHRU_SIGN 145
# define SHRU_EXE 137

# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;

	public:
		//default methods
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		// public methods
		void beExecuted(const Bureaucrat &bureaucrat) const;
		static const std::string asciiTree;
		static AForm *makeForm(AForm *form, std::string const &type, std::string const &target);
		std::string const &getTarget() const;
};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form);


#endif
