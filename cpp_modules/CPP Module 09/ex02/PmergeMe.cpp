#include "PmergeMe.hpp"

template<typename T>

void	swap(T it, int index)
{
	T start = it;
	std::advance(start, 1 - index);
	T end = start;
	std::advance(end, index);
	while (start != end)
	{
		T target = start;
		std::advance(target, index);
		std::iter_swap(start, target);
		start++;
	}
}

  template <typename T> static bool checkUpper(T iter1, T iter2) {
    return *iter1 < *iter2;
  }

  long jacobNumber(long n) {
  double jacob = round((pow(2.0, n + 1) + pow(-1.0, n)) / 3.0);
  return static_cast<long>(jacob + 0.5);
}

std::vector<size_t> jacobsthalSequence(size_t n) {
    std::vector<size_t> seq;
    seq.push_back(0);
    if (n == 0)
		return seq;
    seq.push_back(1);
    for (size_t i = 2; ; ++i) {
        size_t next = seq[i-1] + 2 * seq[i-2];
        if (next >= n)
			break;
        seq.push_back(next);
    }
    return seq;
}

template <typename T>

void insertSortedBinary(T &lst, int value) {
    if (lst.empty()) {
        lst.push_back(value);
        return;
    }

    typename T::iterator low = lst.begin();
    typename T::iterator high = lst.end();

    while (low != high) {
        typename T::iterator mid = low;
        int dist = std::distance(low, high) / 2;
        std::advance(mid, dist);

        if (*mid < value)
		{
            ++mid; 
            low = mid;
        }
		else
        	high = mid;
    }
    lst.insert(low, value);
}

template <typename T>

void jacobsthalInsertion(T &main, T &chein) {
    std::vector<int> cheinVec(chein.begin(), chein.end());
    size_t n = cheinVec.size();
    std::vector<size_t> seq = jacobsthalSequence(n);

    std::vector<bool> inserted(n, false);
    size_t insertedCount = 0;

    for (size_t i = 0; i < seq.size(); i++) {
        size_t idx = seq[i];
        if (idx < n && !inserted[idx]) {
            insertSortedBinary(main, cheinVec[idx]);
            inserted[idx] = true;
            insertedCount++;
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (!inserted[i]) {
            insertSortedBinary(main, cheinVec[i]);
            inserted[i] = true;
            insertedCount++;
        }
    }
}

template<typename T>

T fordJohnsonMainSort(T &container) {
	typedef typename T::iterator iter;

    if (container.size() <= 1)
        return container;
    if (container.size() == 2) {
       iter it = container.begin();
        int a = *it;
        ++it;
        int b = *it;
        container.clear();
        if (a < b) {
            container.push_back(a);
            container.push_back(b);
        } else {
            container.push_back(b);
            container.push_back(a);
        }
        return container;
    }

    T biggers;
    T smallers;
   iter it = container.begin();
    while (it != container.end()) {
        int a = *it++;
        if (it != container.end()) {
            int b = *it++;
            if (a > b) {
                biggers.push_back(a);
                smallers.push_back(b);
            } else {
                biggers.push_back(b);
                smallers.push_back(a);
            }
        }
		else
            biggers.push_back(a);
    }

    T sortedBiggers = fordJohnsonMainSort(biggers);

	jacobsthalInsertion(sortedBiggers, smallers);

	return sortedBiggers;
}

void	isSafe(std::string element)
{
	for (size_t i = 0; i < element.size(); i++)
	{
		if (!isdigit(element[i]))
			throw InvalidInput();
	}
	long num = atol(element.c_str());
	if (num > INT_MAX)
		throw std::out_of_range("number too high");
}

template <typename T>

void	printContainer(T &container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void	containerInit(std::list<int> &list, std::deque<int> &deque, char* line)
{
	std::stringstream ss(line);
	std::string element;
	int num;

	while (1)
	{
		if (!std::getline(ss, element, ' '))
			break;
		if (!element.empty())
		{
			isSafe(element);
			num = atoi(element.c_str());
			list.push_back(num);
			deque.push_back(num);
		}
	}
}

void	Start(std::list<int> &list, std::deque<int> &deque)
{

	std::cout << "Before: ";
	printContainer(list);
	clock_t l_start = std::clock();
	std::list<int> finalList = fordJohnsonMainSort(list);
	clock_t l_end = std::clock();
	double l_tPassed = static_cast<double>(l_end - l_start) / CLOCKS_PER_SEC;

	clock_t d_start = std::clock();
	std::deque<int> finaldeque = fordJohnsonMainSort(deque);
	clock_t d_end = std::clock();
	double d_tPassed = static_cast<double>(d_end - d_start) / CLOCKS_PER_SEC;

    std::cout << "After:  ";
	printContainer(finalList);
	
	std::cout << "Time to process a range of " <<  list.size() << " elements with std::list :  "  << std::fixed << std::setprecision(5) << l_tPassed <<  " us" << std::endl;
	std::cout << "Time to process a range of " <<  deque.size() << " elements with std::list :  "  << std::fixed << std::setprecision(5) << d_tPassed << " us" << std::endl;
}


const char *syntaxError::what() const throw()
{
	return ("syntax error !");
}

const char *InvalidInput::what() const throw()
{
	return ("please enter only positive intigers");
}

const char *numDuplicate::what() const throw()
{
	return ("there is a number duplicate");
}