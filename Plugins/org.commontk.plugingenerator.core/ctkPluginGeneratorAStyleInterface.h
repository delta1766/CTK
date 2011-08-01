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
// http://astyle.svn.sourceforge.net/viewvc/astyle/trunk/AStyleDev/src-cx/AStyleInterface.h

#ifndef CTK_PLUGIN_GENERATOR_ASTYLE_INTERFACE_H
#define CTK_PLUGIN_GENERATOR_ASTYLE_INTERFACE_H

#include <QString>

#include "ctkPluginGeneratorAStyleOptions.h"

// allow for different calling conventions in Linux and Windows
#ifdef _WIN32
#define STDCALL __stdcall
#else
#define STDCALL
#endif

// external function calls in Artistic Style shared or static library
extern "C"
{
  char* STDCALL AStyleGetVersion();
  char* STDCALL AStyleMain(const char* textIn,
                           const char* options,
                           void(STDCALL* errorHandler)(int, const char*),
                           char*(STDCALL* memoryAlloc)(unsigned long));
}


/**
 * The ctkPluginGeneratorAStyleInterface class contains the variables and methods to call the
 * Artistic Style library to format a source file.
 */
class ctkPluginGeneratorAStyleInterface
{

public:

  ctkPluginGeneratorAStyleInterface();

  /**
   * Call the AStyleMain function in Artistic Style.
   *
   * @param  textIn The source code to be formatted.
   * @param  options The options to be passed to Artistic Style
   * @return The formatted source code from Artistic Style.
   */
  static QString formatSource(const QString& textIn, const ctkPluginGeneratorAStyleOptions& options);

private:

  /**
   * Display error messages for the class.
   * This method should be changed to display messages in a manner consistent
   * with the rest of the user program (e.g. a message box).
   *
   * @param  errorMessage The error message to be displayed.
   */
  static void displayErrorMessage(const QString& errorMessage);

  // callback functions for Artistic Style

  /**
   * Static method to handle error messages from messages from Artistic Style.
   * This method is called only if there are errors when AStyleMain is called.
   * This is for debugging and there should be no errors when the calling
   * parameters are correct.
   *
   * @param  errorNumber   The error number from Artistic Style.
   * @param  errorMessage  The error message from Artistic Style.
   */
  static void STDCALL errorHandler(int errorNumber, const char* errorMessage);

  /**
   * Allocate memory for the Artistic Style formatter.
   * This method is called when Artistic Style needs to allocate memory.
   * for the formatted file.
   * The calling program is responsible for freeing the memory.
   *
   * @param  memoryNeeded  The amount of memory needed by Artistic Style.
   */
  static char* STDCALL memoryAlloc(unsigned long memoryNeeded);

};

#endif // CTK_PLUGIN_GENERATOR_ASTYLE_INTERFACE_H
