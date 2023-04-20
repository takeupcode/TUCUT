//  EventPublisherScenarios.cpp
//  TUCUT/Notify (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2013-06-26.
//  Copyright © Take Up Code, Inc.
//
#include <memory>
#include <string>

#include "../../Test/Test.h"

#include "SimplePublisher.h"
#include "SimpleSubscriber.h"
#include "AdvancedPublisher.h"
#include "AdvancedSubscriber.h"

using namespace TUCUT;

SCENARIO( Observable, "Construction/Normal", "unit,event", "Publisher derived classes can be constructed." )
{
    SimplePublisher simple;
    AdvancedPublisher advanced("testName", 10);
}

SCENARIO( Observable, "Operation/Normal", "unit,event", "SimplePublisher can notify subscriber." )
{
    SimplePublisher publisher;

    std::shared_ptr<SimpleSubscriber> subscriber(new SimpleSubscriber());

    publisher.propertyChanged()->connect("test", subscriber);

    std::string parameter = "Name";
    publisher.propertyChanged()->signal(parameter);

    VERIFY_TRUE(subscriber->notified());
    VERIFY_EQUAL(1, subscriber->id());
    VERIFY_EQUAL(parameter, subscriber->property());
}

SCENARIO( Observable, "Operation/Normal", "unit,event", "AdvancedPublisher can notify subscriber." )
{
    AdvancedPublisher publisher("testName", 10);

    std::shared_ptr<AdvancedSubscriber> subscriber(new AdvancedSubscriber());

    publisher.propertyChanged()->connect("test", subscriber);

    publisher.setName("NewName");
    VERIFY_EQUAL(1, subscriber->id());
    VERIFY_TRUE(subscriber->nameNotified());
    VERIFY_FALSE(subscriber->ageNotified());
    VERIFY_FALSE(subscriber->adultNotified());
    VERIFY_FALSE(subscriber->combinedAgeAndAdultNotified());

    subscriber->resetData();
    publisher.setAge(11);
    VERIFY_EQUAL(1, subscriber->id());
    VERIFY_FALSE(subscriber->nameNotified());
    VERIFY_TRUE(subscriber->ageNotified());
    VERIFY_FALSE(subscriber->adultNotified());
    VERIFY_FALSE(subscriber->combinedAgeAndAdultNotified());

    publisher.ageAndAdult()->connect("test", subscriber);

    subscriber->resetData();
    publisher.setAge(30);
    VERIFY_EQUAL(2, subscriber->id());
    VERIFY_FALSE(subscriber->nameNotified());
    VERIFY_TRUE(subscriber->ageNotified());
    VERIFY_TRUE(subscriber->adultNotified());
    VERIFY_TRUE(subscriber->combinedAgeAndAdultNotified());
}
