//
//  ScenarioScenarios.cpp
//  TUCUTTests
//
//  Created by Wahid Tanner on 5/18/13.
//

#include <vector>

#include "../Test.h"

using namespace TUCUT;

SCENARIO( Scenario, "Registration/Normal", "Scenario is registered automatically." )
{
    auto scenarioManager = Test::ScenarioManager::instance();
    auto topLevelCategoryCollection = scenarioManager->categories();
    
    std::vector<std::shared_ptr<Test::Category>> categoryStack{};
    categoryStack.insert(categoryStack.end(), topLevelCategoryCollection.begin(), topLevelCategoryCollection.end());
    
    bool scenarioFound = false;
    while (!categoryStack.empty())
    {
        auto category = categoryStack.back();
        categoryStack.pop_back();
        auto categoryCollection = category->categories();
        categoryStack.insert(categoryStack.end(), categoryCollection.begin(), categoryCollection.end());

        auto scenarioCollection = category->scenarios();
        for (auto scenario : scenarioCollection)
        {
            if (scenario->description() == this->description())
            {
                scenarioFound = true;
                break;
            }
        }
        if (scenarioFound)
        {
            break;
        }
    }
    verifyTrue(scenarioFound);
}

SCENARIO( Scenario, "Verification/Types", "Verification supports wide character equality." )
{
    std::wstring expected = L"Wide";
    std::wstring actual = L"Wide";
    verifyEqual(expected, actual);
}
