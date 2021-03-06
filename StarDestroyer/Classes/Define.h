enum ObjectType
{
	TYPE_WORLD				= 0x00000001,
	TYPE_PLAYER				= 0x00000002,
	TYPE_ENEMY				= 0x00000004,
	TYPE_PLAYER_BULLET		= 0x00000008,
	TYPE_ENEMY_BULLET		= 0x00000010,
	TYPE_WEAPON				= 0x00000020,
	TYPE_SHIELD				= 0x00000040,
};


enum Gategorybitmask
{
	GATEGORYBITMASK_WORLD			= 0x00000001,
	GATEGORYBITMASK_PLAYER			= 0x00000002,
	GATEGORYBITMASK_ENEMY			= 0x00000004,
	GATEGORYBITMASK_ITEM			= 0x00000008,
};


enum Collisionbitmask
{
	COLLISIONBITMASK_WORLD				= 0x0000000E,
	COLLISIONBITMASK_PLAYER				= 0x0000000D,
	COLLISIONBITMASK_ENEMY				= 0x00000003,
	COLLISIONBITMASK_PLAYER_BULLET		= 0x00000005,
	COLLISIONBITMASK_ENEMY_BULLET		= 0x00000003,
	COLLISIONBITMASK_ITEM				= 0x00000003,
	COLLISIONBITMASK_SHIELD				= 0x00000004,
};
