//
//  Test.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 5/13/13.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Test_Test_h
#define TUCUT_Test_Test_h

#include <algorithm>
#include <iostream>
#include <locale>
#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>

namespace TUCUT {
namespace Test {
    
inline std::vector<std::string> internalSplitString(const std::string & src, char delimiter)
{
    std::stringstream ss(src);
    std::string element;
    std::vector<std::string> result;
    
    while (std::getline(ss, element, delimiter))
    {
        result.push_back(element);
    }
    
    return result;
}

class VerificationException : public std::exception
{
public:
    VerificationException (int line)
    : mLine(line)
    { }
    
    virtual const char * what () const noexcept
    {
        return mMessage.c_str();
    }
    
protected:
    static std::string narrow (const std::wstring & wideString)
    {
        std::locale loc;
        std::vector<char> narrowCharBuf(wideString.size());
        std::use_facet<std::ctype<wchar_t>>(loc).narrow(
            wideString.data(),
            wideString.data() + wideString.size(),
            '?',
            narrowCharBuf.data());
        std::string narrowString = narrowCharBuf.data();
        return narrowString;
    }

    std::string mMessage;
    int mLine;
};

class BoolVerificationException : public VerificationException
{
public:
    BoolVerificationException (bool expectedValue, int line)
    : VerificationException(line), mExpectedValue(expectedValue)
    {
        initialize();
    }
    
    std::string expectedValue () const
    {
        if (mExpectedValue)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
    
protected:
    bool mExpectedValue;
    
private:
    void initialize ()
    {
        mMessage = "    Bool verification failed on line " + std::to_string(mLine) + ".\n"
                   "        Expected: " + expectedValue() + "\n";
    }
};

class SameVerificationException : public VerificationException
{
public:
    SameVerificationException (int line)
    : VerificationException(line)
    {
        initialize();
    }
    
private:
    void initialize ()
    {
        mMessage = "    Verification that objects are the same failed on line " + std::to_string(mLine) + ".\n";
    }
};

class EqualVerificationException : public VerificationException
{
public:
    EqualVerificationException (bool expectedValue, bool actualValue, int line)
    : VerificationException(line), mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }
    
    EqualVerificationException (int expectedValue, int actualValue, int line)
    : VerificationException(line), mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (unsigned int expectedValue, unsigned int actualValue, int line)
    : VerificationException(line), mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (long expectedValue, long actualValue, int line)
    : VerificationException(line), mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (unsigned long expectedValue, unsigned long actualValue, int line)
    : VerificationException(line), mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (float expectedValue, float actualValue, int line)
    : VerificationException(line), mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (double expectedValue, double actualValue, int line)
    : VerificationException(line), mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (const std::string & expectedValue, const std::string & actualValue, int line)
    : VerificationException(line), mExpectedValue(expectedValue), mActualValue(actualValue)
    {
        initialize();
    }

    EqualVerificationException (const std::wstring & expectedValue, const std::wstring & actualValue, int line)
    : VerificationException(line), mExpectedValue(narrow(expectedValue)), mActualValue(narrow(actualValue))
    {
        initialize();
    }
    
    std::string expectedValue () const
    {
        return mExpectedValue;
    }
    
    std::string actualValue () const
    {
        return mActualValue;
    }
    
protected:
    std::string mExpectedValue;
    std::string mActualValue;
    
private:
    void initialize ()
    {
        mMessage = "    Equal verification failed on line " + std::to_string(mLine) + ".\n"
                   "        Expected: " + expectedValue() + "\n"
                   "          Actual: " + actualValue() + "\n";
    }
};

class ScenarioBase
{
public:
    virtual ~ScenarioBase ()
    { }
    
    virtual std::string categoryFullName () const
    {
        return mCategoryFullName;
    }
    
    virtual std::string description () const
    {
        return mDescription;
    }
    
    virtual std::string tag () const
    {
        return mTag;
    }

    virtual bool exceptionExpected () const
    {
        return mExceptionExpected;
    }
    
    virtual bool passed () const
    {
        return mRunPassed;
    }
    
    virtual bool run (const std::vector<std::string> & tags)
    {
        // Run scenario if either mTag or tags is empty. Otherwise
        // all tags specified at run time must be present in the scenario.
        if (!mTag.empty())
        {
            bool matchFound = true;
            
            std::vector<std::string> scenarioTags = internalSplitString(mTag, ',');
            for (auto & tag: tags)
            {
                if (std::find(std::begin(scenarioTags), std::end(scenarioTags), tag) == std::end(scenarioTags))
                {
                    matchFound = false;
                    break;
                }
            }
            if (!matchFound)
            {
                return false;
            }
        }
        
        // Scenarios will pass unless one of the verify methods fail.
        mRunPassed = true;
        
        runSteps();
        
        return true;
    }
    
