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
#include "include/IfcAppliedValue.h"
#include "include/IfcConstructionProductResourceType.h"
#include "include/IfcConstructionProductResourceTypeEnum.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPhysicalQuantity.h"
#include "include/IfcPropertySetDefinition.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToResource.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcText.h"

// ENTITY IfcConstructionProductResourceType 
IfcConstructionProductResourceType::IfcConstructionProductResourceType() { m_entity_enum = IFCCONSTRUCTIONPRODUCTRESOURCETYPE; }
IfcConstructionProductResourceType::IfcConstructionProductResourceType( int id ) { m_id = id; m_entity_enum = IFCCONSTRUCTIONPRODUCTRESOURCETYPE; }
IfcConstructionProductResourceType::~IfcConstructionProductResourceType() {}

// method setEntity takes over all attributes from another instance of the class
void IfcConstructionProductResourceType::setEntity( shared_ptr<IfcPPEntity> other_entity )
{
	shared_ptr<IfcConstructionProductResourceType> other = dynamic_pointer_cast<IfcConstructionProductResourceType>(other_entity);
	if( !other) { return; }
	m_GlobalId = other->m_GlobalId;
	m_OwnerHistory = other->m_OwnerHistory;
	m_Name = other->m_Name;
	m_Description = other->m_Description;
	m_ApplicableOccurrence = other->m_ApplicableOccurrence;
	m_HasPropertySets = other->m_HasPropertySets;
	m_Identification = other->m_Identification;
	m_LongDescription = other->m_LongDescription;
	m_ResourceType = other->m_ResourceType;
	m_BaseCosts = other->m_BaseCosts;
	m_BaseQuantity = other->m_BaseQuantity;
	m_PredefinedType = other->m_PredefinedType;
}
void IfcConstructionProductResourceType::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "=IFCCONSTRUCTIONPRODUCTRESOURCETYPE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ApplicableOccurrence ) { m_ApplicableOccurrence->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_HasPropertySets );
	stream << ",";
	if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_LongDescription ) { m_LongDescription->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ResourceType ) { m_ResourceType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_BaseCosts );
	stream << ",";
	if( m_BaseQuantity ) { stream << "#" << m_BaseQuantity->getId(); } else { stream << "$"; }
	stream << ",";
	if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcConstructionProductResourceType::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcConstructionProductResourceType::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConstructionProductResourceType, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcConstructionProductResourceType, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	m_GlobalId = IfcGloballyUniqueId::createObjectFromStepData( args[0] );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromStepData( args[2] );
	m_Description = IfcText::createObjectFromStepData( args[3] );
	m_ApplicableOccurrence = IfcIdentifier::createObjectFromStepData( args[4] );
	readEntityReferenceList( args[5], m_HasPropertySets, map );
	m_Identification = IfcIdentifier::createObjectFromStepData( args[6] );
	m_LongDescription = IfcText::createObjectFromStepData( args[7] );
	m_ResourceType = IfcLabel::createObjectFromStepData( args[8] );
	readEntityReferenceList( args[9], m_BaseCosts, map );
	readEntityReference( args[10], m_BaseQuantity, map );
	m_PredefinedType = IfcConstructionProductResourceTypeEnum::createObjectFromStepData( args[11] );
}
void IfcConstructionProductResourceType::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcConstructionResourceType::setInverseCounterparts( ptr_self_entity );
}
void IfcConstructionProductResourceType::unlinkSelf()
{
	IfcConstructionResourceType::unlinkSelf();
}
