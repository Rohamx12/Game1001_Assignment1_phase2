//Roham Ali 101344253
//Kenneth Rodriguez 101345891

#include <iostream>
#include <sstream>
#include <time.h>
#include <cstdlib>

using namespace std;

class BaseCharacter
{
protected:
	string name;
	int maxHp;
	int presentHp;
	int strenght;
	int intelligence;
	int basedamage;
	int agility;
	int dodgechance;
	int secondarydamage;

public:
	BaseCharacter(string n, int maxHp, int str, int intel, int baseDam, int agl, int dc, int secDam)
	{
		this->name = n;
		this->maxHp = maxHp;
		presentHp = maxHp;
		strenght = str;
		intelligence = intel;
		basedamage = baseDam;
		agility = agl;
		dodgechance = dc;
		secondarydamage = secDam;
	}
	string getName() const
	{
		return name;
	}
	int getStrenght() const
	{
		return strenght;
	}

	int getAgility() const
	{
		return agility;
	}
	
	int getMaxHp() const
	{
		return maxHp;
	}
	int getPresentHp() const
	{
		return presentHp;
	}

	int getAttackValue() const
	{
		return basedamage;
	}

	

	void takedamage(int amt)
	{
		presentHp -= amt;
		if (presentHp < 0)
		{
			presentHp = 0;
		}
	}
	int dodge()
	{
		if (agility > 10)
		{
			int chance = rand() % 100 + 1;
			return chance;
		}
	}
	
	int war = 100;
	int castFireBall()
	{
		return basedamage + war;
	}
	int castHeal()
	{
		presentHp += war;
		if (presentHp > maxHp)
		{
			presentHp = maxHp;
		}
		return war;
	}
	
	
	string toString()
	{
		stringstream s;
		s << "Name: " << name << endl;
		s << "Max HP: " << maxHp << endl;
		s << "PresentHp: " << presentHp << endl;
		s << "strenght: " << strenght << endl;
		s << "Intellegence: " << intelligence << endl;
		s << "Agility" << agility << endl << endl << endl;
		return s.str();
	}

};

class Warrior :public BaseCharacter
{
public:
	Warrior(string n, int maxHp, int str, int intel, int baseDam ,int agl,int dc, int secdam) :BaseCharacter(n, maxHp, str, intel, baseDam, agl, dc, secdam) {}

	int getAttackValue()
	{
		return basedamage + strenght / 2;
	}
	
	int getSecDam()
	{
		return secondarydamage;
	}
	

};

class Mage :public BaseCharacter {
private:
	int mana;
public:
	Mage(string n, int maxHp, int str, int intel, int baseDam, int mana, int agl, int dc, int secdam) :BaseCharacter(n, maxHp, str, intel, baseDam, agl, dc, secdam)
	{
		this->mana = mana;
	}
	

};

class Priest :public BaseCharacter {
private:
	int mana;
public:
	Priest(string n, int maxHp, int str, int intel, int baseDam, int mana, int agl, int dc, int secdam) :BaseCharacter(n, maxHp, str, intel, baseDam, agl, dc, secdam)
	{
		this->mana = mana;
	}
	

};

