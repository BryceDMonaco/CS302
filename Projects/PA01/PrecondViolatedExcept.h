//PrecondViolatedExcept.h

/**
 * @file PrecondViolatedExcept.h
 *
 * @brief This is the header file for the PrecondViolatedExcept class
 * 
 * @author Bryce Monaco
 * 
 * @details Lists the various components of the PrecondViolatedExcept class
 *
 * @version 1.0
 *
 * @Note Copied from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 *		 Listing 7-5
 */

 #ifndef PRECOND_VIOLATED_EXCEPT_
 #define PRECOND_VIOLATED_EXCEPT_

 #include <stdexcept>
 #include <string>

 class PrecondViolatedExcept : public std :: logic_error
 {
 public:

	//@pre Used to throw an exception with a desired message
	//@post An exception with the desired message is thrown
	//@param message  The message to be thrown with the exception, blank by default
	//@return None

 	PrecondViolatedExcept(const std :: string& message = "");

 };

 #endif