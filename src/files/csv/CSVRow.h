#ifndef CSVROW_H
#define CSVROW_H

#pragma once

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string_view>

namespace file::_csv
{
	// https://stackoverflow.com/a/1120224
	class CSVRow
	{
	public:
		std::string_view operator[](std::size_t index) const
		{
			return std::string_view(&m_line[m_data[index * 2] + 1], m_data[index * 2 + 1] - (m_data[index * 2] + 1));
		}
		std::size_t size() const
		{
			return m_data.size() - 1;
		}
		void readNextRow(std::istream& str)
		{
			m_line.clear();
			std::getline(str, m_line);

			m_data.clear();
			m_data.emplace_back(-1);
			std::string::size_type pos = 0;

			bool in_quotes = false;
			bool was_quotes = false;
			while (pos < m_line.size()) {
				if (m_line[pos] == '\"')
				{
					if (!in_quotes)
						m_data.pop_back();
					m_data.emplace_back(pos);
					was_quotes = in_quotes;
					in_quotes = !in_quotes;
				}
				else if (!in_quotes) {
					if (m_line[pos] == ',')
					{
						if (was_quotes)
							was_quotes = !was_quotes;
						else
							m_data.emplace_back(pos);
						m_data.emplace_back(pos);
					}
				}
				++pos;
			}
			m_data.emplace_back(m_line.size());
		}
	private:
		std::string         m_line;
		std::vector<int>    m_data;
	};

	inline std::istream& operator>>(std::istream& str, CSVRow& data)
	{
		data.readNextRow(str);
		return str;
	}
}

#endif