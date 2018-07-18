//
//  Test.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 5/13/13.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Test_Test_h
#define TUCUT_Test_Test_h

#include <iostream>
#include <locale>
#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>

namespace TUCUT {
namespace Test {
    
class VerificationException : public std::exception
{
public:
    VerificationException ()
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
};

class BoolVerificationException : public VerificationException
{
public:
    BoolVerificationException (bool expectedValue)
    : mExpectedValue(expectedValue)
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
        mMessage = "    Bool verification failed.\n"
                   "        Expected: " + expectedValue() + "\n";
    }
};

class SameVerificationException : public VerificationException
{
public:
    SameVerificationException ()
    {
        initialize();
    }
    
private:
    void initialize ()
    {
        mMessage = "    Verification that objects are the same failed.\n";
    }
};

class EqualVerificationException : public VerificationException
{
public:
    EqualVerificationException (bool expectedValue, bool actualValue)
    : mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }
    
    EqualVerificationException (int expectedValue, int actualValue)
    : mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (unsigned int expectedValue, unsigned int actualValue)
    : mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (long expectedValue, long actualValue)
    : mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (unsigned long expectedValue, unsigned long actualValue)
    : mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (float expectedValue, float actualValue)
    : mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (double expectedValue, double actualValue)
    : mExpectedValue(std::to_string(expectedValue)), mActualValue(std::to_string(actualValue))
    {
        initialize();
    }

    EqualVerificationException (const std::string & expectedValue, const std::string & actualValue)
    : mExpectedValue(expectedValue), mActualValue(actualValue)
    {
        initialize();
    }

    EqualVerificationException (const std::wstring & expectedValue, const std::wstring & actualValue)
    : mExpectedValue(narrow(expectedValue)),
      mActualValue(narrow(actualValue))
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
        mMessage = "    Equal verification failed.\n"
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
    
    virtual bool exceptionExpected () const
    {
        return mExceptionExpected;
    }
    
    virtual bool passed () const
    {
        return mRunPassed;
    }
    
    virtual void run ()
    {
        // Scenarios will pass unless one of the verify methods fail.
        mRunPassed = true;
        
        runSteps();
    }
    
    virtual void runSteps () = 0;
    
    virtual std::shared_ptr<ScenarioBase> clone () const = 0;

    virtual void verifyTrue (bool actualValue)
    {
        if (!actualValue)
        {
            mRunPassed = false;
            throw BoolVerificationException(true);
        }
    }
    
    virtual void verifyFalse (bool actualValue)
    {
        if (actualValue)
        {
            mRunPassed = false;
            throw BoolVerificationException(false);
        }
    }
    
    virtual void verifyEqual (bool expectedValue, bool actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue);
        }
    }

    virtual void verifyEqual (int expectedValue, int actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue);
        }
    }

    virtual void verifyEqual (unsigned int expectedValue, unsigned int actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue);
        }
    }

    virtual void verifyEqual (long expectedValue, long actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue);
        }
    }

    virtual void verifyEqual (unsigned long expectedValue, unsigned long actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue);
        }
    }

    virtual void verifyEqual (float expectedValue, float actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue);
        }
    }

    virtual void verifyEqual (double expectedValue, double actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue);
        }
    }

    virtual void verifyEqual (const std::string & expectedValue, const std::string & actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue);
        }
    }

    virtual void verifyEqual (const std::wstring & expectedValue, const std::wstring & actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw EqualVerificationException(expectedValue, actualValue);
        }
    }
    
    template <typename T>
    void verifySame (T * expectedValue, T * actualValue)
    {
        if (actualValue != expectedValue)
        {
            mRunPassed = false;
            throw SameVerificationException();
        }
    }
    
protected:
    ScenarioBase (const std::string & categoryFullName, const std::string & scenarioDescription, bool exceptionExpected)
    : mCategoryFullName(categoryFullName), mDescription(scenarioDescription), mExceptionExpected(exceptionExpected)
    { }
    
    ScenarioBase (const ScenarioBase & src)
    : mCategoryFullName(src.mCategoryFullName), mDescription(src.mDescription), mExceptionExpected(src.mExceptionExpected)
    { }
    
private:
    ScenarioBase & operator = (const ScenarioBase & rhs) = delete;
    
    std::string mCategoryFullName;
    std::string mDescription;
    bool mExceptionExpected;
    bool mRunPassed;
};

