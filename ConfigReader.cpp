//
// Created by seimu on 07/09/18.
//

#include "ConfigReader.h"

ConfigReader::ConfigReader() {}

ConfigReader::ConfigReader(const std::string &config_path) {
	setConfigPath(config_path);
}

void ConfigReader::setConfigPath(const std::string &config_path) {
	std::ifstream file(config_path.c_str());
	current_line = -1;

	for(std::string current_line; std::getline(file, current_line);)
		lines.push_back(current_line);

	file.close();
}

int ConfigReader::goNextLine() {
	current_line++;

	if(current_line >= lines.size())
		return -1;
	else
		return current_line;
}

std::vector<std::string> ConfigReader::split(std::string sentence, char splitter) {
	std::vector<std::string> splitted_tab;
	std::string current_part = "";
	int i = 0;

	while(sentence[i] != '\0') {
		if(sentence[i] != splitter) {
			current_part += sentence[i];
			i++;
		}
		else {
			splitted_tab.push_back(current_part);
			current_part = "";
			i++;
		}
	}

	splitted_tab.push_back(current_part);
	return splitted_tab;
}

std::string ConfigReader::getWebsite() {
	return split(lines[current_line], SPLITTER)[0];
}

std::string ConfigReader::getUserName() {
	return split(lines[current_line], SPLITTER)[1];
}

std::string ConfigReader::getURL() {
	return split(lines[current_line], SPLITTER)[2];
}
