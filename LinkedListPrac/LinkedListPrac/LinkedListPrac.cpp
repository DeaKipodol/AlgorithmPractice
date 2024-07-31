#include <cstddef>
struct Enemy
{
	int x;
	int y;
	int weapon_power;
	Enemy* p_next_enemy;
};
Enemy* p_enemie = NULL;
Enemy* getNewEnemy(Enemy *p_list) {
	Enemy* p_ship = new Enemy;
	p_ship->x = 0;
	p_ship->y = 0;
	p_ship->weapon_power = 20;
	p_ship->p_next_enemy = p_list;
	//p_list = p_ship;
	return p_ship;

}

void upgradeWeapons(Enemy* p) {
	p->weapon_power += 10;
}
int main() {
	Enemy* p = getNewEnemy(p_enemie);
	upgradeWeapons(p);
}