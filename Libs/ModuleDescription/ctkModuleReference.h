/*=============================================================================
  
  Library: CTK
  
  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics
    
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

#ifndef CTKMODULEREFERENCE_H
#define CTKMODULEREFERENCE_H

#include <ctkModuleDescriptionExport.h>

#include <QByteArray>
#include <QString>

class QObject;

class ctkModuleReferencePrivate;

class CTK_MODULDESC_EXPORT ctkModuleReference
{
public:

  ctkModuleReference();
  ~ctkModuleReference();

  ctkModuleReference(const ctkModuleReference& ref);
  ctkModuleReference& operator=(const ctkModuleReference& ref);

  operator bool();

  bool isValid();

  QByteArray xmlDescription() const;

  QString location() const;

  QObject* widgetTree() const;

private:

  friend class ctkModuleManager;

  ctkModuleReferencePrivate* d;

};

#endif // CTKMODULEREFERENCE_H
