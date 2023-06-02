#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
using namespace std;
namespace ariel{

class MagicalContainer {
private:
    

public:
    vector<int> elements;
    void addElement(int element) {
        elements.push_back(element);
    }

    void removeElement(int element) {
        int flage = 1;
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                flage = 0;
                break;
            }
        }
        if(flage == 0)
        {
             throw runtime_error("This element isn't in the container");
        }
    }

    int size() const {
        return int(elements.size());
    }

    class AscendingIterator {
    private:
        MagicalContainer& container;
        vector<int>::iterator it;
    public:
        AscendingIterator(MagicalContainer& cont)
            : container(cont)
            {
                init_sort();
                it = container.elements.begin();
            }

        void init_sort()
        {
            sort(container.elements.begin() , container.elements.end());
        }

        
        bool operator==(const AscendingIterator& other) const {
            return &container == &other.container && &container.elements == &other.container.elements;
        }

        
        bool operator!=(const AscendingIterator& other) const {
            return !(*this == other);
        }
        
        bool operator>(const AscendingIterator& other) const 
        {
            return container.size() > other.container.size();
        }

        bool operator<(const AscendingIterator& other) const 
        {
            return container.size() < other.container.size();
        }

        
        int& operator*() const {
            return *it;
        }

        
        void operator++() {
            ++it;
        }
        

        vector<int>::iterator begin () const {
            vector<int>::iterator itBegin = container.elements.begin();
            return itBegin;
        }

        
        vector<int>::iterator end() const {
            vector<int>::iterator itEnd = container.elements.end();
            return itEnd;
        }
    };

    class SideCrossIterator {
    private:
        MagicalContainer& container;
        vector<int>::iterator it;
    public:
        SideCrossIterator(MagicalContainer& cont)
            : container(cont) 
            {
                initCross();
                it = container.elements.begin();
            }

        void initCross()
        {
            vector<int> temp;
            size_t left = 0;
            size_t right = container.elements.size() - 1;
            
            for(size_t i = 0; i < container.elements.size(); i++)
            {
                if (i%2 == 0)
                {
                    temp.emplace_back(container.elements.at(left));
                    left++;
                }
                else 
                {
                   temp.emplace_back(container.elements.at(right));
                   right--; 
                }
            }

            container.elements = temp;
        }
        
        bool operator==(const SideCrossIterator& other) const 
        {
            return &container == &other.container;
        }

        
        bool operator!=(const SideCrossIterator& other) const 
        {
            return !(*this == other);
        }
        
        bool operator>(const SideCrossIterator& other) const 
        {
            return container.size() > other.container.size();
        }

        bool operator<(const SideCrossIterator& other) const 
        {
            return container.size() < other.container.size();
        }

        int& operator*() const 
        {
            return *it;
        }

        void operator++() 
        {
            ++it;
        }

        vector<int>::iterator begin () const 
        {
            vector<int>::iterator itBegin = container.elements.begin();
            return itBegin;
        }

        vector<int>::iterator end() const 
        {
            vector<int>::iterator itEnd = container.elements.end();
            return itEnd;
        }

    };

    class PrimeIterator {
    private:
        MagicalContainer& container;
        vector<int>::iterator it;
        static bool isPrime(int number) {
            if (number <= 1)
            {
                return false;
            }

            int sqr = int(sqrt(number));
            for (int i = 2; i <= sqr; i++) {
                if (number % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

    public:
        PrimeIterator(MagicalContainer& cont)
            : container(cont) 
            {
                prime_init();
                it = container.elements.begin();
            }
	

        void prime_init(){
            vector<int> temp;
            for(auto num : container.elements){
                if (isPrime(num))
                {
                    temp.emplace_back(num);
                }
            }
            container.elements = temp;
        }

        bool operator==(const PrimeIterator& other) const {
            return &container == &other.container;
        }

        bool operator!=(const PrimeIterator& other) const {
            return !(*this == other);
        }
        
        bool operator>(const PrimeIterator& other) const 
        {
            return container.size() > other.container.size();
        }

        bool operator<(const PrimeIterator& other) const 
        {
            return container.size() < other.container.size();
        }

        int& operator*() const {
            return *it;
        }

        void operator++() {
            ++it;
        }
        
        vector<int>::iterator begin () const {
            vector<int>::iterator itBegin = container.elements.begin();
            return itBegin;
        }

        vector<int>::iterator end() const {
            vector<int>::iterator itEnd = container.elements.end();
            return itEnd;
        }
    };
};

}
