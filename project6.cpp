class Monster
{
  public:
     Monster();
     Monster(const int h, const int st, const int d, const int sp);
     ~Monster();
     string getName() const;
     int getHealth() const;
     int getStrength() const;
     int getDefense() const;
     int getSpeed() const;
     void setName(string name);
     void setHealth(int health);
     void setStrength(int strength);
     void setDefense(int defense);
     void setSpeed(int speed);
     void attack(Monster mon);
     void print();
  private: 
     string name;
     int health, strength, defense, speed;
     static const int MAX_HEALTH = 100;
     static const int MAX_STRENGTH = 50;
     static const int MAX_DEFENSE = 100;
     static const int MAX_SPEED = 20;
};
