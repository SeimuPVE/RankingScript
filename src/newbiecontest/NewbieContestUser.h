//
// Created by seimu on 07/09/18.
//

#ifndef RANKINGSCRIPT_NEWBIECONTESTSTATS_H
#define RANKINGSCRIPT_NEWBIECONTESTSTATS_H

#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>

#define CHALLENGE "Challenges :"
#define POINTS "Points :"
#define KINGDOM "Royaume :"
#define POSITION "Position :"


class NewbieContestUser {
	private:
		std::vector<std::string> code_lines;

		std::string user_name;
		std::string user_url;

		std::string activity; // TODO : add it later.
		unsigned int points;
		std::string kingdom;
		unsigned int position;
		unsigned int total_members;
	double top_percentage;

	public:
		NewbieContestUser(const std::string &user_name, const std::string &user_url);

		static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

		void update();

		std::string &getUserName();
		const std::string &getUserURL() const;
		unsigned int getPoints();
		std::string &getKingdom();
		unsigned int getPosition();
		unsigned int getTotalMembers();
		double getTopPercentage();
};


#endif //RANKINGSCRIPT_NEWBIECONTESTSTATS_H
