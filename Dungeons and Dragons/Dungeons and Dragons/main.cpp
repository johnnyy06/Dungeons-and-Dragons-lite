#include "Dungeon_Master.h"
#include "Character.h"
#include "Room.h"
#include "Dice.h"


int main() {

	// initializare rase
	Race dwarf("Dwarf");
	dwarf.setAbilities("DwarfAbilities.txt");
	dwarf.setAttributes("DwarfAttributes.txt");

	Race elf("Elf");
	elf.setAbilities("ElfAbilities.txt");
	elf.setAttributes("ElfAttributes.txt");

	Race halfling("Halfling");
	halfling.setAbilities("HalflingAbilities.txt");
	halfling.setAttributes("HalflingAttributes.txt");

	Race human("Human");
	human.setAbilities("HumanAbilities.txt");
	human.setAttributes("HumanAttributes.txt");

	// initializare clase
	Class cleric("Cleric");
	cleric.setAbilities("ClericAbilities.txt");
	cleric.setAttributes("ClericAttributes.txt");

	Class fighter("Fighter");
	fighter.setAbilities("FighterAbilities.txt");
	fighter.setAttributes("FighterAttributes.txt");

	Class rogue("Rogue");
	rogue.setAbilities("RogueAbilities.txt");
	rogue.setAttributes("RogueAttributes.txt");

	Class wizard("Wizard");
	wizard.setAbilities("WizardAbilities.txt");
	wizard.setAttributes("WizardAttributes.txt");

	// creare Dungeon Master
	Dungeon_Master* narrator = Dungeon_Master::getInstance("The Dungeon Master");

	// introducere joc
	narrator->displayTitle();
	narrator->introduceYourself();
	narrator->beginGame();

	// creare caracter principal
	Character hero("");

	Race heroRace{};
	std::string raceName = narrator->choseRace();
	if (raceName == "Dwarf") heroRace = dwarf;
	if (raceName == "Elf") heroRace = elf;
	if (raceName == "Halfling") heroRace = halfling;
	if (raceName == "Human") heroRace = human;

	Class heroClass{};
	std::string className = narrator->choseClass();
	if (className == "Cleric") heroClass = cleric;
	if (className == "Fighter") heroClass = fighter;
	if (className == "Rogue") heroClass = rogue;
	if (className == "Wizard") heroClass = wizard;

	narrator->createCharacter(hero, heroRace, heroClass);

	narrator->displayCharacter(hero);

	// creare inamic
	Character villain("");
	narrator->createVillain(villain, dwarf, fighter);

	Room basement("Basement", "Basement.txt");
	basement.setItemCounter();
	Room bastille("Bastille", "Bastille.txt");
	bastille.setItemCounter();
	Room hallway("Hallway", "Hallway.txt");
	hallway.setItemCounter();
	Room library("Library", "Library.txt");
	library.setItemCounter();
	Room treeHouse("TreeHouse", "TreeHouse.txt");
	treeHouse.setItemCounter();

	narrator->displayRoom(hallway);
	std::string nextRoom = narrator->chooseAction(hallway, hero);

	int numberDefeatedEnemies = 0;

	while (hero.getHitPoints() > 0)
	{
		if (nextRoom == "Basement")
		{
			narrator->displayRoom(basement);
			nextRoom = narrator->chooseAction(basement, hero);
		}

		if (nextRoom == "Bastille")
		{
			narrator->displayRoom(bastille);
			nextRoom = narrator->chooseAction(bastille, hero);
		}

		if (nextRoom == "Hallway")
		{
			narrator->displayRoom(hallway);
			nextRoom = narrator->chooseAction(hallway, hero);
		}

		if (nextRoom == "Library")
		{
			narrator->displayRoom(library);
			nextRoom = narrator->chooseAction(library, hero);
		}

		if (nextRoom == "TreeHouse")
		{
			narrator->displayRoom(treeHouse);
			nextRoom = narrator->chooseAction(treeHouse, hero);
		}

		// intalnirea cu un inamic
		std::cout << "\n\tAn enemy gets in your way. \"Do you want to fight, hero?\"\n\n";
		std::cout << "\tPress '9' for YES or '0' for NO\n\n\t";
		int choice = 0;
		std::cin >> choice;

		if (choice == 9)
		{
			narrator->battle(hero, villain);
			numberDefeatedEnemies++;
		}

		// resetare viata caractere
		hero.setHitPoints(100);
		villain.setHitPoints(100);

		// conditie pentru a castiga jocul
		if (numberDefeatedEnemies >= 3)
		{
			std::cout << "\033[33m" << "\tCongratulation! You've won!\n\n" << "\033[0m"; //codurile sunt de la culorile galben si alb
			break;
		}
	}

	std::cin.get();
	std::cin.get();
	return 0;
}