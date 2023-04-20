//  WindowSystem.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-10-26.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_WindowSystem_h
#define TUCUT_TUI_WindowSystem_h

#include "../ECS/Application.h"
#include "../ECS/ApplicationTime.h"
#include "../ECS/System.h"

#include <memory>
#include <string>
#include <vector>

namespace TUCUT::TUI
{
  class Window;

  class WindowSystem : public ECS::System
  {
  public:
    static std::string const defaultToken;

    std::shared_ptr<WindowSystem> getSharedWindowSystem ();

    void initialize () override;

    void addWindow(std::shared_ptr<Window> const & window);
    void addWindow(std::shared_ptr<Window> && window);

    void selectNextWindow(std::string const & name);

    int screenWidth () const;

    int screenHeight () const;

    int minScreenWidth () const;

    int minScreenHeight () const;

    void setMinScreenDimensions (int width, int height);

    int maxScreenWidth () const;

    int maxScreenHeight () const;

    void setMaxScreenDimensions (int width, int height);

  private:
    friend class ECS::Application;

    WindowSystem (std::string const & token, int identity);

    void handleInput () override;

    void update (ECS::TimeResolution elapsedTime) override;

    void render () override;

    int clampWidthBounds (int width) const;

    int clampHeightBounds (int height) const;

    Terminal mTerminal;
    int mScreenMaxX;
    int mScreenMaxY;
    int mMinScreenWidth;
    int mMinScreenHeight;
    int mMaxScreenWidth;
    int mMaxScreenHeight;
    Window * mNextWindow;
    Window * mCurrentWindow;
    std::vector<std::shared_ptr<Window>> mWindows;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_WindowSystem_h
