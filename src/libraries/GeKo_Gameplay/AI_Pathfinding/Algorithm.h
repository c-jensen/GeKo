#pragma once
#include <string>

template <class T>
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
		
		//T* startAlgorithm(T* startNode, T* endNode);
		

protected:
	std::string m_name;
};