/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:23:29 by gyong-si          #+#    #+#             */
/*   Updated: 2024/11/29 15:50:53 by gyong-si         ###   ########.fr       */
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
		//default
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		void execute(const Bureaucrat &executor) const;

};


#endif
