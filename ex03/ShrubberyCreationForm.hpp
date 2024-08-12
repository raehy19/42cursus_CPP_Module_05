/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:21:11 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/25 08:21:17 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

/**
 * @brief ShrubberyCreationForm class
 *
 * This class represents a form that, when executed, creates a file containing
 * ASCII art of a tree. It requires a grade of 145 to sign and a grade of 137 to execute.
 */
class ShrubberyCreationForm : public AForm {
	private:
		std::string _target; ///< The target location where the shrubbery file will be created

	public:
		/**
		 * @brief Constructor with target parameter
		 *
		 * @param target Target of the form
		 */
		ShrubberyCreationForm(const std::string &target);

		/**
		 * @brief Copy constructor
		 *
		 * @param other Another instance of ShrubberyCreationForm to copy
		 */
		ShrubberyCreationForm(const ShrubberyCreationForm &other);

		/**
		 * @brief Assignment operator overload
		 *
		 * @param other Another instance of ShrubberyCreationForm to assign from
		 * @return ShrubberyCreationForm& Reference to the assigned object
		 */
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		/**
		 * @brief Destructor
		 */
		virtual ~ShrubberyCreationForm();

		/**
		 * @brief Execute the form's action, which is to create a shrubbery file
		 *
		 * @param executor Bureaucrat who executes the form
		 * @throw AForm::FormNotSignedException if the form is not signed
		 * @throw AForm::GradeTooLowException if the executor's grade is too low
		 */
		virtual void execute(const Bureaucrat &executor) const;
};

#endif
