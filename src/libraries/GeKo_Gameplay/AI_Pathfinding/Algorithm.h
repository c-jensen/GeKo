#pragma once
#include <string>

template <class T>
/**This class is a template class for all possible path-finding-algorithms.*/
class Algorithm
{
	public:
		Algorithm(std::string name)
		{
			m_name = name;
		}
		~Algorithm(){}

		std::string getName()
		{
			return m_name;
		}

protected:
	std::string m_name;
};