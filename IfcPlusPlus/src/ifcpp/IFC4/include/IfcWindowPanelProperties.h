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
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPObject.h"
#include "IfcPreDefinedPropertySet.h"
class IfcWindowPanelOperationEnum;
class IfcWindowPanelPositionEnum;
class IfcPositiveLengthMeasure;
class IfcShapeAspect;
//ENTITY
class IfcWindowPanelProperties : public IfcPreDefinedPropertySet
{
public:
	IfcWindowPanelProperties();
	IfcWindowPanelProperties( int id );
	~IfcWindowPanelProperties();

	// method setEntity takes over all attributes from another instance of the class
	virtual void setEntity( shared_ptr<IfcPPEntity> other );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void unlinkSelf();
	virtual const char* classname() const { return "IfcWindowPanelProperties"; }


	// IfcRoot -----------------------------------------------------------
	// attributes:
	//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
	//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
	//  shared_ptr<IfcLabel>							m_Name;						//optional
	//  shared_ptr<IfcText>							m_Description;				//optional

	// IfcPropertyDefinition -----------------------------------------------------------
	// inverse attributes:
	//  std::vector<weak_ptr<IfcRelDeclares> >		m_HasContext_inverse;
	//  std::vector<weak_ptr<IfcRelAssociates> >		m_HasAssociations_inverse;

	// IfcPropertySetDefinition -----------------------------------------------------------
	// inverse attributes:
	//  std::vector<weak_ptr<IfcTypeObject> >		m_DefinesType_inverse;
	//  std::vector<weak_ptr<IfcRelDefinesByTemplate> >	m_IsDefinedBy_inverse;
	//  std::vector<weak_ptr<IfcRelDefinesByProperties> >	m_DefinesOccurrence_inverse;

	// IfcPreDefinedPropertySet -----------------------------------------------------------

	// IfcWindowPanelProperties -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcWindowPanelOperationEnum>		m_OperationType;
	shared_ptr<IfcWindowPanelPositionEnum>		m_PanelPosition;
	shared_ptr<IfcPositiveLengthMeasure>			m_FrameDepth;				//optional
	shared_ptr<IfcPositiveLengthMeasure>			m_FrameThickness;			//optional
	shared_ptr<IfcShapeAspect>					m_ShapeAspectStyle;			//optional
};

