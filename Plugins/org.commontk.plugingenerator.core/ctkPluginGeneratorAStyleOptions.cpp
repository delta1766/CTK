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


#include "ctkPluginGeneratorAStyleOptions.h"

class ctkPluginGeneratorAStyleOptionsPrivate : public QSharedData
{
public:

  ctkPluginGeneratorAStyleOptionsPrivate()
  {
    // bracket style options
    bracketStyle = ctkPluginGeneratorAStyleOptions::STYLE_NONE;

    // tabs/spaces options
    indentLength = 4;
    indentType   = ctkPluginGeneratorAStyleOptions::INDENT_SPACES;

    // indentation options
    classIndent        = false;
    switchIndent       = false;
    caseIndent         = false;
    namespaceIndent    = false;
    labelIndent        = false;
    preprocessorIndent = false;
    col1CommentIndent  = false;
    maxInStatementIndent = 40;
    minConditionalOption = ctkPluginGeneratorAStyleOptions::MINCOND_TWO;

    // padding options
    breakHeaderBlocks  = false;
    breakClosingBlocks = false;
    padOperators       = false;
    padParensOutside   = false;
    padParensInside    = false;
    padHeaders         = false;
    unpadParens        = false;
    deleteEmptyLines   = false;
    fillEmptyLines     = false;

    // formatting options
    breakCloseBrackets = false;
    breakElseIfs       = false;
    addBrackets        = false;
    addOneLineBrackets = false;
    breakOneLineStmts  = true;
    breakOneLineBlocks = true;
    convertTabs        = false;
    alignPointers      = ctkPluginGeneratorAStyleOptions::PTR_ALIGN_NONE;
    alignReferences     = ctkPluginGeneratorAStyleOptions::REF_ALIGN_NONE;

    // file mode option
    fileMode = ctkPluginGeneratorAStyleOptions::FILEMODE_CPP;

    // save integer default values
    defaultIndentLength         = indentLength;
    defaultMaxInStatementIndent = maxInStatementIndent;
    defaultMinConditionalOption = minConditionalOption;
  }

  // option variable names are ALMOST the same as Artistic Style
  // the initial value is the default value in Artistic Style
  // comments are the command line option used to set the variable

  // bracket style option
  ctkPluginGeneratorAStyleOptions::BracketStyle bracketStyle; // --style=?

  // tabs/spaces options
  int indentLength;                                       // --indent=? --indent=force-tab=#
  ctkPluginGeneratorAStyleOptions::IndentType indentType; // --indent=? --indent=force-tab=#

  // indentation options
  bool classIndent;                   // --indent-classes
  bool switchIndent;                  // --indent-switches
  bool caseIndent;                    // --indent-cases
  bool namespaceIndent;               // --indent-namespaces
  bool labelIndent;                   // --indent-labels
  bool preprocessorIndent;            // --indent-preprocessor
  bool col1CommentIndent;             // --indent-col1-comments
  int  maxInStatementIndent;          // --max-instatement-indent=#
  ctkPluginGeneratorAStyleOptions::MinConditional  minConditionalOption;          // --min-conditional-indent=#

  // padding options
  bool breakHeaderBlocks;             // --break-blocks, --break-blocks=all
  bool breakClosingBlocks;            // --break-blocks=all
  bool padOperators;                  // --pad-oper
  bool padParensOutside;              // --pad-paren, --pad-paren-out
  bool padParensInside;               // --pad-paren, --pad-paren-in
  bool padHeaders;                    // --pad-header
  bool unpadParens;                   // --unpad-paren
  bool deleteEmptyLines;              // --delete-empty-lines
  bool fillEmptyLines;                // --fill-empty-lines

  // formatting options
  bool breakCloseBrackets;            // --break-closing-brackets
  bool breakElseIfs;                  // --break-elseifs
  bool addBrackets;                   // --add-brackets
  bool addOneLineBrackets;            // --add-one-line-brackets
  bool breakOneLineStmts;             // --keep-one-line-statements
  bool breakOneLineBlocks;            // --keep-one-line-blocks
  bool convertTabs;                   // --convert-tabs
  ctkPluginGeneratorAStyleOptions::PointerAlign alignPointers;     // --align-pointer= none, type, middle, name
  ctkPluginGeneratorAStyleOptions::ReferenceAlign alignReferences; // --align-reference= none, type, middle, name

