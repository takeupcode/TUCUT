//  Part.h
//  TUCUT/Presentation (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-05-07.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Presentation_Part_h
#define TUCUT_Presentation_Part_h

namespace TUCUT::Presentation
{
  template <typename Window, typename WindowSystem>
  class Part
  {
  public:
    enum class VisibleState
    {
      Collapsed,
      Hidden,
      Shown,
      Protected
    };

    virtual ~Part () = default;

    virtual void draw (WindowSystem * ws) const
    { }

    virtual int x () const
    { return 0; }

    virtual int worldX () const
    { return 0; }

    virtual void setX (int x)
    { }

    virtual int y () const
    { return 0; }

    virtual int worldY () const
    { return 0; }

    virtual void setY (int y)
    { }

    virtual void move (int x, int y)
    { }

    virtual int width () const
    { return 0; }

    virtual int minWidth () const
    { return 0; }

    virtual void setWidth (int width)
    { }

    virtual void setMinWidth (int width)
    { }

    virtual int height () const
    { return 0; }

    virtual int minHeight () const
    { return 0; }

    virtual void setHeight (int height)
    { }

    virtual void setMinHeight (int height)
    { }

    virtual void resize (int width, int height)
    { }

    virtual void addPart (Part const & part)
    { }

    virtual void addPart (Part && part)
    { }

    virtual Window * getWindow () const
    { return nullptr; }

    virtual Window * closestWindow () const
    {
      auto * window = getWindow();
      if (window == nullptr && mParentPart != nullptr)
      {
        window = mParentPart->closestWindow();
      }

      return window;
    }

    Part * parentPart () const
    { return mParentPart; }

    virtual VisibleState visibleState () const
    { return VisibleState::Shown; }

    virtual void setVisibleState (VisibleState value)
    { }

    // The behavior of a tab varies widely and likely
    // affects how following parts are drawn based on
    // the position of the tab. This is too much
    // responsibility for this part to handle so all
    // it does is identify itself as a tab so that
    // some other code can figure out what to do.
    virtual bool isTab () const
    { return false; }

  protected:
    void setParentPart (Part * parent)
    { mParentPart = parent; }

    Part * mParentPart;
  };
} // namespace TUCUT::Presentation

#endif // TUCUT_Presentation_Part_h
