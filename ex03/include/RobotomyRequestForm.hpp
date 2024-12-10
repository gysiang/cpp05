/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:24:21 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 12:47:15 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

# define ROBO_SIGN 72
# define ROBO_EXE 45

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;

	public:
		//default methods
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		// public methods
		void beExecuted(const Bureaucrat &executor) const;
		static AForm *makeForm(AForm *form, std::string const &type, std::string const &target);

		std::string const &getTarget() const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);


#endif