void ArenaManager(BaseCharacter* player1 , BaseCharacter* player2)
{

	int round = 1, roll, damage, secdamage;
	system("CLS");
	while (player1->getPresentHp() > 0 && player2->getPresentHp() > 0)
	{
		
		cout << "Battle Field: " << player1->getName() << " And " << player2->getName() << "!!!" << endl;
		cout << "-------- Round: " << round << " ---------\n\n\n";
		
			roll = rand() % 100 + 1;
			if (roll > 50)
			{
				//Warrior go first
				
					damage = player1->getAttackValue();
					
					if (roll > 90)
					{
						player2->takedamage(damage/2);
						cout << player1->getName() << " Used his Secondary weapon on " << player2->getName() << " for " << damage /2 << " damage \n\n";
					}
					else
					{
						player2->takedamage(damage);
						cout << player1->getName() << " Used his Primary weapon on " << player2->getName() << " for " << damage << " damage \n\n";
					}
					if (player2->getPresentHp() > 0)
					{
						roll = rand() % 100 + 1;
						if (roll < 60)
						{
							
							damage = player2->getAttackValue();
							if (player1->dodge() < 50)
							{
								if (roll > 90)
								{
									player1->takedamage(damage/2);
									cout << player2->getName() << " Used his Secondary weapon on " << player1->getName() << " for " << damage << " damage \n\n";
								}
								else
								{
									player1->takedamage(damage);
									cout << player2->getName() << " Used his Primary weapon on " << player1->getName() << " for " << damage << " damage \n\n";
								}
							}
							else
							{
								cout << player1->getName() << " Dodged the attack" << endl;
							}
						}
						else if (roll <= 90)
						{
							damage = player2->castFireBall();
							if (player1->dodge() < 50)
							{
								player1->takedamage(damage);
								cout << player2->getName() << " hits " << player1->getName() << " With a *fire ball* for " << damage << " damage \n\n";
							}
							else
							{
								cout << player1->getName() << " Dodged the *fire ball*" << endl;
							}
						}
						else
						{
							player2->castHeal();
							cout << player2->getName() << " Healed up for " << player2->castHeal() << endl;
						}

					}
				
				
			}
		
		
		else
		{
			//player2e goes first
			roll = rand() % 100 + 1;
			if (roll < 60)
			{
				damage = player2->getAttackValue();
				if (player1->dodge() < 50)
				{
					if (roll > 90)
					{
						player1->takedamage(damage/2);
						cout << player2->getName() << " Used his Secondary weapon on " << player1->getName() << " for " << damage / 2 << " damage \n\n";
					}
					else
					{
						player1->takedamage(damage);
						cout << player2->getName() << " Used his Primary weapon on " << player1->getName() << " for " << damage << " damage \n\n";
					}
				}
				else
				{
					cout << player1->getName() << " Dodged the attack" << endl;
				}
			}
			else if (roll <= 90)
			{
				damage = player2->castFireBall();
				if (player1->dodge() < 50)
				{
					player1->takedamage(damage);
					cout << player2->getName() << " hits " << player1->getName() << " with a *fire ball* for " << damage << " damage \n\n";
				}
				else
				{
					cout << player1->getName() << " Dodged the *fire ball*" << endl;
				}
			}
			else
			{
				player2->castHeal();
				cout << player2->getName() << " Healed up for " << player2->castHeal() << endl;
			}
			if (player2->getPresentHp() > 0)
			{
				damage = player1->getAttackValue();
				if (roll > 90)
				{
					player2->takedamage(damage/2);
					cout << player1->getName() << " Used his Secondary weapon on " << player2->getName() << " for " << damage /2<< " damage \n\n";
				}
				else
				{
					player2->takedamage(damage);
					cout << player1->getName() << " Used his Primary weapon on " << player2->getName() << " for " << damage << " damage \n\n";
				}
			}
			else
			{
				cout << player1->getName() << " Dodged the attack" << endl;
			}


		}
		cout << "End of round stats: \n" << player1->getName() << "HP: (" << player1->getPresentHp() << ")\n" << player2->getName() << "HP: (" << player2->getPresentHp() << ")\n\n\n";
		round++;

		cout << "Press any key to skip this round... \n\n";
		system("Pause");

	}
	if (player1->getPresentHp() > 0)
	{
		cout << "=======" << player1->getName() << " Wins!" << "=======" << endl;
	}
	else
	{
		cout << "=======" << player2->getName() << " Wins!" << "=======" << endl;
	}
	
}


