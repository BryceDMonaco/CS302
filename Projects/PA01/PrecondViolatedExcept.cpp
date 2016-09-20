//PrecondViolatedExcept.cpp

/**
 * @file PrecondViolatedExcept.cpp
 *
 * @brief This is the himplementation file for the PrecondViolatedExcept class
 * 
 * @author Bryce Monaco
 * 
 * @details Implements the various components of the PrecondViolatedExcept class
 *
 * @version 1.0
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 *		 Listing 7-6
 */

 #include "PrecondViolatedExcept.h"

 PrecondViolatedExcept :: PrecondViolatedExcept (const std :: string& message) : std :: logic_error("Precondition Violated Exception: " + message)
 {

 	
 }