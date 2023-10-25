#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
class Player {
	char marker;
	std::string player_name;
public:
	Player(std::string name, char marker);
	std::string &getPlayerName();
	char getMarker();
};

#endif
