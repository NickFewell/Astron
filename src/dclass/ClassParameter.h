// Filename: ClassParameter.h
// Created by: drose (18 Jun, 2004)
//
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//

#pragma once
#include "dcbase.h"
#include "Parameter.h"
namespace dclass   // open namespace
{

// Forward declaration of class
class Class;

// A ClassParameter represents a class (or struct) object used as a parameter itself.
//     This means that all the fields of the class get packed into the message.
class ClassParameter : public Parameter
{
	public:
		ClassParameter(const Class *dclass); // construct from class definition
		ClassParameter(const ClassParameter &copy); // copy constructor

		// as_class_parameter returns the same parameter pointer converted to a class parameter
		//     pointer, if this is in fact an class parameter; otherwise, returns NULL.
		virtual ClassParameter *as_class_parameter();
		virtual const ClassParameter *as_class_parameter() const;

		// make_copy returns a deep copy of this parameter
		virtual Parameter *make_copy() const;

		// is_valid returns false if the element type is an invalid type
		//     (e.g. declared from an undefined typedef), or true if it is valid.
		virtual bool is_valid() const;

		// get_class returns the class that this parameter represents
		const Class *get_class() const;

		// output_instance formats the parameter to the syntax of an class parameter in a .dc file
		//     as CLASS_IDENTIFIER PARAM_IDENTIFIER with optional PARAM_IDENTIFIER,
		//     and outputs the formatted string to the stream.
		virtual void output_instance(std::ostream &out, bool brief, const std::string &prename,
		                             const std::string &name, const std::string &postname) const;

		// generate_hash accumulates the properties of this type into the hash.
		virtual void generate_hash(HashGenerator &hashgen) const;

	private:
		const Class *m_class; // class type of parameter
};


} // close namespace dclass
