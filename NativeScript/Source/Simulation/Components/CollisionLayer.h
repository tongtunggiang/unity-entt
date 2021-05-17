#pragma once

namespace ECollisionLayer
{
	enum Values : std::uint8_t
	{
		Enemy,
		Bullet,

		ALL,
	};
}

struct CCollisionLayer
{
	std::uint8_t value;
};

