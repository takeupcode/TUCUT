//  Glyph.h
//  TUCUT/Text (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-05-05.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Text_Glyph_h
#define TUCUT_Text_Glyph_h

#include <string>
#include <vector>

namespace TUCUT::Text
{
  class Composite
  {
  public:
    virtual ~Composite () = default;
  };

  class Glyph final
  {
  public:
    // The initial character cannot be a combining
    // character. If the initial character is a
    // control character, then no combining characters
    // will be allowed.
    explicit Glyph (uint32_t character);

    // The initial character determines if this glyph
    // is a control character.
    bool isControl () const;

    // The initial character determines if this glyph
    // is normal width or square. Control characters
    // have no print ability so they are not square.
    bool isSquare () const;

    // Any character supplied here must be combining.
    void combineWithGlyph (uint32_t character);

    // Get the UTF8 representation of the base character
    // and all combining characters.
    std::string utf8 () const;

  private:
    std::vector<uint32_t> mCodePoints;
    bool mControl;
    bool mSquare;
  };

  int glyphWidth (uint32_t character);

  // If the string contains any control characters,
  // including escape sequences, then the width will be -1.
  // Otherwise, this is the number of terminal locations
  // needed to display the string.
  int stringWidth (std::string const & utf8);

  // Combining characters will be added to their base
  // glyph. Control characters will get their own glyph
  // in the vector.
  std::vector<Glyph> splitIntoGlyphs (
    std::string const & utf8);

  std::string substr (
    std::string const & utf8,
    size_t pos,
    size_t length);

  std::string replace (
    std::string const & utf8,
    std::string const & text,
    size_t pos,
    size_t length);

  std::string truncate (
    std::string const & utf8,
    size_t length);
} // namespace TUCUT::Text

#endif // TUCUT_Text_Glyph_h
