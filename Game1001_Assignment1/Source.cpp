//Roham Ali 101344253


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
		s << "Agility" << agility << endl;
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
	int pick, wp, wpdmg = 0, stg;
	string name;
	
	for (int i = 0; i <= 10; i++)
	{
		cout << "Pick your First fighter:\n 1.Warrior ==> 200hp\n 2.Mage ==> 185hp\n 3.Priest ==> 150hp\n";
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
			break;
		}
		else if (pick == 2)
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
			break;
		}
		else if (pick == 3)
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
			break;
		}
		else
		{
			cout << "You picked the wrong number. choose again\n\n";

		}
	}
	
	srand(time(NULL));
	
	Warrior* soldier1 = new Warrior(name, 200, stg, 17, wpdmg,12,0,20);
	
	Mage* mag = new Mage("Ghoul", 185, 15, 19, 20, 80,12,0,20);

	Priest* father = new Priest("Rohani", 150, 16, 20, 10, 70,12,0,10);

	cout << "Contender 1:\n" << soldier1->toString();
	cout << "Contender 2:\n" << mag->toString();
	system("Pause");

	
	
	ArenaManager(soldier1, mag);



	return 0;
}