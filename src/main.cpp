#include <iostream>
#include "ranking/RankingPrinter.h"


int main() {
	RankingPrinter rankingPrinter("/opt/RankingConfig.cfg");
//	rankingPrinter.printContinually(60);
	rankingPrinter.print();
}
