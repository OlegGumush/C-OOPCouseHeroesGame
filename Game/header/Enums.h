#pragma once

enum ECharacter  { ARCHER , WIZARD , WARRIOR , ENEMY , ELITE};
enum EPotion { LIFE, MANA };
enum EWeapon { BOW, CROSSBOW, STAFF, WAND, HAMMER, SWORD , ONE_HAND , TWO_HAND };
enum EGender { MALE , FEMALE };
enum EModeOfLife { ALIVE, DEAD , FINISH };
enum EItems { WEAPON , ARMOR , POTION};
enum EArmor { BODY_ARMOR , SHIELD_ARMOR };

#define GLOB_MAX_LIFE 100

#define GLOB_AMOUNT_OF_LIFE 100
#define GLOB_AMOUNT_OF_START_DEFENCE 1

#define GLOB_ITEM 'I'
#define GLOB_POTION 'P'
#define GLOB_WEAPON 'W'
#define GLOB_ARMOR 'S'
#define GLOB_ENEMY 'E'
#define GLOB_ELITE 'L'
#define GLOB_WARRIOR 'A'
#define GLOB_ARCHER 'R'
#define GLOB_WIZARD 'Z'
#define GLOB_ERROR 'E'
#define GLOB_END_OF_FILE "_out.csv"

#define GLOB_ARCHER_RADIUS 5
#define GLOB_WARRIOR_RADIUS 3
#define GLOB_WIZARD_RADIUS 3

#define GLOB_ZERO 48
#define GLOB_NINE 57
#define GLOB_COMMA ',' 
#define GLOB_EMPTY '.'
#define GLOB_SPACE ' '
#define GLOB_SLASH '/'
#define GLOB_KAV '_'

#define GLOB_TWO_HAND_WEAPON_POWER 1.6
#define GLOB_ONE_HAND_WEAPON_POWER 1.2

#define GLOB_SWITCH_WEAPON_SHIELD 0.85
