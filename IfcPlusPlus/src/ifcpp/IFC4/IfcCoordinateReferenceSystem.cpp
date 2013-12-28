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

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcCoordinateReferenceSystem.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcText.h"

// ENTITY IfcCoordinateReferenceSystem 
IfcCoordinateReferenceSystem::IfcCoordinateReferenceSystem() { m_entity_enum = IFCCOORDINATEREFERENCESYSTEM; }
IfcCoordinateReferenceSystem::IfcCoordinateReferenceSystem( int id ) { m_id = id; m_entity_enum = IFCCOORDINATEREFERENCESYSTEM; }
IfcCoordinateReferenceSystem::~IfcCoordinateReferenceSystem() {}

// method setEntity takes over all attributes from another instance of the class
void IfcCoordinateReferenceSystem::setEntity( shared_ptr<IfcPPEntity> other_entity )
{
	shared_ptr<IfcCoordinateReferenceSystem> other = dynamic_pointer_cast<IfcCoordinateReferenceSystem>(other_entity);
	if( !other) { return; }
	m_Name = other->m_Name;
	m_Description = other->m_Description;
	m_GeodeticDatum = other->m_GeodeticDatum;
	m_VerticalDatum = other->m_VerticalDatum;
}
void IfcCoordinateReferenceSystem::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "=IFCCOORDINATEREFERENCESYSTEM" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_GeodeticDatum ) { m_GeodeticDatum->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_VerticalDatum ) { m_VerticalDatum->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcCoordinateReferenceSystem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcCoordinateReferenceSystem::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCoordinateReferenceSystem, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcCoordinateReferenceSystem, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	m_Name = IfcLabel::createObjectFromStepData( args[0] );
	m_Description = IfcText::createObjectFromStepData( args[1] );
	m_GeodeticDatum = IfcIdentifier::createObjectFromStepData( args[2] );
	m_VerticalDatum = IfcIdentifier::createObjectFromStepData( args[3] );
}
void IfcCoordinateReferenceSystem::setInverseCounterparts( shared_ptr<IfcPPEntity> )
{
}
void IfcCoordinateReferenceSystem::unlinkSelf()
{
}
