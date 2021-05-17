/// <summary>
/// Game-specific code for the native plugin
/// </summary>
/// <author>
/// Jackson Dunstan, 2017, http://JacksonDunstan.com
/// </author>
/// <license>
/// MIT
/// </license>

#include "Universal.h"
#include "Bindings.h"
#include "Game.h"
#include "World.h"

Game* Game::s_Instance = nullptr;

Game* Game::Get()
{
	if (s_Instance == nullptr)
	{
		s_Instance = new Game();
	}

	return s_Instance;
}

Game::Game()
{
	m_World = std::make_unique<World>();
}

void Game::Init()
{
	m_World->Init();
}

void Game::Update(float deltaTime)
{
	m_World->Update(deltaTime);
}

World* Game::GetCurrentWorld()
{
	return m_World.get();
}

void Game::SetRawInitialGameState(void* initialGameState)
{
	m_RawInitialGameState = (RawInitialGameState*)initialGameState;
}

const RawInitialGameState* Game::GetRawInitialGameState()
{
	return m_RawInitialGameState;
}

#if UNITY_NATIVE_DLL
void Game::SetEventHub(Native::EventHub eventHub)
{
	m_EventHub = eventHub;
}

Native::EventHub Game::GetEventHub()
{
	return m_EventHub;
}
#endif
