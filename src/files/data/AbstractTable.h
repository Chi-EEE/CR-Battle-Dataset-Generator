#ifndef ABSTRACTTABLE_H
#define ABSTRACTTABLE_H

#pragma once


namespace file::data
{
	class AbstractTable
	{
	public:
		virtual ~AbstractTable() {}

		virtual void insertCSV(std::string fileName) = 0;
	private:

	};
}

#endif