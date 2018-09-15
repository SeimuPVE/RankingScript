//
// Created by seimu on 07/09/18.
//

#ifndef RANKINGSCRIPT_RANKINGSCRIPT_H
#define RANKINGSCRIPT_RANKINGSCRIPT_H

#include <string>

#include "NewbieContestRanking.h"
#include "ConfigReader.h"


class RankingScript {
	private:
		ConfigReader configReader;
		NewbieContestRanking newbieContestRanking;

	public:
		RankingScript();
		RankingScript(const std::string &config_path);

		void setConfigPath(const std::string &config_path);

		void updateRanking();

		int getNewbieContestNumberOfUsers();
		NewbieContestUser getNewbieContestUserRanked(int i);
};


#endif //RANKINGSCRIPT_RANKINGSCRIPT_H
