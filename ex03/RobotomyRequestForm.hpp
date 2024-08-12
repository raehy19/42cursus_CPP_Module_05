/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:47:25 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/25 08:47:26 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

/**
 * @brief RobotomyRequestForm class
 *
 * This class represents a form that, when executed, attempts to robotomize
 * the specified target. It requires a grade of 72 to sign and a grade of 45 to execute.
 */
class RobotomyRequestForm : public AForm {
	private:
		std::string _target; ///< The target of the robotomy

	public:
		/**
		 * @brief Constructor with target parameter
		 *
		 * @param target Target of the form
		 */
		RobotomyRequestForm(const std::string &target);

		/**
		 * @brief Copy constructor
		 *
		 * @param other Another instance of RobotomyRequestForm to copy
		 */
		RobotomyRequestForm(const RobotomyRequestForm &other);

		/**
		 * @brief Assignment operator overload
		 *
		 * @param other Another instance of RobotomyRequestForm to assign from
		 * @return RobotomyRequestForm& Reference to the assigned object
		 */
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		/**
		 * @brief Destructor
		 */
		virtual ~RobotomyRequestForm();

		/**
		 * @brief Execute the form's action, which is to attempt to robotomize the target
		 *
		 * @param executor Bureaucrat who executes the form
		 * @throw AForm::FormNotSignedException if the form is not signed
		 * @throw AForm::GradeTooLowException if the executor's grade is too low
		 */
		virtual void execute(const Bureaucrat &executor) const;
};

#endif
