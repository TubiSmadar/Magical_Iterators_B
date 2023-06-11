#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
namespace ariel
{
// MagicalContainer fatherclass
    class MagicalContainer
    {
    private:
        vector<int> container; // container for the elements
        vector<int*> primeContainer; // container of pointers of prime numbers
        
    public:
        MagicalContainer() = default; // default constructor

        ~MagicalContainer(); // destructor

        void addElement(int element); // add element without duplicates
        
        void removeElement(int element);

        size_t size() const;
        
        bool isPrime(int num);

        //AscendingIterator subclass
        class AscendingIterator
        {
            private:
                MagicalContainer *container; // the containter

                size_t index; // the index of the container element

            public:
                AscendingIterator(MagicalContainer & container, size_t index); // constructor with 2 arguments, container and index.
                
                AscendingIterator(MagicalContainer & container); // constructor with 1 argument.

                AscendingIterator(const AscendingIterator& other); // copy constructor

                ~AscendingIterator(){}; //default destructor

                // for tidy
                AscendingIterator(AscendingIterator&& other) noexcept; // ,move constructor        
                AscendingIterator& operator=(AscendingIterator&& other) noexcept; // copy assigment operator
                
                AscendingIterator begin(); // returns first element

                AscendingIterator end(); // returns last element

                AscendingIterator& operator=(const AscendingIterator& other); // copy assignment operator
                
                // bool operators
                bool operator==(const AscendingIterator & other) const;
                bool operator!=(const AscendingIterator & other) const;
                bool operator>(const AscendingIterator & other) const;
                bool operator<(const AscendingIterator & other) const;
                
                AscendingIterator &operator++();  // iterates over the container element

                int operator*() const; // dereference - return element at current index

        };

        // sidecross subclass
        class SideCrossIterator
        {
        private:
                MagicalContainer *container; // the containter

                size_t index; // the index of the container element

        public:

            //constructors,destructor
            SideCrossIterator(MagicalContainer& container, size_t index);
            SideCrossIterator(MagicalContainer& container);
            SideCrossIterator(const SideCrossIterator& other); 
            ~SideCrossIterator(){};


            // for tidy
            SideCrossIterator(SideCrossIterator&& other) noexcept;
            SideCrossIterator& operator=(SideCrossIterator&& other) noexcept;
            
            // returns the beggining element and the last element in the container.
            SideCrossIterator begin();
            SideCrossIterator end();

            //bool operators
            SideCrossIterator& operator=(const SideCrossIterator& other);
            bool operator==(const SideCrossIterator & other) const;
            bool operator!=(const SideCrossIterator & other) const;
            bool operator>(const SideCrossIterator & other) const;
            bool operator<(const SideCrossIterator & other) const;

            //iterates over the container
            SideCrossIterator& operator++();

            // dereference - return element at current index
            int operator*();
        };

        // PrimeIterator subclass
        class PrimeIterator
        {
        private:
            MagicalContainer *container; // the container
            size_t primeIndex; // index

        public:
            //constructors , destructor
            PrimeIterator(MagicalContainer&, size_t);
            PrimeIterator(MagicalContainer&);
            PrimeIterator(const PrimeIterator& ); 
            ~PrimeIterator(){};


            //for tidy
            PrimeIterator(PrimeIterator&& ) noexcept; 
            PrimeIterator& operator=(PrimeIterator&&) noexcept;

            //returns beggining and end of the container elements
            PrimeIterator begin();
            PrimeIterator end();

            // move assigment operator
            PrimeIterator &operator=(const PrimeIterator &);

            //bool operators
            bool operator==(const PrimeIterator &) const;
            bool operator!=(const PrimeIterator &) const;
            bool operator>(const PrimeIterator &) const;
            bool operator<(const PrimeIterator &) const;

            //iterates over the container
            PrimeIterator& operator++();  

            // dereference - return element at current index
            int operator*() const;
        };
    };

}
