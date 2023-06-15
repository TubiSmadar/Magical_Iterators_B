#include <iostream>
#include <string>
#include "sources/MagicalContainer.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_SUITE("Magical Container Methods:") {
    TEST_CASE("addElement() and size() methods") {
        MagicalContainer container;
        CHECK(container.size() == 0);
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);

        CHECK(container.size() == 3);
        
        container.addElement(7);
        container.addElement(2);

        CHECK(container.size() == 5);

        CHECK_THROWS(container.addElement(2));
    }

    TEST_CASE("removeElement() method") {
        MagicalContainer container;
        
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);

        container.removeElement(10);

        CHECK(container.size() == 2);
        
        CHECK_THROWS_AS(container.removeElement(7),runtime_error);

    }

    TEST_CASE("getElementAt() method") {
        MagicalContainer container;
        
        // Add elements to the container
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);

        CHECK(container.getElementAt(1) == 10);
        
        CHECK_THROWS_AS(container.getElementAt(5),runtime_error);
    }
}

TEST_SUITE("Iterators Methods:") {

    TEST_CASE("AscendingIterator:") {
        MagicalContainer container;  
        container.addElement(5);
        container.addElement(10); 
        container.addElement(3);
        MagicalContainer::AscendingIterator ascIter(container);
        auto it = ascIter.begin();
        CHECK_EQ(*it,3);
        CHECK_NOTHROW(++it);
        auto checkit = it;
        CHECK_EQ(*checkit,5);
        container.addElement(2);

        CHECK_NE(*(ascIter.end()),10);
        container.addElement(12);
        CHECK_NE(*(ascIter.end()),12);
        auto checkit2 = checkit;
        ++checkit;
        CHECK(checkit > checkit2);
        CHECK(checkit2 < checkit);
        string output;
        for( ;it != ascIter.end();++it){
            output = to_string(*it) + " ";
        }
        CHECK(output == "5 10 12 ");

    }

    TEST_CASE("PrimeIterator:") {
        MagicalContainer container;
        
        // Add elements to the container
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);
        MagicalContainer::PrimeIterator pIter(container);
        auto it = pIter.begin();
        CHECK_EQ(*it,3);
        CHECK_NOTHROW(++it);
        container.addElement(2);
        container.addElement(7);

        CHECK_NE(*(pIter.end()),10);
        container.addElement(11);
        CHECK_NE(*(pIter.end()),11);
        auto ch1 = it;
        auto ch2 = ++ch1;
        CHECK(ch1 < ch2);
        CHECK(ch2 > ch1);
        CHECK_EQ(*(++ch2),7);
        CHECK_NE(*(++ch2),10);
        ++ch2;
        CHECK_THROWS(++ch2);

        string output;
        for (  ;it != pIter.end(); ++it) {
            output += to_string(*it) + " ";
        }
        
        CHECK(output == "5 7 11 ");
    }
    TEST_CASE("SideCrossIterator:") {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(5);
        container.addElement(10); 
        container.addElement(3);
        MagicalContainer::SideCrossIterator sideIter(container);
        auto it = sideIter.begin();
        CHECK_EQ(*it,1);
        CHECK_NOTHROW(++it);
        auto checkit = it;
        CHECK_EQ(*checkit,10);
        container.addElement(2);
    //1,10,2,5,3
        CHECK_NE(*(sideIter.end()),3);
        auto checkit2 = checkit;
        ++checkit2;
        CHECK(checkit > checkit2);
        CHECK(checkit2 < checkit);
        string output;
        for(;it != sideIter.end();++it){
            output = to_string(*it) + " ";
        }
        CHECK(output == "10 2 5 3 ");       
        
    }
}
