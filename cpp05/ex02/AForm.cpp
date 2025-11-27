/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:36:04 by psantos-          #+#    #+#             */
/*   Updated: 2025/11/27 17:19:26 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Empty"), _sign(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Empty Form Constructed." << std::endl;
}

AForm::AForm(const std::string &name, int sign_grade, int exec_grade)
: _name(name), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade > 150 || _exec_grade > 150) throw GradeTooLowException();
	else if (_sign_grade < 1 || _exec_grade < 1) throw GradeTooHighException();
	std::cout << "Form " << _name << " Constructed." << std::endl;
}

AForm::AForm(const AForm &other)
: _name(other._name), _sign(other._sign), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	std::cout << "Form Copy Constructor Called." << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "Form Copy Assignment Operator Called." << std::endl;
	if (this != &other) _sign = other._sign;
	return *this;
}

AForm::~AForm() {std::cout << "Form " << _name << " Destroyed." << std::endl;}

const std::string	&AForm::getName() const {return _name;}
bool				AForm::getSigned() const {return _sign;}
int					AForm::getSignGrade() const {return _sign_grade;}
int					AForm::getExecGrade() const {return _exec_grade;}

void				AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _sign_grade) throw GradeTooLowException();
	_sign = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	std::string sign = (f.getSigned() == true) ? "signed" : "not signed";
	return out << "Form " << f.getName() << ", " << sign << ", grade " << f.getSignGrade() << " to sign, grade " << f.getExecGrade() << " to execute.";
}