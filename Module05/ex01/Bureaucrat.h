//
// Created by serj on 30.06.22.
//

#ifndef CPP_MODULES_BUREAUCRAT_H
#define CPP_MODULES_BUREAUCRAT_H

#include <iostream>
#include <cstdlib>

#include "Form.h"

class Form;

class Bureaucrat {

private:

    const std::string name;
    int grade;

public:

    Bureaucrat();
    Bureaucrat & operator = ( const Bureaucrat & );
    Bureaucrat ( const Bureaucrat & );
    ~Bureaucrat();

    Bureaucrat( std::string, int );

    std::string getName() const;
    int getGrade() const;

    void signForm( Form & );

    void incrementGrade( int );
    void decrementGrade( int );

class GradeTooHighException : public std::exception {
    public:
        const char * what () const throw();
    };
class GradeTooLowException : public std::exception {
    public:
        const char * what () const throw();
    };

};


std::ostream & operator << ( std::ostream& , const Bureaucrat& );



#endif //CPP_MODULES_BUREAUCRAT_H
