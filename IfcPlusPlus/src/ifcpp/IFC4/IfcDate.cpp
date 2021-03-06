/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcSimpleValue.h"
#include "include/IfcDate.h"

// TYPE IfcDate 
IfcDate::IfcDate() {}
IfcDate::IfcDate( std::string value ) { m_value = value; }
IfcDate::~IfcDate() {}
void IfcDate::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCDATE("; }
	stream << "'" << encodeStepString( m_value ) << "'";
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcDate> IfcDate::createObjectFromStepData( const std::string& arg )
{
	// read TYPE
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDate>(); }
	auto type_object = std::make_shared<IfcDate>();
	type_object->readArgument( arg );
	return type_object;
}