  // file mode option
  ctkPluginGeneratorAStyleOptions::FileMode fileMode; // --mode=?

  // default values for integer variables, saved by constructor
  int defaultIndentLength;            // default indentLength
  int defaultMaxInStatementIndent;    // default maxInStatementIndent
  int defaultMinConditionalOption;    // default minConditionalIndent
};

ctkPluginGeneratorAStyleOptions::ctkPluginGeneratorAStyleOptions()
  : d(new ctkPluginGeneratorAStyleOptionsPrivate())
{
}

ctkPluginGeneratorAStyleOptions::ctkPluginGeneratorAStyleOptions(const ctkPluginGeneratorAStyleOptions& other)
  : d(other.d)
{

}

ctkPluginGeneratorAStyleOptions::~ctkPluginGeneratorAStyleOptions()
{

}

ctkPluginGeneratorAStyleOptions& ctkPluginGeneratorAStyleOptions::operator=(const ctkPluginGeneratorAStyleOptions& other)
{
  d = other.d;
  return *this;
}

void ctkPluginGeneratorAStyleOptions::setBracketStyle(BracketStyle bracketStyle)
{
  d->bracketStyle = bracketStyle;
}

ctkPluginGeneratorAStyleOptions::BracketStyle ctkPluginGeneratorAStyleOptions::getBracketStyle() const
{
  return d->bracketStyle;
}

void ctkPluginGeneratorAStyleOptions::setMinConditional(MinConditional minConditional)
{
  d->minConditionalOption = minConditional;
}

ctkPluginGeneratorAStyleOptions::MinConditional ctkPluginGeneratorAStyleOptions::getMinConditinal() const
{
  return d->minConditionalOption;
}

void ctkPluginGeneratorAStyleOptions::setIndentType(IndentType indentType)
{
  d->indentType = indentType;
}

ctkPluginGeneratorAStyleOptions::IndentType ctkPluginGeneratorAStyleOptions::getIndentType() const
{
  return d->indentType;
}

void ctkPluginGeneratorAStyleOptions::setIndentLength(int indentLength)
{
  d->indentLength = indentLength;
}

int ctkPluginGeneratorAStyleOptions::getIndentLength() const
{
  return d->indentLength;
}

void ctkPluginGeneratorAStyleOptions::setClassIndent(bool classIndent)
{
  d->classIndent = classIndent;
}

bool ctkPluginGeneratorAStyleOptions::getClassIndent() const
{
  return d->classIndent;
}

void ctkPluginGeneratorAStyleOptions::setSwitchIndent(bool switchIndent)
{
  d->switchIndent = switchIndent;
}

bool ctkPluginGeneratorAStyleOptions::getSwitchIndent() const
{
  return d->switchIndent;
}

void ctkPluginGeneratorAStyleOptions::setCaseIndent(bool caseIndent)
{
  d->caseIndent = caseIndent;
}

bool ctkPluginGeneratorAStyleOptions::getCaseIndent() const
{
  return d->caseIndent;
}

void ctkPluginGeneratorAStyleOptions::setNamespaceIndent(bool namespaceIndent)
{
  d->namespaceIndent = namespaceIndent;
}

bool ctkPluginGeneratorAStyleOptions::getNamespaceIndent() const
{
  return d->namespaceIndent;
}

void ctkPluginGeneratorAStyleOptions::setLabelIndent(bool labelIndent)
{
  d->labelIndent = labelIndent;
}

bool ctkPluginGeneratorAStyleOptions::getLabelIndent() const
{
  return d->labelIndent;
}

void ctkPluginGeneratorAStyleOptions::setPreprocessorIndent(bool preprocessorIndent)
{
  d->preprocessorIndent = preprocessorIndent;
}

bool ctkPluginGeneratorAStyleOptions::getPreprocessorIndent() const
{
  return d->preprocessorIndent;
}