    virtual void runSteps () = 0;
    
    virtual std::shared_ptr<ScenarioBase> clone () const = 0;

    virtual void verifyTrue (bool actualValue, int line)
    {
        if (!actualValue)
        {
            mRunPassed = false;
            throw BoolVerificationException(true, line);
        }
    }
    
    virtual void verifyFalse (bool actualValue, int line)
    {
        if (actualValue)
        {
            mRunPassed = false;
            throw BoolVerificationException(false, line);
        }
    }
    
    virtual void verifyEqual (bool expectedValue, bool actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue, line);
        }
    }

    virtual void verifyEqual (int expectedValue, int actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue, line);
        }
    }

    virtual void verifyEqual (unsigned int expectedValue, unsigned int actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue, line);
        }
    }

    virtual void verifyEqual (long expectedValue, long actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue, line);
        }
    }

    virtual void verifyEqual (unsigned long expectedValue, unsigned long actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue, line);
        }
    }

    virtual void verifyEqual (float expectedValue, float actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue, line);
        }
    }

    virtual void verifyEqual (double expectedValue, double actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue, line);
        }
    }

    virtual void verifyEqual (const std::string & expectedValue, const std::string & actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue, line);
        }
    }

    virtual void verifyEqual (const std::wstring & expectedValue, const std::wstring & actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue, line);
        }
    }
    
    template <typename T>
    void verifySame (T * expectedValue, T * actualValue, int line)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw SameVerificationException(line);
        }
    }
    
protected:
    ScenarioBase (const std::string & categoryFullName, const std::string & scenarioDescription, bool exceptionExpected, const std::string & scenarioTag)
    : mCategoryFullName(categoryFullName), mDescription(scenarioDescription), mTag(scenarioTag), mExceptionExpected(exceptionExpected)
    { }
    
    ScenarioBase (const ScenarioBase & src)
    : mCategoryFullName(src.mCategoryFullName), mDescription(src.mDescription), mTag(src.mTag), mExceptionExpected(src.mExceptionExpected)
    { }
    
private:
    ScenarioBase & operator = (const ScenarioBase & rhs) = delete;
    
    std::string mCategoryFullName;
    std::string mDescription;
    std::string mTag;
    bool mExceptionExpected;
    bool mRunPassed;
};

template <typename ExceptionT = std::exception>
class Scenario : public ScenarioBase
{
public:
    Scenario (const std::string & categoryFullName, const std::string & scenarioDescription, bool exceptionExpected, const std::string & scenarioTag = "")
    : ScenarioBase(categoryFullName, scenarioDescription, exceptionExpected, scenarioTag)
    { }
    
    virtual ~Scenario ()
    { }
    
protected:
    Scenario (const Scenario & src)
    : ScenarioBase(src)
    { }
    
private:
    Scenario & operator = (const Scenario & rhs) = delete;
};

class Category
{
    friend class ScenarioManager;
    
public:
    Category (const std::string & name, const std::string & fullName)
    : mName(name), mFullName(fullName), mPassCount(0), mFailCount(0), mSkipCount(0)
    {
    }
    
    Category (const Category & src)
    : mName(src.mName), mChildCategories(src.mChildCategories), mChildScenarios(src.mChildScenarios),
      mPassCount(src.mPassCount), mFailCount(src.mFailCount), mSkipCount(src.mSkipCount)
    { }
    
    virtual ~Category ()
    { }
    
    virtual std::string name () const
    {
        return mName;
    }

    virtual std::string fullName () const
    {
        return mFullName;
    }

    virtual int passCount () const
    {
        return mPassCount;
    }

    virtual int failCount () const
    {
        return mFailCount;
    }

    virtual int skipCount () const
    {
        return mSkipCount;
    }

    std::vector<std::shared_ptr<Category>> categories ()
    {
        return mChildCategories;
    }
    
    std::vector<std::shared_ptr<ScenarioBase>> scenarios ()
    {
        return mChildScenarios;
    }
    
    virtual std::shared_ptr<ScenarioBase> registerScenario (const ScenarioBase * scenario)
    {
        std::shared_ptr<ScenarioBase> sharedScenario(scenario->clone());
        
        mChildScenarios.push_back(sharedScenario);
        
        return sharedScenario;
    }
    
