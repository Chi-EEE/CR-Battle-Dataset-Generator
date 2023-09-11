#include "FileManager.h"

FileManager::~FileManager() {
	for (auto table = this->tables.begin(); table != this->tables.end(); ++table)
	{
		delete (*table).second;
	}
	this->tables.clear();
}

AbstractTable* FileManager::getTable(File fileType)
{
	if (contains(fileType))
	{
		return this->tables[fileType];
	}
	else
	{
		std::cerr << "Unable to find the File Enum for " << fileType;
		return nullptr;
	}
}

void FileManager::addCSVFile(File fileType, std::string fileName)
{
	if (contains(fileType))
	{
		this->tables[fileType]->insertCSV(fileName);
	}
	else
	{
		std::cerr << "Unable to find the File Enum for " << fileType;
	}
}

void FileManager::addTomlFile(File fileType, std::string fileName)
{
	if (contains(fileType))
	{
		this->tables[fileType]->insertToml(fileName);
	}
	else
	{
		std::cerr << "Unable to find the File Enum for " << fileType;
	}
}

template<typename T>
inline void FileManager::createTable(File fileType, Table<T> table)
{
	this->tables.insertCSV(std::make_pair(fileType, table));
}
