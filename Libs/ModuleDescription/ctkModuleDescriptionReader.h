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

#ifndef __ctkSlicerModuleReader_h
#define __ctkSlicerModuleReader_h

// Qt includes
#include <QRegExp>
#include <QStack>
#include <QXmlAttributes>
#include <QXmlDefaultHandler>

// CTK includes
#include <ctkModuleDescriptionExport.h>

/**
 * Reader of default module XML description
 * Freely inspired from 
 * Slicer/Libs/SlicerExecutionModel/ModuleDescriptionParser/ModuleDescriptionParser.cxx
 */
class CTK_MODULDESC_EXPORT ctkModuleDescriptionParser
{

public:

  void setInput(QIODevice* input);

  void parseDescription();

  ctkModuleDescription* moduleDescription() const;

protected:

  virtual bool validate() const;
};

#endif
