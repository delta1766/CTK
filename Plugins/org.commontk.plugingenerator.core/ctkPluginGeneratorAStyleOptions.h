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


#ifndef CTKPLUGINGENERATORASTYLEOPTIONS_H
#define CTKPLUGINGENERATORASTYLEOPTIONS_H

#include <QString>
#include <QSharedDataPointer>

class ctkPluginGeneratorAStyleOptionsPrivate;

class ctkPluginGeneratorAStyleOptions
{

public:

  enum BracketStyle { STYLE_NONE,
                      STYLE_ALLMAN,
                      STYLE_JAVA,
                      STYLE_KR,
                      STYLE_STROUSTRUP,
                      STYLE_WHITESMITH,
                      STYLE_BANNER,
                      STYLE_GNU,
                      STYLE_LINUX,
                      STYLE_HORSTMANN,
                      STYLE_1TBS,
                      STYLE_PICO,
                      STYLE_LISP
                     };

  enum IndentType { INDENT_SPACES,
                    INDENT_TABS,
                    INDENT_FTABS
                  };

  enum PointerAlign { PTR_ALIGN_NONE,
                      PTR_ALIGN_TYPE,
                      PTR_ALIGN_MIDDLE,
                      PTR_ALIGN_NAME
                    };

  enum ReferenceAlign { REF_ALIGN_NONE = PTR_ALIGN_NONE,
                        REF_ALIGN_TYPE = PTR_ALIGN_TYPE,
                        REF_ALIGN_MIDDLE = PTR_ALIGN_MIDDLE,
                        REF_ALIGN_NAME = PTR_ALIGN_NAME,
                        REF_SAME_AS_PTR
                      };

  enum MinConditional { MINCOND_ZERO = 0,
                        MINCOND_ONE = 1,
                        MINCOND_TWO = 2,
                        MINCOND_ONEHALF = 3,
                        MINCOND_END
                      };

  enum FileMode { FILEMODE_CPP,
                  FILEMODE_JAVA,
                  FILEMODE_SHARP
                };

public:

  ctkPluginGeneratorAStyleOptions();
  ctkPluginGeneratorAStyleOptions(const ctkPluginGeneratorAStyleOptions& other);

  ~ctkPluginGeneratorAStyleOptions();

  ctkPluginGeneratorAStyleOptions& operator=(const ctkPluginGeneratorAStyleOptions& other);

  void setBracketStyle(BracketStyle bracketStyle);
  BracketStyle getBracketStyle() const;

  void setMinConditional(MinConditional minConditional);
  MinConditional getMinConditinal() const;

  // Indentation options
  void       setIndentType(IndentType indentType);
  IndentType getIndentType() const;
  void       setIndentLength(int indentLength);
  int        getIndentLength() const;
  void       setClassIndent(bool classIndent);
  bool       getClassIndent() const;
  void       setSwitchIndent(bool switchIndent);
  bool       getSwitchIndent() const;
  void       setCaseIndent(bool caseIndent);
  bool       getCaseIndent() const;
  void       setNamespaceIndent(bool namespaceIndent);
  bool       getNamespaceIndent() const;
  void       setLabelIndent(bool labelIndent);
  bool       getLabelIndent() const;
  void       setPreprocessorIndent(bool preprocessorIndent);
  bool       getPreprocessorIndent() const;
  void       setCol1CommentIndent(bool col1CommentIndent);
  bool       getCol1CommentIndent() const;
  void       setMaxInStatementIndent(int maxInStatementIndent);
  int        getMaxInStatementIndent() const;
  void       setMinConditionalOption(MinConditional minConditionalOption);
  MinConditional getMinConditionalOption() const;

  // Padding options
  void setBreakHeaderBlocks(bool breakHeaderBlocks);
  bool getBreakHeaderBlocks() const;
  void setBreakClosingBlocks(bool breakClosingBlocks);
  bool getBreakClosingBlocks() const;
  void setPadOperators(bool padOperators);
  bool getPadOperators() const;
  void setPadParensOutside(bool padParensOutside);
  bool getPadParensOutside() const;
  void setPadParensInside(bool padParensInside);
  bool getPadParensInside() const;
  void setPadHeaders(bool padHeaders);
  bool getPadHeaders() const;
  void setUnpadParens(bool unpadParens);
  bool getUnpadParens() const;
  void setDeleteEmptyLines(bool deleteEmptyLines);
  bool getDeleteEmptyLines() const;
  void setFillEmptyLines(bool fillEmptyLines);
  bool getFillEmptyLines() const;

  // Formatting options
  void setBreakCloseBrackets(bool breakCloseBrackets);
  bool getBreakCloseBrackets() const;
  void setBreakElseIfs(bool breakElseIfs);
  bool getBreakElseIfs() const;
  void setAddBrackets(bool addBrackets);
  bool getAddBrackets() const;
  void setAddOneLineBrackets(bool addOneLineBrackets);
  bool getAddOneLineBrackets() const;
  void setBreakOneLineStmts(bool breakOneLineStmts);
  bool getBreakOneLineStmts() const;
  void setBreakOneLineBlocks(bool breakOneLineBlocks);
  bool getBreakOneLineBlocks() const;
  void setConvertTabs(bool convertTabs);
  bool getConvertTabs() const;
  void setPointerAlign(PointerAlign pointerAlign);
  PointerAlign getPointerAlign() const;
  void setReferenceAlign(ReferenceAlign referenceAlign);
  ReferenceAlign getReferenceAlign() const;

  void setFileMode(FileMode fileMode);
  FileMode getFileMode() const;

  /**
   * Build a string of options from the current option variables.
   * An option is generated only if the current value is different
   * than the default value.
   * If an option variable is invalid, invalid text is sent to
   * Artistic Style so the private ErrorHandler method will be called.
   *
   * @return A string containing the options for Artistic Style.
   */
  QString toString() const;

private:

  QSharedDataPointer<ctkPluginGeneratorAStyleOptionsPrivate> d;

};

#endif // CTKPLUGINGENERATORASTYLEOPTIONS_H
