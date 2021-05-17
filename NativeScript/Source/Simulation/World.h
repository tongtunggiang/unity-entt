#pragma once


class World
{
public:
	World();
	~World();

	void Update(float deltaTime);
	void Init();

public:
	template<typename EventType, typename ListenerType, void(ListenerType::* member)(const EventType&)>
	void BindEvent(ListenerType* instance)
	{
		m_EventDispatcher.sink<EventType>().template connect<member>(instance);
	}

	template<typename EventType, typename ListenerType>
	void UnbindEvent(ListenerType* instance)
	{
		m_EventDispatcher.sink<EventType>().disconnect(instance);
	}

	template<typename EventType, typename... Args>
	void InvokeEvent(bool invokeImmediately, EventType&& e)
	{
		if (invokeImmediately)
			m_EventDispatcher.trigger(e);
		else
			m_EventDispatcher.enqueue(e);
	}

	inline Registry& GetRegistry() { return m_Registry; }

private:
	Registry m_Registry;
	EventDispatcher m_EventDispatcher;
};
