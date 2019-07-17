//
//  GameComponentScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../GameComponent.h"
#include "../GameObject.h"
#include "../GameManager.h"
#include "TestSimpleComponent.h"
#include "TestDependentComponent.h"
#include "TestSuperDependentComponent.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameComponent, "Construction/Normal", "unit,game", "GameComponent can be constructed." )
{
    std::string token = "moveable";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameComp = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(token);
}

SCENARIO( GameComponent, "Operation/Normal", "unit,game", "GameComponent can get shared pointer." )
{
    std::string token = "moveable";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameComp = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(token);
    
    auto sharedPtr = gameComp->getSharedGameComponent();
    
    VERIFY_EQUAL(3, static_cast<int>(sharedPtr.use_count()));
    VERIFY_SAMEPTR(gameComp.get(), sharedPtr.get());
}

SCENARIO( GameComponent, "Operation/Normal", "unit,game", "Game components know abilities." )
{
    std::string tokenComp = "DependentComponent";
    std::string compAbility = "Ability2";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameComp = pGameMgr->getOrCreateGameComponent<Test::TestDependentComponent>(tokenComp);

    auto abilities = gameComp->getAbilities();
    
    VERIFY_EQUAL(1, static_cast<int>(abilities.size()));
    VERIFY_EQUAL(compAbility, abilities.front());
}
