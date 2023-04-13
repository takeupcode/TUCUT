#ifndef TUCUT_TUI_Game_h
#define TUCUT_TUI_Game_h

#include "Prompt.h"
#include "Terminal.h"

#include <istream>
#include <ostream>
#include <random>

namespace TUCUT::TUI
{
  class Game
  {
  public:
    Game (
      Terminal & terminal,
      unsigned int seed = 0);

    void play ();
    void quit ();

    std::ostream & output () const;

    Prompt & prompt ();

    unsigned int seed () const;

    int randomPercent ();

  private:
    void processInput ();

    void processUpdate ();

    void clearDisplay ();

    void draw ();

    void reset (unsigned int seed = 0);

    Terminal & mTerminal;
    std::ostream & mOutput;
    bool mGameOver;
    Prompt mPrompt;
    unsigned int mOriginalSeed;
    unsigned int mSeed;
    std::mt19937 mRNG;
    std::uniform_int_distribution<std::mt19937::result_type>
      mPercent;

    Color mForeRed;
    Color mForeBrightRed;

    int mChoice;
    unsigned int mCurrentNumber;
    unsigned int mNextNumber;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Game_h
