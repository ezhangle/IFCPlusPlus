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
#include "include/IfcSectionTypeEnum.h"

// TYPE IfcSectionTypeEnum 
IfcSectionTypeEnum::IfcSectionTypeEnum() {}
IfcSectionTypeEnum::~IfcSectionTypeEnum() {}
void IfcSectionTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCSECTIONTYPEENUM("; }
	if( m_enum == ENUM_UNIFORM )
	{
		stream << ".UNIFORM.";
	}
	else if( m_enum == ENUM_TAPERED )
	{
		stream << ".TAPERED.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcSectionTypeEnum> IfcSectionTypeEnum::createObjectFromStepData( const std::string& arg )
{
	// read TYPE
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSectionTypeEnum>(); }
	auto type_object = std::make_shared<IfcSectionTypeEnum>();
	if( _stricmp( arg.c_str(), ".UNIFORM." ) == 0 )
	{
		type_object->m_enum = IfcSectionTypeEnum::ENUM_UNIFORM;
	}
	else if( _stricmp( arg.c_str(), ".TAPERED." ) == 0 )
	{
		type_object->m_enum = IfcSectionTypeEnum::ENUM_TAPERED;
	}
	return type_object;
}
