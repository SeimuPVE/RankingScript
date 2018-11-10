//
// Created by seimu on 07/09/18.
//

#ifndef RANKINGSCRIPT_RANKINGPRINTER_H
#define RANKINGSCRIPT_RANKINGPRINTER_H

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

#include "RankingScript.h"


class RankingPrinter {
	private:
		RankingScript rankingScript;

	public:
		RankingPrinter();
		RankingPrinter(const std::string &config_path);

		void setConfigPath(const std::string &config_path);

		void print();
		void printContinually(int minutes);

		void printNewbieContest();
};


#endif //RANKINGSCRIPT_RANKINGPRINTER_H
