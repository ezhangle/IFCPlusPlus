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
#include "IfcSweptAreaSolid.h"
class IfcCurve;
class IfcParameterValue;
class IfcDirection;
//ENTITY
class IfcFixedReferenceSweptAreaSolid : public IfcSweptAreaSolid
{
public:
	IfcFixedReferenceSweptAreaSolid();
	IfcFixedReferenceSweptAreaSolid( int id );
	~IfcFixedReferenceSweptAreaSolid();

	// method setEntity takes over all attributes from another instance of the class
	virtual void setEntity( shared_ptr<IfcPPEntity> other );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void unlinkSelf();
	virtual const char* classname() const { return "IfcFixedReferenceSweptAreaSolid"; }


	// IfcRepresentationItem -----------------------------------------------------------
	// inverse attributes:
	//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
	//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

	// IfcGeometricRepresentationItem -----------------------------------------------------------

	// IfcSolidModel -----------------------------------------------------------

	// IfcSweptAreaSolid -----------------------------------------------------------
	// attributes:
	//  shared_ptr<IfcProfileDef>					m_SweptArea;
	//  shared_ptr<IfcAxis2Placement3D>				m_Position;					//optional

	// IfcFixedReferenceSweptAreaSolid -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcCurve>							m_Directrix;
	shared_ptr<IfcParameterValue>				m_StartParam;				//optional
	shared_ptr<IfcParameterValue>				m_EndParam;					//optional
	shared_ptr<IfcDirection>						m_FixedReference;
};

