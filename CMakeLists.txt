cmake_minimum_required(VERSION 3.12)
project(RankingScript)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++17 -lcurl")

add_executable(RankingScript src/main.cpp src/ranking/RankingPrinter.cpp src/ranking/RankingPrinter.h src/ranking/RankingScript.cpp src/ranking/RankingScript.h src/config/ConfigReader.cpp src/config/ConfigReader.h src/newbiecontest/NewbieContestRanking.cpp src/newbiecontest/NewbieContestRanking.h src/rootme/RootMeRanking.cpp src/rootme/RootMeRanking.h src/newbiecontest/NewbieContestUser.cpp src/newbiecontest/NewbieContestUser.h src/rootme/RootMeStats.cpp src/rootme/RootMeStats.h)

target_link_libraries(RankingScript curl)