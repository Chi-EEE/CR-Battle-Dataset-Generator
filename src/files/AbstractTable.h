#ifndef ABSTRACTTABLE_H
#define ABSTRACTTABLE_H

#pragma once


namespace CSV
{
	class AbstractTable
	{
	public:
		virtual ~AbstractTable() {}

		virtual void insert(std::string fileName) = 0;
	private:

	};
}

#endif