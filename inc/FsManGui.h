////////////////////////////////////////////////////////////////////////////////
//
// File: FsManGui.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef INC_FSMANGUI_H_
#define INC_FSMANGUI_H_

#include <memory>

#include "ui/Window.h"

class FsManGui : public Window
{
  public:

    FsManGui();

    virtual ~FsManGui();

    void onClose();

  protected:

    virtual void create();

    virtual void postCreate();

  private:

    class FsManGuiPrivate;

    std::auto_ptr<FsManGuiPrivate> d;
};
#endif /* INC_FSMANGUI_H_ */
