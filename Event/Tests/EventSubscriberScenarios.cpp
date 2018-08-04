//
//  EventSubscriberScenarios.cpp
//  TestTUCUT
//
//  Created by Wahid Tanner on 6/25/13.
//  Copyright © 2013 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "SimpleSubscriber.h"
#include "AdvancedSubscriber.h"

using namespace TUCUT;

SCENARIO( Observer, "Construction/Normal", "unit,event", "Subscriber derived classes can be constructed." )
{
    SimpleSubscriber subscriber1;
    AdvancedSubscriber subscriber2;
}

SCENARIO( Observer, "Operation/Direct", "unit,event", "SimpleSubscriber can be notified directly." )
{
    SimpleSubscriber subscriber;
    
    // This is not the normal usage. This class is designed to be notified through an
    // Observable signal.
    std::string parameter = "Name";
    subscriber.notify(3, parameter);
    
    VERIFY_TRUE(subscriber.notified());
    VERIFY_EQUAL(3, subscriber.id());
    VERIFY_EQUAL(parameter, subscriber.property());
}

SCENARIO( Observer, "Operation/Direct", "unit,event", "AdvancedSubscriber can be notified directly." )
{
    AdvancedSubscriber subscriber;

    subscriber.resetData();
    VERIFY_EQUAL(0, subscriber.id());
    VERIFY_FALSE(subscriber.nameNotified());
    VERIFY_FALSE(subscriber.ageNotified());
    VERIFY_FALSE(subscriber.adultNotified());
    VERIFY_FALSE(subscriber.combinedAgeAndAdultNotified());

    // This is not the normal usage. This class is designed to be notified through an
    // Observable signal.
    subscriber.notify(1, AdvancedPublisher::nameProperty);
    VERIFY_EQUAL(1, subscriber.id());
    VERIFY_TRUE(subscriber.nameNotified());
    VERIFY_FALSE(subscriber.ageNotified());
    VERIFY_FALSE(subscriber.adultNotified());
    VERIFY_FALSE(subscriber.combinedAgeAndAdultNotified());
    
    subscriber.resetData();
    subscriber.notify(2, AdvancedPublisher::ageProperty);
    VERIFY_EQUAL(2, subscriber.id());
    VERIFY_FALSE(subscriber.nameNotified());
    VERIFY_TRUE(subscriber.ageNotified());
    VERIFY_FALSE(subscriber.adultNotified());
    VERIFY_FALSE(subscriber.combinedAgeAndAdultNotified());
    
    subscriber.resetData();
    subscriber.notify(3, AdvancedPublisher::adultProperty);
    VERIFY_EQUAL(3, subscriber.id());
    VERIFY_FALSE(subscriber.nameNotified());
    VERIFY_FALSE(subscriber.ageNotified());
    VERIFY_TRUE(subscriber.adultNotified());
    VERIFY_FALSE(subscriber.combinedAgeAndAdultNotified());
    
    subscriber.resetData();
    subscriber.notify(4, 50, true);
    VERIFY_EQUAL(4, subscriber.id());
    VERIFY_FALSE(subscriber.nameNotified());
    VERIFY_FALSE(subscriber.ageNotified());
    VERIFY_FALSE(subscriber.adultNotified());
    VERIFY_TRUE(subscriber.combinedAgeAndAdultNotified());
}
