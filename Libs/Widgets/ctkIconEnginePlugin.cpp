/*=========================================================================

  Library:   CTK
 
  Copyright (c) 2010  Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 
=========================================================================*/

// Qt includes
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QImageReader>
#include <QPainter>

#include "ctkIconEnginePlugin.h"

class ctkIconEnginePluginPrivate:public ctkPrivate<ctkIconEnginePlugin>
{
public:
  QStringList SizeDirectories;
};

//------------------------------------------------------------------------------
ctkIconEnginePlugin::ctkIconEnginePlugin(QObject* parentObject)
 :QIconEnginePluginV2(parentObject)
{
  CTK_INIT_PRIVATE(ctkIconEnginePlugin);
}

//------------------------------------------------------------------------------
QIconEngineV2* ctkIconEnginePlugin::create(const QString& fileName)
{
  CTK_D(ctkIconEnginePlugin);
  Q_UNUSED(fileName);
  ctkIconEngine* iconEngine = new ctkIconEngine;
  iconEngine->setSizeDirectories(d->SizeDirectories);
  return iconEngine;
}

//------------------------------------------------------------------------------
QStringList ctkIconEnginePlugin::keys()const
{
  QStringList supportedKeys;
  foreach(QByteArray byteArray, QImageReader::supportedImageFormats())
    {
    supportedKeys << QString(byteArray);
    }
  return supportedKeys;
}

//------------------------------------------------------------------------------
void ctkIconEnginePlugin::setSizeDirectories(const QStringList& sizeDirectories)
{
  CTK_D(ctkIconEnginePlugin);
  d->SizeDirectories = sizeDirectories;
}

//------------------------------------------------------------------------------
QStringList ctkIconEnginePlugin::sizeDirectories()const
{
  CTK_D(const ctkIconEnginePlugin);
  return d->SizeDirectories;
}

//------------------------------------------------------------------------------
class ctkIconEnginePrivate:public ctkPrivate<ctkIconEngine>
{
public:
  QStringList SizeDirectories;
};

//------------------------------------------------------------------------------
ctkIconEngine::ctkIconEngine()
{
  CTK_INIT_PRIVATE(ctkIconEngine);
}

//------------------------------------------------------------------------------
void ctkIconEngine::addFile(const QString& fileName, const QSize& size,
                            QIcon::Mode mode, QIcon::State state)
{
  CTK_D(ctkIconEngine);
  this->Superclass::addFile(fileName, size, mode, state);
  QString sizeDirectory;
  foreach(QString directory, d->SizeDirectories)
    {
    if (fileName.contains(directory))
      {
      sizeDirectory = directory;
      break;
      }
    }
  if (sizeDirectory.isEmpty())
    {
    return;
    }
  foreach(QString directory, d->SizeDirectories)
    {
    QString otherFileName = fileName;
    otherFileName.replace(sizeDirectory, directory);
    if (otherFileName != fileName)
      {
      this->Superclass::addFile(otherFileName, QSize(), mode, state);
      }
    }
  /*
  QFileInfo file(fileName);
  QDir dir = file.dir();
  foreach(QString subdirPath, dir.entryList(QDir::NoDotAndDotDot | QDir::Dirs))
    {
    QDir subdir(subdirPath);
    QStringList matchingFiles = subdir.entryList(QStringList() <<file.fileName());
    if (matchingFiles.size() && matchingFiles[0] != fileName)
      {
      this->Superclass::addFile(matchingFiles[0], QSize(), mode, state);
      }
    }
  */
}

//------------------------------------------------------------------------------
void ctkIconEngine::setSizeDirectories(const QStringList& sizeDirectories)
{
  CTK_D(ctkIconEngine);
  d->SizeDirectories = sizeDirectories;
}

//------------------------------------------------------------------------------
QStringList ctkIconEngine::sizeDirectories()const
{
  CTK_D(const ctkIconEngine);
  return d->SizeDirectories;
}
