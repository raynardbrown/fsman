////////////////////////////////////////////////////////////////////////////////
//
// File: maingui.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "ui/UiApplication.h"

#include "FsManGui.h"

int main(int argc, char ** argv)
{
  UiApplication app(argc,  argv);

  int exitCode = 0;

  FsManGui * fsManGui = new FsManGui();

  fsManGui->showWindow();

  exitCode = app.run(fsManGui);

  return exitCode;
}