    virtual void run (std::ostream & stream, const std::vector<std::string> & tags)
    {
        mPassCount = 0;
        mFailCount = 0;
        mSkipCount = 0;

        int childCategoryPassCount = 0;
        int childCategoryFailCount = 0;
        int childCategorySkipCount = 0;
        for (auto & category : mChildCategories)
        {
            category->run(stream, tags);
            childCategoryPassCount += category->passCount();
            childCategoryFailCount += category->failCount();
            childCategorySkipCount += category->skipCount();
        }
        
        if (!mChildScenarios.empty())
        {
            stream << "----- Running scenarios in: " << fullName() << " -----" << std::endl;
        }
        int localPassCount = 0;
        int localFailCount = 0;
        int localSkipCount = 0;
        for (auto & scenario : mChildScenarios)
        {
            try
            {
                if (!scenario->run(tags))
                {
                    localSkipCount++;
                }
                else if (scenario->passed())
                {
                    localPassCount++;
                    stream << "Scenario passed: " <<
                        scenario->description() << std::endl;
                }
                else
                {
                    localFailCount++;
                    stream << "Scenario failed: " <<
                        scenario->description() << std::endl;
                }
            }
            catch (VerificationException ex)
            {
                localFailCount++;
                stream << "Scenario failed: " <<
                    scenario->description() << std::endl <<
                    ex.what();
                continue;
            }
            catch (...)
            {
                localFailCount++;
                stream << "Scenario failed unexpectedly: " <<
                    scenario->description() << std::endl;
                continue;
            }
        }
        if (!mChildScenarios.empty())
        {
            stream << "----- Passed: " << localPassCount << " Failed: " << localFailCount << " Skipped: " << localSkipCount << " -----" << std::endl;
            stream << std::endl;
        }

        mPassCount = childCategoryPassCount + localPassCount;
        mFailCount = childCategoryFailCount + localFailCount;
        mSkipCount = childCategorySkipCount + localSkipCount;
    }
    
private:
    Category & operator = (const Category & rhs) = delete;
    
    std::string mName;
    std::string mFullName;
    int mPassCount;
    int mFailCount;
    int mSkipCount;
    // We can use shared_ptr for child stories because there are no cyclic links.
    std::vector<std::shared_ptr<Category>> mChildCategories;
    std::vector<std::shared_ptr<ScenarioBase>> mChildScenarios;
};

std::ostream & operator << (std::ostream & strm, const Category & category);

class ScenarioManager
{
public:
    virtual ~ScenarioManager ()
    { }
    
    static std::shared_ptr<ScenarioManager> instance ()
    {
        static std::shared_ptr<ScenarioManager> staticInstance(new ScenarioManager());
        
        return staticInstance;
    }
    
    std::vector<std::shared_ptr<Category>> categories ()
    {
        return mTopLevelCategories;
    }
    
    virtual std::shared_ptr<Category> registerCategory (const std::string & categoryFullName)
    {
        // Skip over initial forward slash characters.
        auto beginPosition = std::find_if_not(std::begin(categoryFullName), std::end(categoryFullName),
                                              [](char c) { return c == '/'; });
        if (beginPosition == std::end(categoryFullName))
        {
            throw std::invalid_argument("Category names cannot be empty or consist entirely of / characters.");
        }
        
        std::string trimmedCategoryFullName(beginPosition, std::end(categoryFullName));
        std::vector<std::string> categories = internalSplitString(trimmedCategoryFullName, '/');

        std::shared_ptr<Category> previousCategory;
        std::string currentFullName;
        for (auto & currentName: categories)
        {
            if (currentName.empty())
            {
                throw std::invalid_argument("Category names cannot be empty.");
            }
            
            if (!currentFullName.empty())
            {
                currentFullName += '/';
            }
            currentFullName += currentName;
            
            auto categoryIter = mAllCategories.find(currentFullName);
            if (categoryIter == std::end(mAllCategories))
            {
                std::shared_ptr<Category> newCategory(new Category(currentName, categoryFullName));
                categoryIter = mAllCategories.insert({currentFullName, newCategory}).first;
                if (previousCategory)
                {
                    previousCategory->mChildCategories.push_back(newCategory);
                }
                else
                {
                    mTopLevelCategories.push_back(newCategory);
                }
            }
            
            previousCategory = categoryIter->second;
        }
        
        return previousCategory;
    }
    
