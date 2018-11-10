//
// Created by seimu on 07/09/18.
//

#include "RankingPrinter.h"

RankingPrinter::RankingPrinter() {}

RankingPrinter::RankingPrinter(const std::string &config_path) {
	setConfigPath(config_path);
}

void RankingPrinter::setConfigPath(const std::string &config_path) {
	rankingScript.setConfigPath(config_path);
}

void RankingPrinter::print() {
	rankingScript.updateRanking();
	printNewbieContest();
}

void RankingPrinter::printContinually(int minutes) {
	while(true) {
		print();
		std::this_thread::sleep_for(std::chrono::milliseconds(minutes * 1000 * 60));
	}
}

void RankingPrinter::printNewbieContest() {
	int i, j;

	std::cout << "******************************************************************************" << std::endl;
	std::cout << "******************************************************************************" << std::endl;
	std::cout << "****  _   _               _     _       ____            _            _    ****" << std::endl;
	std::cout << "**** | \\ | | _____      _| |__ (_) ___ / ___|___  _ __ | |_ ___  ___| |_  ****" << std::endl;
	std::cout << "**** |  \\| |/ _ \\ \\ /\\ / / '_ \\| |/ _ \\ |   / _ \\| '_ \\| __/ _ \\/ __| __| ****" << std::endl;
	std::cout << "**** | |\\  |  __/\\ V  V /| |_) | |  __/ |__| (_) | | | | ||  __/\\__ \\ |_  ****" << std::endl;
	std::cout << "**** |_| \\_|\\___| \\_/\\_/ |_.__/|_|\\___|\\____\\___/|_| |_|\\__\\___||___/\\__| ****" << std::endl;
	std::cout << "****                                                                      ****" << std::endl;
	std::cout << "******************************************************************************" << std::endl;
	std::cout << "******************************************************************************" << std::endl;
	std::cout << "" << std::endl;
	std::cout << " Nom               | Points          | Royaume            | Top              " << std::endl;
	std::cout << "___________________|_________________|____________________|___________________" << std::endl;

	for(i = 0; i < rankingScript.getNewbieContestNumberOfUsers(); i++) {
		std::cout << rankingScript.getNewbieContestUserRanked(i).getUserName();
		for(j = rankingScript.getNewbieContestUserRanked(i).getUserName().size(); j < 19; j++)
			std::cout << " ";
		std::cout << "|";

		std::cout << rankingScript.getNewbieContestUserRanked(i).getPoints();
		for(j = std::to_string(rankingScript.getNewbieContestUserRanked(i).getPoints()).size(); j < 17; j++)
			std::cout << " ";
		std::cout << "|";

		std::cout << rankingScript.getNewbieContestUserRanked(i).getKingdom();
		for(j = rankingScript.getNewbieContestUserRanked(i).getKingdom().size(); j < 20; j++)
			std::cout << " ";
		std::cout << "|";

		std::cout << rankingScript.getNewbieContestUserRanked(i).getTopPercentage();
		std::cout << std::endl;
	}
}
