#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "data/AbstractTable.h"
#include "data/Table.hpp"
#include "data/File.h"
#include "../arena/data/EntityData.h"

using namespace file::data;

namespace file {
	class FileManager
	{
	public:
		FileManager() {
		}

		FileManager(FileManager const&) = delete;

		FileManager& operator=(FileManager const&) = delete;

		~FileManager();

		static FileManager& getInstance() {
			static FileManager instance;
			return instance;
		}

		void createTable(File csvFileType, AbstractTable* table);

		void addCSVFile(File csvFileType, std::string fileName);

		AbstractTable* getTable(File fileType);
	private:
		inline bool contains(File fileType) {
			auto it = this->tables.find(fileType);
			return it != this->tables.end();
		}

		std::unordered_map<File, AbstractTable*> tables;
	};
}

#endif