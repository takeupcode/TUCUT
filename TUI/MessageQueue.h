#ifndef TUCUT_TUI_MessageQueue_h
#define TUCUT_TUI_MessageQueue_h

#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>

namespace TUCUT::TUI
{
  template <class T>
  class MessageQueue final
  {
  public:
    bool post (T const & msg)
    {
      {
        std::lock_guard<std::mutex> lock(mMutex);

        if (mExit)
        {
          return false;
        }
        mQueue.push(msg);
      }
      mCV.notify_one();
      return true;
    }

    bool get (T & msg)
    {
      while (true)
      {
        std::unique_lock<std::mutex> lock(mMutex);
        if (mQueue.empty())
        {
          if (mExit)
          {
            return false;
          }
          mCV.wait(lock);
        }

        // We don't use a lambda in the wait method to
        // perform the spurious wakeup test because we
        // also want to check if we are exiting. It seems
        // simpler to check like this instead of doing both
        // checks in a lambda only to have to check the
        // queue again anyway.
        if (mQueue.empty())
        {
          continue;
        }
        msg = std::move(mQueue.front());
        mQueue.pop();
        return true;
      }
      return false;
    }

    bool getNonBlocking (T & msg)
    {
      std::lock_guard<std::mutex> lock(mMutex);
      if (mQueue.empty())
      {
        return false;
      }
      msg = std::move(mQueue.front());
      mQueue.pop();
      return true;
    }

    void exit ()
    {
      {
        std::lock_guard<std::mutex> lock(mMutex);
        mExit = true;
      }
      mCV.notify_one();
    }

    bool empty () const
    {
      std::lock_guard<std::mutex> lock(mMutex);
      return mQueue.empty();
    }

    bool done () const
    {
      std::lock_guard<std::mutex> lock(mMutex);
      return mExit && mQueue.empty();
    }

  private:
    mutable std::mutex mMutex;
    std::queue<T> mQueue;
    std::condition_variable mCV;
    bool mExit = false;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_MessageQueue_h
