/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:29 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/27 16:44:51 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
	private:
		const std::string 	name;
		int					grade;

	public:
		// default methods
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat &src);

		// getters
		const std::string &getName(void) const;
		const int		&getGrade(void) const;

		// setters
		void	signForm(Form &a);

		// exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual char const	*what(void) const throw();
		};


};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &b);

#endif
