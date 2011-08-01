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


// This file is based on
// http://astyle.svn.sourceforge.net/viewvc/astyle/trunk/AStyleDev/src-cx/AStyleInterface.cpp

#include "ctkPluginGeneratorAStyleInterface.h"

#include <QDebug>

ctkPluginGeneratorAStyleInterface::ctkPluginGeneratorAStyleInterface()
{
}

void ctkPluginGeneratorAStyleInterface::displayErrorMessage(const QString& errorMessage)
{
  qWarning() << errorMessage;
}

QString ctkPluginGeneratorAStyleInterface::formatSource(const QString& textIn,
                                                        const ctkPluginGeneratorAStyleOptions& options)
{
  QString optionsString = options.toString();
  // displayErrorMessage("--------------------");
  // displayErrorMessage(optionsString);
  // displayErrorMessage("--------------------");
  char* textOut = AStyleMain(textIn.toLatin1().data(),
                             optionsString.toLatin1().data(),
                             errorHandler,
                             memoryAlloc);
  QString result(textOut);
  delete textOut;
  return result;
}

void STDCALL ctkPluginGeneratorAStyleInterface::errorHandler(int errorNumber, const char* errorMessage)
{
  displayErrorMessage(QString("astyle error %1: %2").arg(errorNumber).arg(errorMessage));
}

char* STDCALL ctkPluginGeneratorAStyleInterface::memoryAlloc(unsigned long memoryNeeded)
{
  // error condition should be checked by calling procedure
  char* buffer = new(std::nothrow) char [memoryNeeded];
  return buffer;
}
