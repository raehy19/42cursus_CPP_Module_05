/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:58:27 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/09 01:58:28 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		// Orthodox Canonical Form
		Form();

		Form(const Form &other);

		Form &operator=(const Form &other);

		~Form();

		// Constructor
		Form(const std::string &name, int gradeToSign, int gradeToExecute);

		// Getters
		const std::string &getName() const;

		bool getIsSigned() const;

		int getGradeToSign() const;

		int getGradeToExecute() const;

		// Member functions
		void beSigned(const Bureaucrat &bureaucrat);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif