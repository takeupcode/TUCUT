//
//  GameComponent.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameComponent_h
#define TUCUT_Game_GameComponent_h

#include <memory>
#include <string>
#include <vector>

#include "PropertyValue.h"
#include "../Identity/Identifiable.h"

namespace TUCUT {
namespace Game {

class GameObject;
    
class GameComponent : public std::enable_shared_from_this<GameComponent>, public Identity::Identifiable<int>
{
public:
    static const std::string defaultToken;
    
    std::shared_ptr<GameComponent> getSharedGameComponent ();
    
    virtual ~GameComponent () = default;
    
    virtual std::vector<std::string> getAbilities () const
    {
        return mAbilityTokens;
    }

    virtual void addDefaultProperties (int objectId) const;
    virtual void addDefaultProperties (const std::shared_ptr<GameObject> & object) const;
    
    virtual void removeProperties (int objectId) const;
    virtual void removeProperties (const std::shared_ptr<GameObject> & object) const;

    virtual std::string getString (int objectId, int propertyId) const;
    virtual std::string getString (const std::shared_ptr<GameObject> & object, int propertyId) const;
    virtual int getInteger (int objectId, int propertyId) const;
    virtual int getInteger (const std::shared_ptr<GameObject> & object, int propertyId) const;
    virtual double getFloating (int objectId, int propertyId) const;
    virtual double getFloating (const std::shared_ptr<GameObject> & object, int propertyId) const;
    virtual bool getBoolean (int objectId, int propertyId) const;
    virtual bool getBoolean (const std::shared_ptr<GameObject> & object, int propertyId) const;

    virtual std::vector<std::string> getStrings (int objectId, int propertyId) const;
    virtual std::vector<std::string> getStrings (const std::shared_ptr<GameObject> & object, int propertyId) const;
    virtual std::vector<int> getIntegers (int objectId, int propertyId) const;
    virtual std::vector<int> getIntegers (const std::shared_ptr<GameObject> & object, int propertyId) const;
    virtual std::vector<double> getFloatings (int objectId, int propertyId) const;
    virtual std::vector<double> getFloatings (const std::shared_ptr<GameObject> & object, int propertyId) const;
    virtual std::vector<bool> getBooleans (int objectId, int propertyId) const;
    virtual std::vector<bool> getBooleans (const std::shared_ptr<GameObject> & object, int propertyId) const;

    virtual void setString (int objectId, int propertyId, const std::string & value) const;
    virtual void setString (const std::shared_ptr<GameObject> & object, int propertyId, const std::string & value) const;
    virtual void setInteger (int objectId, int propertyId, int value) const;
    virtual void setInteger (const std::shared_ptr<GameObject> & object, int propertyId, int value) const;
    virtual void setFloating (int objectId, int propertyId, double value) const;
    virtual void setFloating (const std::shared_ptr<GameObject> & object, int propertyId, double value) const;
    virtual void setBoolean (int objectId, int propertyId, bool value) const;
    virtual void setBoolean (const std::shared_ptr<GameObject> & object, int propertyId, bool value) const;

    virtual void setStrings (int objectId, int propertyId, const std::vector<std::string> & value) const;
    virtual void setStrings (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<std::string> & value) const;
    virtual void setIntegers (int objectId, int propertyId, const std::vector<int> & value) const;
    virtual void setIntegers (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<int> & value) const;
    virtual void setFloatings (int objectId, int propertyId, const std::vector<double> & value) const;
    virtual void setFloatings (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<double> & value) const;
    virtual void setBooleans (int objectId, int propertyId, const std::vector<bool> & value) const;
    virtual void setBooleans (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<bool> & value) const;

protected:
    friend class GameManager;
    
    GameComponent (const std::string & token, int identity)
    : Identifiable(token, identity)
    { }
    
    virtual void initialize ();
    
    std::vector<std::string> mAbilityTokens;
    std::vector<std::string> mActionTokens;
};
    
} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameComponent_h
