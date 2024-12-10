/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:09 by gyong-si          #+#    #+#             */
/*   Updated: 2024/12/10 11:53:07 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "../include/AForm.hpp"

class Intern
{
	public:
		//default methods
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);
		AForm *makeForm(const std::string &type, const std::string &target);

};

#endif
