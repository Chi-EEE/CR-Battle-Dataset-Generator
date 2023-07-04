#include "Table.h"

#include "CSV.h"
using namespace CSV::Reader;

namespace CSV
{
	template<typename T>
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
