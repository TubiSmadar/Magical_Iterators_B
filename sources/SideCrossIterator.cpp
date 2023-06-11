#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t index) : container(&container), index(index) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(&container), index(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), index(other.index) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
{
    if(container != other.container) throw runtime_error("containers aren't equal!!");

    if(this != &other)
    {
        container = other.container;
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
{
    return index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
{
    return index != other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
{
    return index < other.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
{
    return index > other.index;
}

int MagicalContainer::SideCrossIterator::operator*() 
{
    return (*(this->container)).container[index];
}


MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    // Check if the iterator is out of bounds
    if (index == (*container).container.size()) 
        throw runtime_error("Out of Bounds");

    size_t shortcut = (*container).container.size();
    size_t middle = shortcut / 2; 
    // If the pointer is at the middle element
    if (index == middle)
    {
        // Set the index to the last element
        index = shortcut;
        return *this;
    }
    // If the pointer is at the element before the middle element
    if (index < middle)
    {
        // Move the iterator to the corresponding element on the other side
        index = shortcut - index - 1;
        return *this;
    }

    // If the pointer is at the element after the middle element
    if (index > middle)
    {
        // Move the iterator to the corresponding element on the other side
        index = shortcut - index;
        return *this;
    }

    // All cases covered!!
    return *this;

}


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() 
{
	return SideCrossIterator((*this->container), 0);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{

    return SideCrossIterator(*this->container, (*container).container.size());
}