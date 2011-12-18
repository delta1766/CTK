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

#include "ctkCLIPluginExplorerMainWindow.h"
#include "ui_ctkCLIPluginExplorerMainWindow.h"

#include <ctkModuleDescriptionValidator.h>
#include <ctkModuleManager.h>

#include <QFile>
#include <QBuffer>
#include <QUiLoader>
#include <QDebug>

ctkCLIPluginExplorerMainWindow::ctkCLIPluginExplorerMainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::ctkCLIPluginExplorerMainWindow)
{
  ui->setupUi(this);
}

ctkCLIPluginExplorerMainWindow::~ctkCLIPluginExplorerMainWindow()
{
  delete ui;
}

void ctkCLIPluginExplorerMainWindow::showGui(const QString &xmlFile)
{
  QFile input(xmlFile);
  if (!input.exists())
  {
    qCritical() << "XML description does not exist:" << input.fileName();
    return;
  }
  input.open(QIODevice::ReadOnly);

  ctkModuleDescriptionValidator validator(&input);
  if (!validator.validate())
  {
    qCritical() << validator.errorString();
    return;
  }

  QUiLoader uiLoader;
  QByteArray uiBlob;
  uiBlob.append(validator.output());
  QBuffer uiForm(&uiBlob);

  QWidget* mainWidget = uiLoader.load(&uiForm, ui->mainTabWidget);
  if (mainWidget)
  {
      ui->mainTabWidget->addTab(mainWidget, mainWidget->objectName());
  }
}

void ctkCLIPluginExplorerMainWindow::on_actionRun_triggered()
{
  qDebug() << "Creating module command line...";

  QString cmdLine = ctkModuleManager::createCommandLine(ui->mainTabWidget->currentWidget());
}
