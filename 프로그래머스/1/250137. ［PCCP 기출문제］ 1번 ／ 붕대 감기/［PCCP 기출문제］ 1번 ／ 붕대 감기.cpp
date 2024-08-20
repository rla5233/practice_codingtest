#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int MaxHealth = health;
    int TotalSecond = attacks[attacks.size() - 1][0];
    int HealCount = 0;
    int AttackIndex = 0;
    for(int i = 1; i <= TotalSecond; ++i)
    {
        if(i == attacks[AttackIndex][0])
        {
            health -= attacks[AttackIndex][1];
			HealCount = 0;
            ++AttackIndex;  

			if (0 >= health)
			{
				return -1;
			}
        }
        else    
		{
			health += bandage[1];
			++HealCount;

			if (HealCount == bandage[0])
			{
				health += bandage[2];
				HealCount = 0;
			}
            
            if (health > MaxHealth)
            {
                health = MaxHealth;
            }
		}
    }
    
    return health;
}