void ctkPluginGeneratorAStyleOptions::setCol1CommentIndent(bool col1CommentIndent)
{
  d->col1CommentIndent = col1CommentIndent;
}

bool ctkPluginGeneratorAStyleOptions::getCol1CommentIndent() const
{
  return d->col1CommentIndent;
}

void ctkPluginGeneratorAStyleOptions::setMaxInStatementIndent(int maxInStatementIndent)
{
  d->maxInStatementIndent = maxInStatementIndent;
}

int ctkPluginGeneratorAStyleOptions::getMaxInStatementIndent() const
{
  return d->maxInStatementIndent;
}

void ctkPluginGeneratorAStyleOptions::setMinConditionalOption(MinConditional minConditionalOption)
{
  d->minConditionalOption = minConditionalOption;
}

ctkPluginGeneratorAStyleOptions::MinConditional ctkPluginGeneratorAStyleOptions::getMinConditionalOption() const
{
  return d->minConditionalOption;
}

void ctkPluginGeneratorAStyleOptions::setBreakHeaderBlocks(bool breakHeaderBlocks)
{
  d->breakHeaderBlocks = breakHeaderBlocks;
}

bool ctkPluginGeneratorAStyleOptions::getBreakHeaderBlocks() const
{
  return d->breakHeaderBlocks;
}

void ctkPluginGeneratorAStyleOptions::setBreakClosingBlocks(bool breakClosingBlocks)
{
  d->breakClosingBlocks = breakClosingBlocks;
}

bool ctkPluginGeneratorAStyleOptions::getBreakClosingBlocks() const
{
  return d->breakClosingBlocks;
}

void ctkPluginGeneratorAStyleOptions::setPadOperators(bool padOperators)
{
  d->padOperators = padOperators;
}

bool ctkPluginGeneratorAStyleOptions::getPadOperators() const
{
  return d->padOperators;
}

void ctkPluginGeneratorAStyleOptions::setPadParensOutside(bool padParensOutside)
{
  d->padParensOutside = padParensOutside;
}

bool ctkPluginGeneratorAStyleOptions::getPadParensOutside() const
{
  return d->padParensOutside;
}

void ctkPluginGeneratorAStyleOptions::setPadParensInside(bool padParensInside)
{
  d->padParensInside = padParensInside;
}

bool ctkPluginGeneratorAStyleOptions::getPadParensInside() const
{
  return d->padParensInside;
}

void ctkPluginGeneratorAStyleOptions::setPadHeaders(bool padHeaders)
{
  d->padHeaders = padHeaders;
}

bool ctkPluginGeneratorAStyleOptions::getPadHeaders() const
{
  return d->padHeaders;
}

void ctkPluginGeneratorAStyleOptions::setUnpadParens(bool unpadParens)
{
  d->unpadParens = unpadParens;
}

bool ctkPluginGeneratorAStyleOptions::getUnpadParens() const
{
  return d->unpadParens;
}

void ctkPluginGeneratorAStyleOptions::setDeleteEmptyLines(bool deleteEmptyLines)
{
  d->deleteEmptyLines = deleteEmptyLines;
}

bool ctkPluginGeneratorAStyleOptions::getDeleteEmptyLines() const
{
  return d->deleteEmptyLines;
}

void ctkPluginGeneratorAStyleOptions::setFillEmptyLines(bool fillEmptyLines)
{
  d->fillEmptyLines = fillEmptyLines;
}

bool ctkPluginGeneratorAStyleOptions::getFillEmptyLines() const
{
  return d->fillEmptyLines;
}

void ctkPluginGeneratorAStyleOptions::setBreakCloseBrackets(bool breakCloseBrackets)
{
  d->breakCloseBrackets = breakCloseBrackets;
}

bool ctkPluginGeneratorAStyleOptions::getBreakCloseBrackets() const
{
  return d->breakCloseBrackets;
}

void ctkPluginGeneratorAStyleOptions::setBreakElseIfs(bool breakElseIfs)
{
  d->breakElseIfs = breakElseIfs;
}

