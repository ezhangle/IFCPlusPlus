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
#include "include/IfcDirectionSenseEnum.h"

// TYPE IfcDirectionSenseEnum 
IfcDirectionSenseEnum::IfcDirectionSenseEnum() {}
IfcDirectionSenseEnum::~IfcDirectionSenseEnum() {}
void IfcDirectionSenseEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCDIRECTIONSENSEENUM("; }
	if( m_enum == ENUM_POSITIVE )
	{
		stream << ".POSITIVE.";
	}
	else if( m_enum == ENUM_NEGATIVE )
	{
		stream << ".NEGATIVE.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcDirectionSenseEnum> IfcDirectionSenseEnum::createObjectFromStepData( const std::string& arg )
{
	// read TYPE
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDirectionSenseEnum>(); }
	auto type_object = std::make_shared<IfcDirectionSenseEnum>();
	if( _stricmp( arg.c_str(), ".POSITIVE." ) == 0 )
	{
		type_object->m_enum = IfcDirectionSenseEnum::ENUM_POSITIVE;
	}
	else if( _stricmp( arg.c_str(), ".NEGATIVE." ) == 0 )
	{
		type_object->m_enum = IfcDirectionSenseEnum::ENUM_NEGATIVE;
	}
	return type_object;
}
