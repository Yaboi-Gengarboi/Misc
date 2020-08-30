// File_Manager.h
// Justyn Durnford
// Created on 8/24/2020
// Last updated on 8/24/2020

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <fstream>
#include <string>
#include <vector>

//
//
//
class File_Manager
{
	std::ifstream _fin;
	std::ofstream _fout;
	std::vector<std::string> _lines;

	bool doesFileExist() const;

	void readFile();
	void writeFile();

	std::string range_substr(const std::string& str, const std::size_t& begin, const std::size_t& end) const;

	public:

	File_Manager();
	File_Manager(const char* filestr);
	File_Manager(const std::string& filestr);

	~File_Manager();

	std::string readLine(const std::size_t& index) const;

	void writeLine(const char* line, const std::size_t& index);
	void writeLine(const std::string& line, const std::size_t& index);

	void insertLine(const char* line, const std::size_t& index);
	void insertLine(const std::string& line, const std::size_t& index);

	void insertToLine(const char* line, const std::size_t& index);
	void insertToLine(const std::string& line, const std::size_t& index);

	std::vector<std::string>& allLines() const;
};

#endif // FILE_MANAGER_H