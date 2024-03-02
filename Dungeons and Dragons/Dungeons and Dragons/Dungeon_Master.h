#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Character.h"
#include "Room.h"
#include "Dice.h"

class Dungeon_Master
{
private:
	std::string name;
	static Dungeon_Master* m_Instance;
	Dungeon_Master(const std::string& newName) : name(newName) {}
public:
	static Dungeon_Master* getInstance(const std::string& newName);

	void displayTitle() const;

	void introduceYourself() const;

	void beginGame()const;

	std::string choseRace()const;

	std::string choseClass()const;

	void createCharacter(Character& character, Race & newRace, Class & newClass);

	void createVillain(Character& villain, Race& newRace, Class& newClass);

	void displayCharacter(Character& character)const;

	void displayAttributes(const Character& character)const;

	void displayRoom(const Room& room); // afiseaza toate elementele dintr-o camera

	std::string chooseAction(const Room& room, Character& character)const;

	void battle(Character& hero, Character& villain);

	Dungeon_Master(Dungeon_Master& other) = delete;
	Dungeon_Master operator = (const Dungeon_Master& other) = delete;
};

