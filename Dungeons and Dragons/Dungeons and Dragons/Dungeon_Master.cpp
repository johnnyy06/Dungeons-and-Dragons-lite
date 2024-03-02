#include "Dungeon_Master.h"
#include "Colors.h"

enum RACE { DWARF = 1, ELF, HALFLING, HUMAN };

enum CLASS { CLERIC = 1, FIGHTER, ROGUE, WIZARD };

Dungeon_Master* Dungeon_Master::m_Instance = nullptr;

Dungeon_Master* Dungeon_Master::getInstance(const std::string& newName)
{
    if (m_Instance == nullptr) m_Instance = new Dungeon_Master(newName);
  
    return m_Instance;
}

void Dungeon_Master::displayTitle() const
{
    std::cout << "\t\t\t\t\t\t   " << Colors::WHITE_BACKGROUND << Colors::BLACK
        << "Dungeons and Dragons" << Colors::RESET << "\t\t" << Colors::RESET << "\n\n";
}

void Dungeon_Master::introduceYourself() const
{
    std::cout << "    Good day! I am " << Colors::PURPLE_BACKROUND << Colors::YELLOW <<
        this->name << Colors::RESET << ". I will be your guide in this magical World of Dungeons! Let's begin your story!\n\n\n";
}

void Dungeon_Master::beginGame()const
{
    std::cout << "\t\t\t\tWelcome to the captivating world of Dungeons & Dragons\n\t\t          - an epic universe in which your imagination will become reality -\n\n";
    std::cout << "\t       In this role-playing game, you will explore fantastical realms, confront mythical creatures\n\t\t\t       and embark on incredible adventures with friends. \n";
    std::cout << "\t\t\t  We begin a journey into a world full of mystery, magic and danger.\n\t\t The destiny of your characters will be shaped by the choices you make in this epic odyssey.\n";
    std::cout << "\t\t   Get ready to dive into a compelling story where only imagination sets the boundaries!\n\n\n\n";
}

std::string Dungeon_Master::choseRace() const
{
    int tempRace;

    std::cout << "\tIt's time to chose your character's race: 1. Dwarf   2. Elf   3. Halfling   4. Human\n\t";

    std::string str_tempRace;
    std::cin >> str_tempRace;

    while (str_tempRace != "1" && str_tempRace != "2" && str_tempRace != "3" && str_tempRace != "4")
    {
        std::cout << "Invalid race. Please select one of the above: ";
        std::cin >> str_tempRace;
    }

    tempRace = stoi(str_tempRace);

    switch (tempRace)
    {
    case DWARF:
        return "Dwarf";
        break;
    case ELF:
        return "Elf";
        break;
    case HALFLING:
        return "Halfling";
        break;
    case HUMAN:
        return "Human";
        break;
    }
}

std::string Dungeon_Master::choseClass() const
{
    int tempClass;

    std::cout << "\tIt's time to chose your character's race: 1. Cleric   2. Fighter   3. Rogue   4. Wizard\n\t";

    std::string str_tempClass;
    std::cin >> str_tempClass;

    while (str_tempClass != "1" && str_tempClass != "2" && str_tempClass != "3" && str_tempClass != "4")
    {
        std::cout << "Invalid race. Please select one of the above: ";
        std::cin >> str_tempClass;
    }

    tempClass = stoi(str_tempClass);

    switch (tempClass)
    {
    case CLERIC:
        return "Cleric";
        break;
    case FIGHTER:
        return "Fighter";
        break;
    case ROGUE:
        return "Rogue";
        break;
    case WIZARD:
        return "Wizard";
        break;
    }
}

