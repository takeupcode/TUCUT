//  WindowSystem.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-10-26.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_WindowSystem_h
#define TUCUT_TUI_WindowSystem_h

#include <memory>
#include <string>
#include <vector>

#include "../Game/GameManager.h"

namespace TUCUT::TUI
{
  class Window;

  class WindowSystem : public Game::GameSystem
  {
  public:
    static const std::string defaultToken;

    std::shared_ptr<WindowSystem> getSharedWindowSystem ();

    ~WindowSystem ();

    void initialize () override;

    void addWindow(const std::shared_ptr<Window> & window);
    void addWindow(std::shared_ptr<Window> && window);

    void selectNextWindow(const std::string & name);

    int screenWidth () const;

    int screenHeight () const;

    int minScreenWidth () const;

    int minScreenHeight () const;

    void setMinScreenDimensions (int height, int width);

    int maxScreenWidth () const;

    int maxScreenHeight () const;

    void setMaxScreenDimensions (int height, int width);

  private:
    friend class Game::GameManager;

    WindowSystem (const std::string & token, int identity);

    void deinitialize ();

    void handleInput () override;

    void update (Game::TimeResolution elapsedTime) override;

    void render () override;

    int checkHeightBounds (int height) const;

    int checkWidthBounds (int width) const;

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
