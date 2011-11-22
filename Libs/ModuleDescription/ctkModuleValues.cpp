/*=============================================================================

Library: CTK

Copyright (c) 2010 Brigham and Women's Hospital (BWH) All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

=============================================================================*/

#include "ctkModuleValues.h"
#include "ctkModuleParameterGroup.h"

#include <iostream>

#include <QFile>
#include <QTextStream>

//----------------------------------------------------------------------------
const QVector<ctkModuleParameterGroupValue*>& ctkModuleValues::valueGroups() const
{
  return this->ValueGroups;
}

//----------------------------------------------------------------------------
ctkModuleParameterGroupValue* ctkModuleValues::valueGroup(const QString& parameterName)const
{
  // iterate over each parameter group
  foreach( ctkModuleParameterGroupValue* group, this->ValueGroups)
    {
    ctkModuleParameterValue* value = group->value(parameterName);
    if (value)
      {
      return group;
      }    
    }
  return 0;
}

//----------------------------------------------------------------------------
ctkModuleParameterValue* ctkModuleValues::value(const QString& parameterName)const
{
  // iterate over each parameter group
  foreach( const ctkModuleParameterGroupValue* group, this->ValueGroups)
    {
    ctkModuleParameterValue* value = group->value(parameterName);
    if (value)
      {
      return value;
      }    
    }
  return 0;
}
