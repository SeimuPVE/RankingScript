//
// Created by seimu on 07/09/18.
//

#ifndef RANKINGSCRIPT_NEWBIECONTESTRANKING_H
#define RANKINGSCRIPT_NEWBIECONTESTRANKING_H

#include <iostream>
#include <string>
#include <vector>

#include "NewbieContestUser.h"


class NewbieContestRanking {
	private:
		std::vector<NewbieContestUser> user_list;
		std::vector<NewbieContestUser> sorted_user_list;

public:
	NewbieContestRanking();
	NewbieContestRanking(const std::vector<NewbieContestUser> &user_list);

	void setUsers(const std::vector<NewbieContestUser> &users);
	void sortUsers();

	const int getNumberOfUsers() const;
	const NewbieContestUser getUserRanked(int i) const;
};


#endif //RANKINGSCRIPT_NEWBIECONTESTRANKING_H
