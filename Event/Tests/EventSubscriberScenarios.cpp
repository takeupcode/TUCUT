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
    subscriber.notify(parameter);
    
    VERIFY_TRUE(subscriber.notified());
    VERIFY_EQUAL(parameter, subscriber.property());
}

SCENARIO( Observer, "Operation/Direct", "unit,event", "AdvancedSubscriber can be notified directly." )
{
    AdvancedSubscriber subscriber;

    subscriber.reset();
    VERIFY_FALSE(subscriber.nameNotified());
    VERIFY_FALSE(subscriber.ageNotified());
    VERIFY_FALSE(subscriber.adultNotified());
    VERIFY_FALSE(subscriber.combinedAgeAndAdultNotified());

    // This is not the normal usage. This class is designed to be notified through an
    // Observable signal.
    subscriber.notify(AdvancedPublisher::nameProperty);
    VERIFY_TRUE(subscriber.nameNotified());
    VERIFY_FALSE(subscriber.ageNotified());
    VERIFY_FALSE(subscriber.adultNotified());
    VERIFY_FALSE(subscriber.combinedAgeAndAdultNotified());
    subscriber.reset();

    subscriber.notify(AdvancedPublisher::ageProperty);
    VERIFY_FALSE(subscriber.nameNotified());
    VERIFY_TRUE(subscriber.ageNotified());
    VERIFY_FALSE(subscriber.adultNotified());
    VERIFY_FALSE(subscriber.combinedAgeAndAdultNotified());
    subscriber.reset();

    subscriber.notify(AdvancedPublisher::adultProperty);
    VERIFY_FALSE(subscriber.nameNotified());
    VERIFY_FALSE(subscriber.ageNotified());
    VERIFY_TRUE(subscriber.adultNotified());
    VERIFY_FALSE(subscriber.combinedAgeAndAdultNotified());
    subscriber.reset();

    subscriber.notify(50, true);
    VERIFY_FALSE(subscriber.nameNotified());
    VERIFY_FALSE(subscriber.ageNotified());
    VERIFY_FALSE(subscriber.adultNotified());
    VERIFY_TRUE(subscriber.combinedAgeAndAdultNotified());
    subscriber.reset();
}
