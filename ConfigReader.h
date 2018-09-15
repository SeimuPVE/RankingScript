//
// Created by seimu on 07/09/18.
//

#ifndef RANKINGSCRIPT_CONFIGREADER_H
#define RANKINGSCRIPT_CONFIGREADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define SPLITTER ';'


class ConfigReader {
	private:
		std::ifstream file;
		std::vector<std::string> lines;
		int current_line;

public:
	ConfigReader();
	ConfigReader(const std::string &config_path);

	void setConfigPath(const std::string &config_path);

	int goNextLine();
	std::vector<std::string> split(std::string sentence, char splitter);

	std::string getWebsite();
	std::string getUserName();
	std::string getURL();
};


#endif //RANKINGSCRIPT_CONFIGREADER_H