template <typename ExceptionT = std::exception>
class Scenario : public ScenarioBase
{
public:
    Scenario (const std::string & categoryFullName, const std::string & scenarioDescription, bool exceptionExpected)
    : ScenarioBase(categoryFullName, scenarioDescription, exceptionExpected)
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
    : mName(name), mFullName(fullName), mPassCount(0), mFailCount(0)
    {
    }
    
    Category (const Category & src)
    : mName(src.mName), mChildCategories(src.mChildCategories), mChildScenarios(src.mChildScenarios),
      mPassCount(src.mPassCount), mFailCount(src.mFailCount)
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
    
    virtual void run (std::ostream & stream)
    {
        mPassCount = 0;
        mFailCount = 0;

        int childCategoryPassCount = 0;
        int childCategoryFailCount = 0;
        for (auto & category : mChildCategories)
        {
            category->run(stream);
            childCategoryPassCount += category->passCount();
            childCategoryFailCount += category->failCount();
        }
        
        if (!mChildScenarios.empty())
        {
            stream << "----- Running scenarios in: " << fullName() << " -----" << std::endl;
        }
        int localPassCount = 0;
        int localFailCount = 0;
        for (auto & scenario : mChildScenarios)
        {
            try
            {
                scenario->run();
                if (scenario->passed())
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
            stream << "----- Passed: " << localPassCount << " Failed: " << localFailCount << " -----" << std::endl;
            stream << std::endl;
        }

        mPassCount = childCategoryPassCount + localPassCount;
        mFailCount = childCategoryFailCount + localFailCount;
    }
    
private:
    Category & operator = (const Category & rhs) = delete;
    
    std::string mName;
    std::string mFullName;
    int mPassCount;
    int mFailCount;
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
        std::string::size_type beginPosition = categoryFullName.find_first_not_of("/");
        if (beginPosition == std::string::npos)
        {
            throw std::invalid_argument("Category names cannot consist entirely of / characters.");
        }
        
        std::string::size_type currentBeginPosition = beginPosition;
        std::string::size_type currentEndPosition;
        std::shared_ptr<Category> previousCategory;
        while (currentBeginPosition != std::string::npos)
        {
            currentEndPosition = categoryFullName.find_first_of("/", currentBeginPosition);
            if (currentEndPosition == std::string::npos)
            {
                currentEndPosition = categoryFullName.length();
            }
            
            std::string currentFullName = categoryFullName.substr(beginPosition,
                currentEndPosition - beginPosition);
            std::string currentName = categoryFullName.substr(currentBeginPosition,
                currentEndPosition - currentBeginPosition);
            
            if (currentName.empty())
            {
                throw std::invalid_argument("Category names cannot be empty.");
            }
            
            auto categoryIter = mAllCategories.find(currentFullName);
            if (categoryIter == mAllCategories.end())
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
            
            currentBeginPosition = categoryFullName.find_first_not_of("/", currentEndPosition);
        }
        
        return previousCategory;
    }
    
    virtual void run (std::ostream & stream)
    {
        int passCount = 0;
        int failCount = 0;
        for (auto & category : mTopLevelCategories)
        {
            category->run(stream);
            passCount += category->passCount();
            failCount += category->failCount();
        }
        stream << "----- Summary -----" << std::endl;
        stream << "Total number of tests run: " << passCount + failCount << std::endl;
        stream << "Tests passed: " << passCount << std::endl;
        stream << "Tests failed: " << failCount << std::endl;
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

#define SCENARIO( preprocGroupName, preprocCategoryName, preprocScenarioDescription ) class INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName ) \
: public TUCUT::Test::Scenario<> \
{ \
public: \
    INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName ) (const std::string & categoryFullName, const std::string & scenarioDescription, bool exceptionExpected) \
    : TUCUT::Test::Scenario<>(categoryFullName, scenarioDescription, exceptionExpected) \
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
INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName ) INTERNAL_TUCUT_TEST_SCENARIO_INSTANCE_NAME( preprocGroupName )(preprocCategoryName, preprocScenarioDescription, false); \
void INTERNAL_TUCUT_TEST_SCENARIO_CLASS_NAME( preprocGroupName )::runSteps ()

#ifdef TUCUT_TEST_GENERATE_MAIN

namespace TUCUT {
namespace Test {
    
int main (int argc, const char * argv[])
{
    auto scenarioManager = ScenarioManager::instance();
    
    scenarioManager->run(std::cout);
    
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
