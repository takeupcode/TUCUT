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

    virtual void render (WindowSystem * ws) const
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

    void setParentPart (Part * parent)
    { mParentPart = parent; }

    virtual VisibleState visibleState () const
    { return VisibleState::Shown; }

    virtual void setVisibleState (VisibleState value)
    { }

  protected:
    std::vector<Part> mParts;
    Part * mParentPart;
  };
} // namespace TUCUT::Presentation

#endif // TUCUT_Presentation_Part_h
