#include "MagicalContainer.hpp"
using namespace ariel;

bool MagicalContainer::isPrime(int num)
{
    if(num < 2) return false;
    
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}

// compares the numbers, helper function for good complexity
bool pointerSort(int *numA, int *numB)
{
    return *numA < *numB;
}

MagicalContainer::~MagicalContainer()
{
    for (size_t i = 0; i < primeContainer.size(); i++)
    {
        delete primeContainer[i];
    }
    
}

//add element to the containter and if needed add to prime container
void MagicalContainer::addElement(int element)
{
    // find where do i need to insert the element
    auto it = lower_bound(container.begin(), container.end(), element);
    
    // do the insertion
    container.insert(it, element);

    // check prime to add to the prime container
    if (isPrime(element))
    {
        // create a new pointer for the element
        int* primeNum = new int(element);
        
        // find where do i need to insert the element
        auto primeIt = lower_bound(primeContainer.begin(), primeContainer.end(), primeNum, pointerSort);
        
        // do the insertion
        primeContainer.insert(primeIt, primeNum);
    }
}

void MagicalContainer::removeElement(int element)
{
    // indicator if element we want to remove is present
    bool flag = false;

    auto it = container.begin();
    while( it != container.end())
    {
        if(*it == element)
        {
            it = container.erase(it);
            flag = true;
            break;
        }
        ++it;
    }
    
    // error if needed.
    if(!flag) throw runtime_error("Element is not in the container!");
}

size_t MagicalContainer::size() const
{
    return container.size();
}