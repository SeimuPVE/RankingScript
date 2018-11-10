//
// Created by seimu on 07/09/18.
//

#include "NewbieContestUser.h"


bool contains(std::string container, std::string word) {
	int i, j;

	for(i = 0; i < container.length(); i++)
		if(container.substr(i, word.length()) == word)
			return true;

	return false;
}

NewbieContestUser::NewbieContestUser(const std::string &user_name, const std::string &user_url) : user_name(user_name), user_url(user_url) {
	update();
}

size_t NewbieContestUser::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

void NewbieContestUser::update() {
	CURL *curl;
	std::string page_code;
	std::string current_line = "";
	int i = 0;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_COOKIE, "admin=0; PHPSESSID=8c50a2302ff86d37586909742dd8501e; SMFCookie89=a%3A4%3A%7Bi%3A0%3Bs%3A5%3A%2258785%22%3Bi%3A1%3Bs%3A40%3A%22385802116a5048456398632113f74c7e998a6eeb%22%3Bi%3A2%3Bi%3A1723223392%3Bi%3A3%3Bi%3A0%3B%7D;");
		curl_easy_setopt(curl, CURLOPT_URL, user_url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &page_code);
	}

	code_lines.clear();
	curl_easy_perform(curl);

	while(page_code[i] != '\0') {
		if(page_code[i] == '\n') {
			current_line += '\0';
			code_lines.push_back(current_line);

			current_line.clear();
		}
		else
			current_line += page_code[i];

		i++;
	}

	page_code.clear();
	curl_easy_cleanup(curl);
}

std::string &NewbieContestUser::getUserName() {
	return user_name;
}

const std::string &NewbieContestUser::getUserURL() const {
	return user_url;
}

unsigned int NewbieContestUser::getPoints() {
	unsigned int current_line = 0, i = 0;
	points = 0;

	// First, we go in the CHALLENGE part.
	while(!contains(code_lines[current_line], CHALLENGE))
		current_line++;

	// While it does'nt contain POINTS we increase.
	while(!contains(code_lines[current_line], POINTS))
		current_line++;

	// While it's not a number we increase.
	while(code_lines[current_line][i] < '0' || code_lines[current_line][i] > '9')
		i++;

	// And we get the number of points.
	while(code_lines[current_line][i] >= '0' && code_lines[current_line][i] <= '9') {
		points *= 10;
		points += code_lines[current_line][i] - '0';

		i++;
	}

	return points;
}

std::string &NewbieContestUser::getKingdom() {
	unsigned int current_line = 0, i = 0;
	kingdom.clear();

	// First, we go in the CHALLENGE part.
	while(!contains(code_lines[current_line], CHALLENGE))
		current_line++;

	// While it does'nt contain KINGDOM we increase.
	while(!contains(code_lines[current_line], KINGDOM))
		current_line++;

	// While it's not the end of KINGDOM we increase.
	while(code_lines[current_line][i] != ':')
		i++;

	// While it's not the end of </span> we increase.
	while(code_lines[current_line][i] != '>')
		i++;

	// We delete the space.
	i += 2;

	// And we get the kingdom.
	while(code_lines[current_line][i] != '<') {
		kingdom += code_lines[current_line][i];
		i++;
	}

	return kingdom;
}

unsigned int NewbieContestUser::getPosition() {
	unsigned int current_line = 0, i = 0;
	position = 0;

	// First, we go in the CHALLENGE part.
	while(!contains(code_lines[current_line], CHALLENGE))
		current_line++;

	// While it does'nt contain POINTS we increase.
	while(!contains(code_lines[current_line], POSITION))
		current_line++;

	// While it's not a number we increase.
	while(code_lines[current_line][i] < '0' || code_lines[current_line][i] > '9')
		i++;

	// And we get the number of points.
	while(code_lines[current_line][i] >= '0' && code_lines[current_line][i] <= '9') {
		position *= 10;
		position += code_lines[current_line][i] - '0';

		i++;
	}

	return position;
}

unsigned int NewbieContestUser::getTotalMembers() {
	unsigned int current_line = 0, i = 0;
	total_members = 0;

	// First, we go in the CHALLENGE part.
	while(!contains(code_lines[current_line], CHALLENGE))
		current_line++;

	// While it does'nt contain POINTS we increase.
	while(!contains(code_lines[current_line], POSITION))
		current_line++;

	// While it's not a number we increase.
	while(code_lines[current_line][i] < '0' || code_lines[current_line][i] > '9')
		i++;

	// We skip the user position.
	while(code_lines[current_line][i] != '/')
		i++;
	while(code_lines[current_line][i] < '0' || code_lines[current_line][i] > '9')
		i++;

	// And we get the number of points.
	while(code_lines[current_line][i] >= '0' && code_lines[current_line][i] <= '9') {
		total_members *= 10;
		total_members += code_lines[current_line][i] - '0';

		i++;
	}

	return total_members;
}

double NewbieContestUser::getTopPercentage() {
	top_percentage = (double) getPosition() / (double) getTotalMembers() * 100;
	return top_percentage;
}
