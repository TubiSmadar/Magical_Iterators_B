#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, size_t index) : container(&container), index(index) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(&container), index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), index(other.index) {}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
{
    if(container != other.container) throw runtime_error("containers aren't equal!!");

    if(this != &other)
    {
        container = other.container;
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
{
    return index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
    return index != other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
{
    return index < other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
    return index > other.index;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    return (*container).container[index];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if( index == container->size()) throw runtime_error("Out of Bounds!!");
    ++index;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(*this);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return AscendingIterator(*container, (*container).size());
}