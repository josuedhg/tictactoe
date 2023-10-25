#include "player.h"

Player::Player(std::string name, char marker) : player_name{name}, marker{marker} {}

std::string &Player::getPlayerName()
{
	return this->player_name;
}

char Player::getMarker()
{
	return this->marker;
}

