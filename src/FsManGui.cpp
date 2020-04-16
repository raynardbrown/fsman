////////////////////////////////////////////////////////////////////////////////
//
// File: FsManGui.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "ui/UiApplication.h"

#include "ui/event/CloseObserver.h"

#include "ui/layout/RowLayout.h"

#include "FsManGui.h"

class FsManGui::FsManGuiPrivate
{
  public:

    FsManGuiPrivate()
    :mainRowLayout(nullptr)
    {
    }

    ~FsManGuiPrivate()
    {
    }

    void createAllUiComponents()
    {
    }

    RowLayout * mainRowLayout;
};

FsManGui::FsManGui()
:Window("FSMan",
        800,
        600),
 d(std::auto_ptr<FsManGuiPrivate>(new FsManGuiPrivate()))
{
  d->mainRowLayout = new RowLayout(this);

  d->createAllUiComponents();
}

FsManGui::~FsManGui()
{

}

void FsManGui::onClose()
{
  UiApplication::quit();
}

void FsManGui::create()
{
  CloseObserver<FsManGui> * closeObserver  = new CloseObserver<FsManGui>(this, &FsManGui::onClose);

  addCloseObserver(closeObserver);
}

void FsManGui::postCreate()
{
  setTopPadding(11);
  setBottomPadding(11);
  setLeftPadding(11);
  setRightPadding(11);
}