    virtual void run (std::ostream & stream, const std::vector<std::string> & tags)
    {
        int passCount = 0;
        int failCount = 0;
        int skipCount = 0;
        for (auto & category : mTopLevelCategories)
        {
            category->run(stream, tags);
            passCount += category->passCount();
            failCount += category->failCount();
            skipCount += category->skipCount();
        }
        stream << "----- Summary -----" << std::endl;
        stream << "Total number of tests run: " << passCount + failCount << std::endl;
        stream << "Tests passed: " << passCount << std::endl;
        stream << "Tests failed: " << failCount << std::endl;
        stream << "Tests skipped: " << skipCount << std::endl;
    }
    
private:
    ScenarioManager ()
    {
        mAllCategories.clear();
        mTopLevelCategories.clear();
    }
    
    std::map<std::string, std::shared_ptr<Category>> mAllCategories;
    std::vector<std::shared_ptr<Category>> mTopLevelCategories;
};

} // namespace Test
} // namespace TUCUT

#define INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME_FINAL( name, line ) ScenarioClass ## name ## line
#define INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME_RELAY( name, line ) INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME_FINAL( name, line )
#define INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( name ) INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME_RELAY( name, __LINE__ )

#define INTERNAL_TUCUT_TEST_SCENARIO_INSTANCE_NAME_FINAL( name, line ) ScenarioInstance ## name ## line
#define INTERNAL_TUCUT_TEST_SCENARIO_INSTANCE_NAME_RELAY( name, line ) INTERNAL_TUCUT_TEST_SCENARIO_INSTANCE_NAME_FINAL( name, line )
#define INTERNAL_TUCUT_TEST_SCENARIO_INSTANCE_NAME( name ) INTERNAL_TUCUT_TEST_SCENARIO_INSTANCE_NAME_RELAY( name, __LINE__ )

#define SCENARIO( preprocGroupName, preprocCategoryName, preprocTag, preprocScenarioDescription ) class INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName ) \
: public TUCUT::Test::Scenario<> \
{ \
public: \
    INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName ) (const std::string & categoryFullName, const std::string & scenarioDescription, bool exceptionExpected, const std::string & scenarioTag) \
    : TUCUT::Test::Scenario<>(categoryFullName, scenarioDescription, exceptionExpected, scenarioTag) \
    { \
        auto scenarioManager = TUCUT::Test::ScenarioManager::instance(); \
        auto category = scenarioManager->registerCategory(categoryFullName); \
        category->registerScenario(this); \
    } \
    virtual std::shared_ptr<TUCUT::Test::ScenarioBase> clone () const \
    { \
        return std::shared_ptr<TUCUT::Test::ScenarioBase>(new INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName )(*this)); \
    } \
    virtual void runSteps (); \
protected: \
    INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName ) (const INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName ) & src) \
    : TUCUT::Test::Scenario<>(src) \
    { } \
}; \
static INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName ) INTERNAL_TUCUT_TEST_SCENARIO_INSTANCE_NAME( preprocGroupName )(preprocCategoryName, preprocScenarioDescription, false, preprocTag); \
void INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName )::runSteps ()

#define VERIFY_TRUE(actual) verifyTrue(actual, __LINE__)
#define VERIFY_FALSE(actual) verifyFalse(actual, __LINE__)
#define VERIFY_EQUAL(expected, actual) verifyEqual(expected, actual, __LINE__)
#define VERIFY_SAME(expected, actual) verifySame(expected, actual, __LINE__)

#ifdef TUCUT_TEST_GENERATE_MAIN

namespace TUCUT {
namespace Test {
    
int main (int argc, const char * argv[])
{
    std::vector<std::string> tags;
    for (int i = 1; i < argc; i++)
    {
        tags.push_back(argv[i]);
    }
    
    auto scenarioManager = ScenarioManager::instance();
    
    scenarioManager->run(std::cout, tags);
    
    return 0;
}
        
} // namespace Test
} // namespace TUCUT

int main (int argc, const char * argv[])
{
    int result = TUCUT::Test::main(argc, argv);
    
    return result;
}

#endif // TUCUT_TEST_GENERATE_MAIN

#ifdef TUCUT_TEST_GENERATE_GLOBALS

namespace TUCUT {
namespace Test {
        
std::ostream & operator << (std::ostream & strm, const Category & category)
{
    return strm;
}
        
} // namespace Test
} // namespace TUCUT

#endif // TUCUT_TEST_GENERATE_GLOBALS

#endif // TUCUT_Test_Test_h
