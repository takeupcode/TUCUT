#include "Game.h"

#include "Terminal.h"

#include <chrono>
#include <ctime>
#include <string>

TUCUT::TUI::Game::Game(
  Terminal & terminal,
  unsigned int seed)
: mTerminal(terminal),
  mOutput(terminal.output()),
  mGameOver(true),
  mPrompt(terminal),
  mOriginalSeed(seed),
  mPercent(0, 100)
{
  mForeRed.changeColor(
    TextLayer::Foreground,
    Palette::ColorsTrue,
    135, 0, 0);

  mForeBrightRed.changeColor(
    TextLayer::Foreground,
    Palette::ColorsTrue,
    255, 0, 0);
}

void TUCUT::TUI::Game::play ()
{
  reset(mOriginalSeed);

  draw();
  while (!mGameOver)
  {
    processInput();
    processUpdate();
    draw();
  }
}

void TUCUT::TUI::Game::quit ()
{
  mGameOver = true;
}

std::ostream & TUCUT::TUI::Game::output () const
{
  return mOutput;
}

TUCUT::TUI::Prompt & TUCUT::TUI::Game::prompt ()
{
  return mPrompt;
}

unsigned int TUCUT::TUI::Game::seed () const
{
  return mSeed;
}

int TUCUT::TUI::Game::randomPercent ()
{
  return mPercent(mRNG);
}

void TUCUT::TUI::Game::processInput ()
{
  mChoice = mPrompt.promptChoice("Enter choice: ",
    {"Less than", "Greater than or equal"});
}

void TUCUT::TUI::Game::processUpdate ()
{
  if (mNextNumber < mCurrentNumber)
  {
    if (mChoice != 0)
    {
      quit();
    }
  }
  else
  {
    if (mChoice != 1)
    {
      quit();
    }
  }

  mCurrentNumber = mNextNumber;
  mNextNumber = randomPercent();
}

void TUCUT::TUI::Game::clearDisplay ()
{
  mTerminal.clearScreen();
}

void TUCUT::TUI::Game::draw ()
{
  if (mGameOver)
  {
    // By this time, the numbers have been changed.
    mOutput << mForeBrightRed
      << "\nWrong choice!"
      << " The next number was "
      << mCurrentNumber << "."
      << " Game over.\n";
    mTerminal.resetGraphics();
    return;
  }
  clearDisplay();
  mTerminal.moveCursor(0, 0);

  mOutput << mForeRed
    << "\nCurrent number is: " << mCurrentNumber << "\n"
    << "Predict how the next number will compare!" << "\n\n";
  mTerminal.resetGraphics();
}

void TUCUT::TUI::Game::reset (unsigned int seed)
{
  if (seed == 0)
  {
    seed = static_cast<int>(std::chrono::system_clock::now().
      time_since_epoch().count());
  }
  mSeed = seed;
  mRNG.seed(mSeed);

  mGameOver = false;

  mCurrentNumber = randomPercent();
  mNextNumber = randomPercent();
}