int main()
{
	int pick, wp, wpdmg = 0, stg, agil;
	string name;
	int picked,view;
	for (int i = 0; i <= 10; i++)
	{
		cout << "Pick your First fighter:\n 1.Warrior ==> 200hp === 20 intelligence\n 2.Mage ==> 185hp === 15 intelligence\n 3.Priest ==> 150hp === 10 intelligence\n";
		cin >> pick;
		if (pick == 1)
		{
			cout << "You picked a Warrior\n";
			cout << "Your fighter's name:";
			cin >> name;
			for (int i = 0; i <= 10; i++)
			{
				cout << "choose your fighter's weapon:\n";
				cout << "1.Sword ===> 30 damage\n2.Wand ===> 25\n3.Cross ===> 20\n";
				cin >> wp;
				if (wp >= 4 && wp <= 0)
				{
					cout << "You picked the wrong weapon\n";
				}
				if (wp == 1)
				{
					cout << "You picked Sword\n";
					wpdmg = 30;
					break;
				}
				else if (wp == 2)
				{
					cout << "You picked Wand\n";
					wpdmg = 25;
					break;
				}
				else if (wp == 3)
				{
					cout << "You picked Cross\n";
					wpdmg = 20;
					break;
				}
			}
			cout << "Pick your characters strength:(0 to 50)\n";
			cin >> stg;
			if (stg < 0 || stg >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				stg = 25;
			}
			cout << "Enter your character agility:(0 to 50)\n";
			cin >> agil;
			if (agil < 0 || agil >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				agil = 25;
			}
			Warrior* soldier1 = new Warrior(name, 200, stg, 20, wpdmg, agil, 0, 20);
			cout << "Enter number (1) to view your fighter\n";
			cin >> view;
			if(view == 1)
			{
				cout << "*Fighter:*\n" << soldier1->toString();
				system("Pause");
			}
			

			picked = 1;
			break;
		}


		if (pick == 2)
		{
			cout << "You picked a Mage\n";
			cout << "Your fighter's name:";
			cin >> name;
			for (int i = 0; i <= 10; i++)
			{
				cout << "choose your fighter's weapon:\n";
				cout << "1.Sword ===> 30 damage\n2.Wand ===> 25\n3.Cross ===> 20\n";
				cin >> wp;
				if (wp >= 4 && wp <= 0)
				{
					cout << "You picked the wrong weapon\n";
				}
				if (wp == 1)
				{
					cout << "You picked Sword\n";
					wpdmg = 30;
					break;
				}
				else if (wp == 2)
				{
					cout << "You picked Wand\n";
					wpdmg = 25;
					break;
				}
				else if (wp == 3)
				{
					cout << "You picked Cross\n";
					wpdmg = 20;
					break;
				}

			}
			cout << "Pick your characters strength:(0 to 50)\n";
			cin >> stg;
			if (stg < 0 || stg >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				stg = 25;
			}
			cout << "Enter your character agility:(0 to 50)\n";
			cin >> agil;
			if (agil < 0 || agil >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				agil = 25;
			}
			Mage* mag = new Mage(name, 185, stg, 15, wpdmg, 80, agil, 0, 20);
			cout << "Enter number (1) to view your fighter";
			cin >> view;
			if (view == 1)
			{
				cout << "*Fighter:*\n" << mag->toString();
				system("Pause");
			}
			picked = 2;
			break;
		}


		if (pick == 3)
		{
			cout << "You picked a Priest\n";
			cout << "Your fighter's name:";
			cin >> name;
			for (int i = 0; i <= 10; i++)
			{
				cout << "choose your fighter's weapon:\n";
				cout << "1.Sword ===> 30 damage\n2.Wand ===> 25\n3.Cross ===> 20\n";
				cin >> wp;
				if (wp >= 4 && wp <= 0)
				{
					cout << "You picked the wrong weapon\n";
				}
				if (wp == 1)
				{
					cout << "You picked Sword\n";
					wpdmg = 30;
					break;
				}
				else if (wp == 2)
				{
					cout << "You picked Wand\n";
					wpdmg = 25;
					break;
				}
				else if (wp == 3)
				{
					cout << "You picked Cross\n";
					wpdmg = 20;
					break;
				}
			}
			cout << "Pick your characters strength:(0 to 50)\n";
			cin >> stg;
			if (stg < 0 || stg >50)
			{
				cout << "You picked the wrong number\n The character will have the default value for strength(25)\n";
				stg = 25;
			}
			cout << "Enter your character agility:(0 to 50)\n";
			cin >> agil;
			if (agil < 0 || agil >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				agil = 25;
			}
			Priest* father = new Priest(name, 150, stg, 10, wpdmg, 80, agil, 0, 20);
			cout << "Enter number (1) to view your fighter";
			cin >> view;
			if (view == 1)
			{
				cout << "*Fighter:*\n" << father->toString();
				system("Pause");
			}
			picked = 3;
			break;
		}

		else
		{
			cout << "You picked the wrong number. choose again\n\n";

		}
	}

	Warrior* soldier1 = new Warrior(name, 200, stg, 20, wpdmg, agil, 0, 20);
	Mage* mag = new Mage(name, 185, stg, 15, wpdmg, 80, agil, 0, 20);
	Priest* father = new Priest(name, 150, stg, 10, wpdmg, 80, agil, 0, 20);
	////////////////////////////
	int pick1, wp1, wpdmg1 = 0, stg1, agil1;
	string name1;
	int picked2;
	for (int i = 0; i <= 10; i++)
	{
		cout << "Pick your Second fighter:\n 1.Warrior ==> 200hp === 20 intelligence\n 2.Mage ==> 185hp === 15 intelligence\n 3.Priest ==> 150hp === 10 intelligence\n";
		cin >> pick1;
		if (pick1 == 1)
		{
			cout << "You picked a Warrior\n";
			cout << "Your Second fighter's name:";
			cin >> name1;
			for (int i = 0; i <= 10; i++)
			{
				cout << "choose your fighter's weapon:\n";
				cout << "1.Sword ===> 30 damage\n2.Wand ===> 25\n3.Cross ===> 20\n";
				cin >> wp1;
				if (wp1 >= 4 && wp1 <= 0)
				{
					cout << "You picked the wrong weapon\n";
				}
				if (wp1 == 1)
				{
					cout << "You picked Sword\n";
					wpdmg1 = 30;
					break;
				}
				else if (wp1 == 2)
				{
					cout << "You picked Wand\n";
					wpdmg1 = 25;
					break;
				}
				else if (wp1 == 3)
				{
					cout << "You picked Cross\n";
					wpdmg1 = 20;
					break;
				}
			}
			cout << "Pick your characters strength:(0 to 50)\n";
			cin >> stg1;
			if (stg1 < 0 || stg1 >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				stg1 = 25;
			}
			cout << "Enter your character agility:(0 to 50)\n";
			cin >> agil1;
			if (agil1 < 0 || agil1 >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				agil1 = 25;
			}
			Warrior* soldier2 = new Warrior(name1, 200, stg1, 20, wpdmg1, agil1, 0, 20);
			cout << "Enter number (1) to view your fighter";
			cin >> view;
			if (view == 1)
			{
				cout << "*Fighter:*\n" << soldier2->toString();
				system("Pause");
			}
			
			picked2 = 1;
			break;
		}
		else if (pick1 == 2)
		{
			cout << "You picked a Mage\n";
			cout << "Your fighter's name:";
			cin >> name1;
			for (int i = 0; i <= 10; i++)
			{
				cout << "choose your fighter's weapon:\n";
				cout << "1.Sword ===> 30 damage\n2.Wand ===> 25\n3.Cross ===> 20\n";
				cin >> wp1;
				if (wp1 >= 4 && wp1 <= 0)
				{
					cout << "You picked the wrong weapon\n";
				}
				if (wp1 == 1)
				{
					cout << "You picked Sword\n";
					wpdmg1 = 30;
					break;
				}
				else if (wp1 == 2)
				{
					cout << "You picked Wand\n";
					wpdmg1 = 25;
					break;
				}
				else if (wp == 3)
				{
					cout << "You picked Cross\n";
					wpdmg1 = 20;
					break;
				}

			}
			cout << "Pick your characters strength:(0 to 50)\n";
			cin >> stg1;
			if (stg1 < 0 || stg1 >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				stg1 = 25;
			}
			cout << "Enter your character agility:(0 to 50)\n";
			cin >> agil1;
			if (agil1 < 0 || agil1 >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				agil1 = 25;
			}
			Mage* mag2 = new Mage(name1, 185, stg1, 15, wpdmg1, 80, agil1, 0, 20);
			cout << "Enter number (1) to view your fighter";
			cin >> view;
			if (view == 1)
			{
				cout << "*Fighter:*\n" << mag2->toString();
				system("Pause");
			}
			picked2 = 2;
			break;
		}
		else if (pick1 == 3)
		{
			cout << "You picked a Priest\n";
			cout << "Your fighter's name:";
			cin >> name1;
			for (int i = 0; i <= 10; i++)
			{
				cout << "choose your fighter's weapon:\n";
				cout << "1.Sword ===> 30 damage\n2.Wand ===> 25\n3.Cross ===> 20\n";
				cin >> wp1;
				if (wp1 >= 4 && wp1 <= 0)
				{
					cout << "You picked the wrong weapon\n";
				}
				if (wp1 == 1)
				{
					cout << "You picked Sword\n";
					wpdmg1 = 30;
					break;
				}
				else if (wp1 == 2)
				{
					cout << "You picked Wand\n";
					wpdmg1 = 25;
					break;
				}
				else if (wp1 == 3)
				{
					cout << "You picked Cross\n";
					wpdmg1 = 20;
					break;
				}
			}
			cout << "Pick your characters strength:(0 to 50)\n";
			cin >> stg1;
			if (stg1 < 0 || stg1 >50)
			{
				cout << "You picked the wrong number\n The character will have the default value for strength(25)\n";
				stg1 = 25;
			}
			cout << "Enter your character agility:(0 to 50)\n";
			cin >> agil1;
			if (agil1 < 0 || agil1 >50)
			{
				cout << "You picked the wrong number\n The character will have the default value(25)\n";
				agil1 = 25;
			}
			Priest* father2 = new Priest(name1, 150, stg1, 10, wpdmg1, 80, agil1, 0, 20);
			cout << "Enter number (1) to view your fighter";
			cin >> view;
			if (view == 1)
			{
				cout << "*Fighter:*\n" << father2->toString();
				system("Pause");
			}
			picked2 = 3;
			break;
		}
		else
		{
			cout << "You picked the wrong number. choose again\n\n";

		}
	}

		srand(time(NULL));



		Warrior* soldier2 = new Warrior(name1, 200, stg1, 20, wpdmg1, agil1, 0, 20);
		Mage* mag2 = new Mage(name1, 185, stg1, 15, wpdmg1, 80, agil1, 0, 20);
		Priest* father2 = new Priest(name1, 150, stg1, 10, wpdmg1, 80, agil1, 0, 20);
		int press, fight;
		if (picked == 1 && picked2 == 1)
		{
			cout << "To view all of the contenders Enter number (1)... \n Enter any key to continue\n";
			

			cin >> press;
			if (press == 1)
			{
				cout << "*Contender 1:*\n" << soldier1->toString();
				cout << "*Contender 2:*\n" << soldier2->toString();
				system("Pause");
			}

			ArenaManager(soldier1, soldier2);
		}
		if (picked == 2 && picked2 == 1)
		{
			cout << "To view all of the contenders Enter number (1)... \n Enter any key to continue\n";
			cin >> press;
			if (press == 1)
			{
				cout << "*Contender 1:*\n" << mag->toString();
				cout << "*Contender 2:*\n" << soldier2->toString();
				system("Pause");
			}
			ArenaManager(mag, soldier2);
		}
		if (picked == 3 && picked2 == 1)
		{
			cout << "To view all of the contenders Enter number (1)... \n Enter any key to continue\n";
			cin >> press;
			if (press == 1)
			{
				cout << "*Contender 1:*\n" << father->toString();
				cout << "*Contender 2:*\n" << soldier2->toString();
				system("Pause");
			}
			ArenaManager(father, soldier2);
		}
		if (picked == 2 && picked2 == 2)
		{
			cout << "To view all of the contenders Enter number (1)... \n Enter any key to continue\n";
			cin >> press;
			if (press == 1)
			{
				cout << "*Contender 1:*\n" << mag->toString();
				cout << "*Contender 2:*\n" << mag2->toString();
				system("Pause");
			}
			ArenaManager(mag, mag2);
		}
		if (picked == 3 && picked2 == 2)
		{
			cout << "To view all of the contenders Enter number (1)... \n Enter any key to continue\n";
			cin >> press;
			if (press == 1)
			{
				cout << "*Contender 1:*\n" << mag->toString();
				cout << "*Contender 2:*\n" << mag2->toString();
				system("Pause");
			}
			ArenaManager(father, mag2);
		}
		if (picked == 1 && picked2 == 2)
		{
			cout << "To view all of the contenders Enter number (1)... \n Enter any key to continue\n";
			cin >> press;
			if (press == 1)
			{
				cout << "*Contender 1:*\n" << soldier1->toString();
				cout << "*Contender 2:*\n" << mag2->toString();
				system("Pause");
			}
			ArenaManager(soldier1, mag2);
		}
		if (picked == 1 && picked2 == 3)
		{
			cout << "To view all of the contenders Enter number (1)... \n Enter any key to continue\n";
			cin >> press;
			if (press == 1)
			{
				cout << "*Contender 1:*\n" << soldier1->toString();
				cout << "*Contender 2:*\n" << father2->toString();
				system("Pause");
			}
			ArenaManager(soldier1, father2);
		}
		if (picked == 2 && picked2 == 3)
		{
			cout << "To view all of the contenders Enter number (1)... \n Enter any key to continue\n";
			cin >> press;
			if (press == 1)
			{
				cout << "*Contender 1:*\n" << mag->toString();
				cout << "*Contender 2:*\n" << father2->toString();
				system("Pause");
			}
			ArenaManager(mag, father2);
		}
		if (picked == 3 && picked2 == 3)
		{
			cout << "To view all of the contenders Enter number (1)... \n Enter any key to continue\n";
			cin >> press;
			if (press == 1)
			{
				cout << "*Contender 1:*\n" << father->toString();
				cout << "*Contender 2:*\n" << father2->toString();
				system("Pause");
			}
			ArenaManager(father, father2);
		}
	
	return 0;

}
