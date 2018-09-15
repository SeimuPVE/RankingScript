#include <iostream>
#include "RankingPrinter.h"


int main() {
	RankingPrinter rankingPrinter("/opt/RankingConfig.cfg");
//	rankingPrinter.printContinually(60);
	rankingPrinter.print();
}