bool ctkPluginGeneratorAStyleOptions::getBreakElseIfs() const
{
  return d->breakElseIfs;
}

void ctkPluginGeneratorAStyleOptions::setAddBrackets(bool addBrackets)
{
  d->addBrackets = addBrackets;
}

bool ctkPluginGeneratorAStyleOptions::getAddBrackets() const
{
  return d->addBrackets;
}

void ctkPluginGeneratorAStyleOptions::setAddOneLineBrackets(bool addOneLineBrackets)
{
  d->addOneLineBrackets = addOneLineBrackets;
}

bool ctkPluginGeneratorAStyleOptions::getAddOneLineBrackets() const
{
  return d->addOneLineBrackets;
}

void ctkPluginGeneratorAStyleOptions::setBreakOneLineStmts(bool breakOneLineStmts)
{
  d->breakOneLineStmts = breakOneLineStmts;
}

bool ctkPluginGeneratorAStyleOptions::getBreakOneLineStmts() const
{
  return d->breakOneLineStmts;
}

void ctkPluginGeneratorAStyleOptions::setBreakOneLineBlocks(bool breakOneLineBlocks)
{
  d->breakOneLineBlocks = breakOneLineBlocks;
}

bool ctkPluginGeneratorAStyleOptions::getBreakOneLineBlocks() const
{
  return d->breakOneLineBlocks;
}

void ctkPluginGeneratorAStyleOptions::setConvertTabs(bool convertTabs)
{
  d->convertTabs = convertTabs;
}

bool ctkPluginGeneratorAStyleOptions::getConvertTabs() const
{
  return d->convertTabs;
}

void ctkPluginGeneratorAStyleOptions::setPointerAlign(PointerAlign pointerAlign)
{
  d->alignPointers = pointerAlign;
}

ctkPluginGeneratorAStyleOptions::PointerAlign ctkPluginGeneratorAStyleOptions::getPointerAlign() const
{
  return d->alignPointers;
}

void ctkPluginGeneratorAStyleOptions::setReferenceAlign(ReferenceAlign referenceAlign)
{
  d->alignReferences = referenceAlign;
}

ctkPluginGeneratorAStyleOptions::ReferenceAlign ctkPluginGeneratorAStyleOptions::getReferenceAlign() const
{
  return d->alignReferences;
}

void ctkPluginGeneratorAStyleOptions::setFileMode(FileMode fileMode)
{
  d->fileMode = fileMode;
}

ctkPluginGeneratorAStyleOptions::FileMode ctkPluginGeneratorAStyleOptions::getFileMode() const
{
  return d->fileMode;
}