void Dungeon_Master::createCharacter(Character& character, Race & newRace, Class & newClass)
{
    // initializeaza numele caracterului
    std::cout << "\tName your Hero: ";
    std::string tempName;
    std::cin >> tempName;
    character.setCh_Name(tempName);

    character.setC_name(newClass.getC_name());
    character.setC_abilities(newClass.getC_abilities());
    character.setC_attributes(newClass.getC_attributes());

    character.setR_name(newRace.getR_name());
    character.setR_abilities(newRace.getR_abilities());
    character.setR_attributes(newRace.getR_attributes());

    for (const auto& i : character.getC_attributes())
    {
        if (i.getName() == "Strength") character.addStrength(i.getPoints());

        if (i.getName() == "Dexterity") character.addDexterity(i.getPoints());

        if (i.getName() == "Intelligence") character.addIntelligence(i.getPoints());
    }

    for (const auto& i : character.getR_attributes())
    {
        if (i.getName() == "Strength") character.addStrength(i.getPoints());

        if (i.getName() == "Dexterity") character.addDexterity(i.getPoints());

        if (i.getName() == "Intelligence") character.addIntelligence(i.getPoints());
    }
}

void Dungeon_Master::createVillain(Character& villain, Race& newRace, Class& newClass)
{
    // initializeaza numele inamicului
    villain.setCh_Name("Villain");

    villain.setC_name(newClass.getC_name());
    villain.setC_abilities(newClass.getC_abilities());
    villain.setC_attributes(newClass.getC_attributes());

    villain.setR_name(newRace.getR_name());
    villain.setR_abilities(newRace.getR_abilities());
    villain.setR_attributes(newRace.getR_attributes());

    for (const auto& i : villain.getC_attributes())
    {
        if (i.getName() == "Strength") villain.addStrength(i.getPoints());

        if (i.getName() == "Dexterity") villain.addDexterity(i.getPoints());

        if (i.getName() == "Intelligence") villain.addIntelligence(i.getPoints());
    }

    for (const auto& i : villain.getR_attributes())
    {
        if (i.getName() == "Strength") villain.addStrength(i.getPoints());

        if (i.getName() == "Dexterity") villain.addDexterity(i.getPoints());

        if (i.getName() == "Intelligence") villain.addIntelligence(i.getPoints());
    }
}

void Dungeon_Master::displayCharacter(Character& character)const
{
    std::cout << character << "\n\n";
}

void Dungeon_Master::displayAttributes(const Character& character) const
{
    std::cout << "\tStrength: " << character.getStrength() << "   Dexterity: " << character.getDexterity() << "   Intelligence: " << character.getIntelligence() << "\n";
}

void Dungeon_Master::displayRoom(const Room& room)
{
    std::cout << room << "\n\n";
}

std::string Dungeon_Master::chooseAction(const Room& room, Character& character)const
{
    int choice = 0;
    int rolled = 0;

    while (1)
    {
        std::cout << "\tWhat you gonna do?\t";

        std::cin >> choice;

        while (choice < 1 || choice > room.getItemCounter())
        {
            std::cout << "\tInvalid choice. Please choose one of the above.\t";
            std::cin >> choice;
        }

        std::vector <Item> temp = room.getItemList();

        std::vector <Item>::iterator iter = temp.begin();
        iter += choice;
        iter -= 1;
        
        rolled = Dice::roll();
        std::cout << "\tRolling the dice...\t\tIt's " << rolled;
        std::cout << "\n\n";

        if ((*iter).getWhatRequired() == "Strength")
        {
            rolled += character.abilityContribution(character.getStrength());
        }

        if ((*iter).getWhatRequired() == "Dexterity")
        {
            rolled += character.abilityContribution(character.getDexterity());
        }

        if ((*iter).getWhatRequired() == "Intelligence")
        {
            rolled += character.abilityContribution(character.getIntelligence());
        }

        std::cout << "\tThe total is: " << rolled << "\n\n";

        if (rolled >= (*iter).getAmountRequired())
        {
            std::cout << "\tAmazing! You'll get what you've asked for!\n\n";

            if ((*iter).getName() == "Door" || (*iter).getName() == "Portal")
            {
                return (*iter).getWhereTo();
            }

            if ((*iter).getName() == "Book")
            {
                if ((*iter).getWhatGives() == "Strength") character.addStrength((*iter).getAmountGiven());
                if ((*iter).getWhatGives() == "Dexterity") character.addDexterity((*iter).getAmountGiven());
                if ((*iter).getWhatGives() == "Intelligence") character.addIntelligence((*iter).getAmountGiven());

                this->displayAttributes(character);
            }
        }
        else
        {
            std::cout << "\tUnfortunately not enough... Try again.\n\n";
        }
    }
}

