#pragma once

struct Waypoint
{
	Vector3 position;
	Vector3 direction;
};

/* GAME_SETTINGS_COMPONENT */
struct CWaypointSettings
{
	std::vector<Waypoint> waypoints;
};

