/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:24:31 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 12:22:43 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>


class Bureaucrat;

class AForm
{
	private:
		const std::string		name;
		bool					n;
		int				sign_grade;
		int				exe_grade;

	public:
		//public methods
		AForm();
		AForm(const std::string name, const int sign_grade, const int exe_grade);
		AForm(const AForm &src);
		virtual ~AForm();
		AForm &operator=(const AForm &src);

		// getters
		const std::string &getName(void) const;
		const int &getSignGrade(void) const;
		const int &getExeGrade(void) const;
		int getN(void) const;
		virtual std::string const &getTarget(void) const = 0;

		// setters
		void	beSigned(Bureaucrat &a);
		void	setSignGrade(const int a);
		void	setExeGrade(const int a);
		void	execute(const Bureaucrat &executor) const;
		virtual void beExecuted(Bureaucrat const &Bureaucrat) const = 0;
		static AForm *makeForm(const std::string &type, const std::string &target);


		// exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual char const	*what(void) const throw();
		};

		class FormAlreadySigned: public std::exception {
			public:
				virtual char const	*what(void) const throw();
		};

		class FormNotSigned: public std::exception {
			public:
				virtual char const	*what(void) const throw();
		};

		class FormInvalid: public std::exception {
			public:
				virtual char const	*what(void) const throw();
		};

};

std::ostream	&operator<<(std::ostream &str, AForm const &a);


#endif
