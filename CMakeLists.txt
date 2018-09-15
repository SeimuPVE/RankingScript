cmake_minimum_required(VERSION 3.12)
project(RankingScript)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++17 -lcurl")

add_executable(RankingScript main.cpp RankingPrinter.cpp RankingPrinter.h RankingScript.cpp RankingScript.h ConfigReader.cpp ConfigReader.h NewbieContestRanking.cpp NewbieContestRanking.h RootMeRanking.cpp RootMeRanking.h NewbieContestUser.cpp NewbieContestUser.h RootMeStats.cpp RootMeStats.h)

target_link_libraries(RankingScript curl)