void Dungeon_Master::battle(Character& hero, Character& villain)
{
    while (1)
    {
        std::cout << "\t" << Colors::RED_BACKGROUND << villain.getCh_name() << "\t\t\t\t\t\t\t\t\t\t\t\t" << Colors::GREEN_BACKGROUND << hero.getCh_name() << Colors::RESET << "\n";
        std::cout << "\tHP: " << villain.getHitPoints() << "\t\t\t\t\t\t\t\t\t\t\t\tHP: " << hero.getHitPoints() << "\n";

        int abilityCounter = 0;

        std::vector <Ability> abilityTemp;

        std::cout << "\n\n\tChoose an ability to hit the enemy:\n";
        for (const auto& i : hero.getR_abilities())
        {
            abilityTemp.push_back(i);
            abilityCounter++;
            std::cout << "\t" << abilityCounter << ". " << i.getName() << "  " << i.getDamage() << " damage -> roll " <<
                i.getCost() << " " << i.getRequired() << "\n";
        }

        for (const auto& i : hero.getC_abilities())
        {
            abilityTemp.push_back(i);
            abilityCounter++;
            std::cout << "\t" << abilityCounter << ". " << i.getName() << "  " << i.getDamage() << " damage -> roll " <<
                i.getCost() << " " << i.getRequired() << "\n";
        }

        int choice = 0;

        std::cin >> choice;

        while (choice < 1 || choice > abilityCounter)
        {
            std::cout << "\tInvalid choice. Please choose one of the above.\t";
            std::cin >> choice;
        }

        std::vector <Ability>::iterator iter = abilityTemp.begin();
        iter += choice;
        iter -= 1;

        // atacul caracterului dumneavoastra
        int rolled = 0;
        rolled = Dice::roll();
        std::cout << "\tRolling the dice...\t\tIt's " << rolled;
        std::cout << "\n\n";

        if ((*iter).getRequired() == "Strength")
        {
            rolled += hero.abilityContribution(hero.getStrength());
        }

        if ((*iter).getRequired() == "Dexterity")
        {
            rolled += hero.abilityContribution(hero.getDexterity());
        }

        if ((*iter).getRequired() == "Intelligence")
        {
            rolled += hero.abilityContribution(hero.getIntelligence());
        }

        std::cout << "\tThe total is: " << rolled << "\n\n";

        if (rolled >= (*iter).getCost() && hero.getHitPoints() >= 0)
        {
            std::cout << "\tSuccess! You hit the enemy!\n\n";

            villain.takeDamage((*iter).getDamage());
        }
        else
        {
            std::cout << "\tUnfortunately not enough...\n\n";
        }

        // atacul inamicului
        rolled = Dice::roll();
        std::cout << "\tRolling the dice...\t\tIt's " << rolled;
        std::cout << "\n\n";

        rolled += villain.abilityContribution(villain.getStrength());

        if (rolled >= villain.getC_abilities()[1].getCost() && villain.getHitPoints() >= 0)
        {
            std::cout << "\tVillain hit you. You are getting low on health.\n\n";
            hero.takeDamage(villain.getC_abilities()[1].getDamage());
        }
        else
        {
            std::cout << "\tThe enemy missed you.\n\n";
        }

        // deznodamantul bataliei
        if (hero.getHitPoints() <= 0)
        {
            std::cout << Colors::RED << "\tYou have been defeted! Game over!\n\n" << Colors::RESET;
            exit(0);
        }

        if (villain.getHitPoints() <= 0)
        {
            std::cout << Colors::GREEN << "\tYou defeted the enemy\n\n" << Colors::RESET;
            return;
        }
    }
}
