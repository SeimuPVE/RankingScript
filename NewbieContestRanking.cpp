//
// Created by seimu on 07/09/18.
//

#include "NewbieContestRanking.h"

NewbieContestRanking::NewbieContestRanking() {}

NewbieContestRanking::NewbieContestRanking(const std::vector<NewbieContestUser> &user_list) : user_list(user_list) {}

void NewbieContestRanking::setUsers(const std::vector<NewbieContestUser> &users) {
	user_list = users;
}

void NewbieContestRanking::sortUsers() {
	std::vector<NewbieContestUser> tmp_user_list = user_list;
	int i, indice_best_user;

	while(tmp_user_list.size() > 0) {
		indice_best_user = 0;

		for(i = 0; i < tmp_user_list.size(); i++)
			if(tmp_user_list[indice_best_user].getPoints() < tmp_user_list[i].getPoints())
				indice_best_user = i;

		sorted_user_list.push_back(tmp_user_list[indice_best_user]);
		tmp_user_list.erase(tmp_user_list.begin() + indice_best_user);
	}
}

const int NewbieContestRanking::getNumberOfUsers() const {
	return user_list.size();
}

const NewbieContestUser NewbieContestRanking::getUserRanked(int i) const {
	return sorted_user_list[i];
}
