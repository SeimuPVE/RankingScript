//
// Created by seimu on 07/09/18.
//

#include "RankingScript.h"

RankingScript::RankingScript() {}

RankingScript::RankingScript(const std::string &config_path) {
	setConfigPath(config_path);
}

void RankingScript::setConfigPath(const std::string &config_path) {
	configReader.setConfigPath(config_path);
	std::vector<NewbieContestUser> users;

	while(configReader.goNextLine() != -1)
		users.push_back(NewbieContestUser(configReader.getUserName(), configReader.getURL()));

	newbieContestRanking.setUsers(users);
	newbieContestRanking.sortUsers();
}

void RankingScript::updateRanking() {
	newbieContestRanking.sortUsers();
}

int RankingScript::getNewbieContestNumberOfUsers() {
	return newbieContestRanking.getNumberOfUsers();
}

NewbieContestUser RankingScript::getNewbieContestUserRanked(int i) {
	return newbieContestRanking.getUserRanked(i);
}