QString ctkPluginGeneratorAStyleOptions::toString() const
{
  QString options;       // options to Artistic Style
  options.reserve(100);
  QChar separator('\n'); // can be new-line, tab, space, or comma

  if (d->bracketStyle != STYLE_NONE)
  {
    if (d->bracketStyle == STYLE_ALLMAN)
      options.append("style=allman");
    else if (d->bracketStyle == STYLE_JAVA)
      options.append("style=java");
    else if (d->bracketStyle == STYLE_KR)
      options.append("style=k&r");
    else if (d->bracketStyle == STYLE_STROUSTRUP)
      options.append("style=stroustrup");
    else if (d->bracketStyle == STYLE_WHITESMITH)
      options.append("style=whitesmith");
    else if (d->bracketStyle == STYLE_BANNER)
      options.append("style=banner");
    else if (d->bracketStyle == STYLE_GNU)
      options.append("style=gnu");
    else if (d->bracketStyle == STYLE_LINUX)
      options.append("style=linux");
    else if (d->bracketStyle == STYLE_HORSTMANN)
      options.append("style=horstmann");
    else if (d->bracketStyle == STYLE_1TBS)
      options.append("style=1tbs");
    else if (d->bracketStyle == STYLE_PICO)
      options.append("style=pico");
    else
      // force an error message
      options.append("invalid-bracketStyle=").append(
            QString::number(static_cast<uint>(d->bracketStyle)));
    options.append(separator);
  }

  // begin indent check
  if (d->indentType == INDENT_SPACES) // space is the default
  {
    if (d->indentLength != d->defaultIndentLength)
    {
      options.append("indent=spaces=").append(QString::number(d->indentLength));
      options.append(separator);
    }
  }
  else if (d->indentType == INDENT_TABS) // tab is not the default
  {
    // check conditions to use default tab setting
    if (d->indentLength == d->defaultIndentLength)
      options.append("indent=tab");
    else
      options.append("indent=tab=").append(QString::number(d->indentLength));
    options.append(separator);
  }
  else if (d->indentType == INDENT_FTABS)
  {
    options.append("indent=force-tab=").append(QString::number(d->indentLength));
    options.append(separator);
  }
  else
  {
    // force an error message
    options.append("invalid-indentType=").append(QString::number(static_cast<uint>(d->indentType)));
    options.append(separator);
  }
  // end indent check

  if (d->classIndent)
  {
    options.append("indent-classes");
    options.append(separator);
  }
  if (d->switchIndent)
  {
    options.append("indent-switches");
    options.append(separator);
  }
  if (d->caseIndent)
  {
    options.append("indent-cases");
    options.append(separator);
  }
  if (d->namespaceIndent)
  {
    options.append("indent-namespaces");
    options.append(separator);
  }
  if (d->labelIndent)
  {
    options.append("indent-labels");
    options.append(separator);
  }
  if (d->preprocessorIndent)
  {
    options.append("indent-preprocessor");
    options.append(separator);
  }
  if (d->maxInStatementIndent != d->defaultMaxInStatementIndent)
  {
    options.append("max-instatement-indent=").append(QString::number(d->maxInStatementIndent));
    options.append(separator);
  }
  if (d->minConditionalOption != d->defaultMinConditionalOption)
  {
    options.append("min-conditional-indent=").append(QString::number(static_cast<uint>(d->minConditionalOption)));
    options.append(separator);
  }

  // begin break-blocks check
  if (d->breakClosingBlocks)
  {
    options.append("break-blocks=all");
    options.append(separator);
  }
  else if (d->breakHeaderBlocks)
  {
    options.append("break-blocks");
    options.append(separator);
  }
  // end break-blocks check
  if (d->breakCloseBrackets)
  {
    options.append("break-closing-brackets");
    options.append(separator);
  }
  if (d->breakElseIfs)
  {
    options.append("break-elseifs");
    options.append(separator);
  }
  if (d->deleteEmptyLines)
  {
    options.append("delete-empty-lines");
    options.append(separator);
  }
  if (d->padOperators)
  {
    options.append("pad-oper");
    options.append(separator);
  }

  // begin pad parens check
  if (d->padParensOutside && d->padParensInside)
  {
    options.append("pad-paren");
    options.append(separator);
  }
  else if (d->padParensOutside)
  {
    options.append("pad-paren-out");
    options.append(separator);
  }
  else if (d->padParensInside)
  {
    options.append("pad-paren-in");
    options.append(separator);
  }
  // end pad parens check
  if (d->unpadParens)
  {
    options.append("unpad-paren");
    options.append(separator);
  }
  if (!d->breakOneLineStmts) // default = true
  {
    options.append("keep-one-line-statements");
    options.append(separator);
  }
  if (!d->breakOneLineBlocks) // default = true
  {
    options.append("keep-one-line-blocks");
    options.append(separator);
  }
  if (d->convertTabs)
  {
    options.append("convert-tabs");
    options.append(separator);
  }
  if (d->fillEmptyLines)
  {
    options.append("fill-empty-lines");
    options.append(separator);
  }

  // add the file mode, default is C++
  if (d->fileMode == FILEMODE_CPP)
  {
    if (options.length() > 0) // delete the last separator
      options.chop(1);
  }
  else if (d->fileMode == FILEMODE_JAVA)
    options.append("mode=java");
  else if (d->fileMode == FILEMODE_SHARP)
    options.append("mode=cs");
  else
    // force an error message
    options.append("invalid-fileMode=").append(
          QString::number(static_cast<uint>(d->fileMode)));

  return options;
}
