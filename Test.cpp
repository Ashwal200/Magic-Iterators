#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>
using namespace ariel;
using namespace std;


// Test AscendingIterator
TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(2);
    container.addElement(5);
    container.addElement(4);
    container.addElement(1);

// Check if the itarator go throw on the array
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(*it == 5);
        


}

// Test SideCrossIterator
TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    
// Check if the itarator go throw on the array
	MagicalContainer::SideCrossIterator it(container);
	CHECK(*it == 1);
	++it;
	CHECK(*it == 5);
	++it;
	CHECK(*it == 2);
	++it;
	CHECK(*it == 4);
	++it;
	CHECK(*it == 3);


}

// Test PrimeIterator
TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(110);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(7);
    container.addElement(15);
    container.addElement(25);
    container.addElement(13);
    container.addElement(20);
    CHECK(container.size() == 10);
    
    
// Check if the itarator go throw on the array
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 13);
	
        



}


TEST_CASE("Adding element") {
    MagicalContainer container;
        container.addElement(11);
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        CHECK(container.size() == 4);
	CHECK_FALSE(container.size() != 4);
}

TEST_CASE("Removing element") {
    MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        CHECK_NOTHROW(container.removeElement(1));
        CHECK(container.size() == 1);
        container.addElement(11);
        container.addElement(22);
        CHECK(container.size() == 3);
        // do nothing if the number isn't exist
        CHECK_NOTHROW(container.removeElement(3));
        CHECK(container.size() == 3);
        CHECK_FALSE(container.size() != 3);
}


// Test for operators in AscendingIterator
TEST_CASE("operators") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);

        CHECK_FALSE(it1 < it2);
        CHECK_FALSE(it1 > it2);
        
        CHECK(it1 == it2);
        CHECK_FALSE(it1 != it2);
    }

// Test for operators in SideCrossIterator
TEST_CASE("operators") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);

        CHECK_FALSE(it1 < it2);
        CHECK_FALSE(it1 > it2);
        
        CHECK(it1 == it2);
        CHECK_FALSE(it1 != it2);
    }

// Test for operators in PrimeIterator
TEST_CASE("operators") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);

        CHECK_FALSE(it1 < it2);
        CHECK_FALSE(it1 > it2);
        
        CHECK(it1 == it2);
        CHECK_FALSE(it1 != it2);
       
    }
    
// Test for begin and end 

// Test for AscendingIterator
TEST_CASE("begin and end") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);


        MagicalContainer::AscendingIterator it(container);
        CHECK(*it.begin() == 1);
        CHECK(*it.end() == 2);
        
	
    }

// Test for SideCrossIterator
TEST_CASE("begin and end") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);

        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it.begin() == 1);
        CHECK(*it.end() == 2);
    }

// Test for PrimeIterator
TEST_CASE("begin and end") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);

        MagicalContainer::PrimeIterator it(container);
        CHECK(*it.begin() == 1);
        CHECK(*it.end() == 2);
    }



