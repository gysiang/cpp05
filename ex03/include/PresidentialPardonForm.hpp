/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:25:39 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 12:47:10 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# define PRES_SIGN 25
# define PRES_EXE 5

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		void beExecuted(const Bureaucrat &executor) const;
		static AForm *makeForm(AForm *form, std::string const &type, std::string const &target);
		std::string const &getTarget(void) const;

};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form);

#endif
