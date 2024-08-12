/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:48:11 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/12 14:48:12 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/**
 * @brief Intern class
 *
 * The Intern class is responsible for creating forms based on a given name and target.
 * It contains a makeForm method that generates different types of forms.
 */
class Intern {
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		/**
		 * @brief Creates a form based on the given form name and target
		 *
		 * @param formName The name of the form to create
		 * @param target The target of the form
		 * @return A pointer to the created form, or nullptr if the form name is invalid
		 */
		AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
