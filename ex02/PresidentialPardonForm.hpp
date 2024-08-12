/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:47:43 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/25 08:47:44 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

/**
 * @brief PresidentialPardonForm class
 *
 * This class represents a form that, when executed, grants a pardon
 * to the specified target. It requires a grade of 25 to sign and a grade of 5 to execute.
 */
class PresidentialPardonForm : public AForm {
	private:
		std::string _target; ///< The target of the pardon

	public:
		/**
		 * @brief Constructor with target parameter
		 *
		 * @param target Target of the form
		 */
		PresidentialPardonForm(const std::string &target);

		/**
		 * @brief Copy constructor
		 *
		 * @param other Another instance of PresidentialPardonForm to copy
		 */
		PresidentialPardonForm(const PresidentialPardonForm &other);

		/**
		 * @brief Assignment operator overload
		 *
		 * @param other Another instance of PresidentialPardonForm to assign from
		 * @return PresidentialPardonForm& Reference to the assigned object
		 */
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		/**
		 * @brief Destructor
		 */
		virtual ~PresidentialPardonForm();

		/**
		 * @brief Execute the form's action, which is to pardon the target
		 *
		 * @param executor Bureaucrat who executes the form
		 * @throw AForm::FormNotSignedException if the form is not signed
		 * @throw AForm::GradeTooLowException if the executor's grade is too low
		 */
		virtual void execute(const Bureaucrat &executor) const;
};

#endif
