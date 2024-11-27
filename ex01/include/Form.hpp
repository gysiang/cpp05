/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:24:31 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/27 17:40:44 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string		name;
		bool					n;
		const int				sign_grade;
		const int				exe_grade;

	public:
		//public methods
		Form(const std::string name, const int sign_grade, const int exe_grade);
		Form(const Form &src);
		~Form();
		Form &operator=(const Form &src);

		// getters
		const std::string &getName(void) const;
		const int &getSignGrade(void) const;
		const int &getExeGrade(void) const;

		// setters
		void	beSigned(Bureaucrat &a);

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

std::ostream	&operator<<(std::ostream &str, Form const &a);


#endif
