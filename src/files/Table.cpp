#include "Table.h"

#include "CSV.h"
using namespace CSV::Reader;

namespace CSV
{
	template<IsData T>
	Table<T>::Table()
	{
	}

	template<IsData T>
	void Table<T>::insert(std::string fileName)
	{
		std::ifstream file(fileName);
		CSVIterator csvIterator(file);
		++csvIterator;
		++csvIterator;
		for (; csvIterator != CSVIterator(); ++csvIterator)
		{
			this->entries.emplace_back(T(*csvIterator));
		}
	}

	template<IsData T>
	T Table<T>::getData(std::string name)
	{
		for (T entry : this->entries)
		{
			if (entry[0] == name)
			{
				return entry;
			}
		}
	}
}