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

void FileManager::createTable(File fileType, AbstractTable* table)
{
	this->tables.insert(std::make_pair(fileType, table));
}
