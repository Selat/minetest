#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <list>
#include <vector>
#include <map>

#include "circuit_element.h"
#include "irr_v3d.h"
#include "map.h"
#include "circuit_element_states.h"

class INodeDefManager;
class GameScripting;

class Circuit
{
public:
	Circuit(GameScripting* script);
	void addElement(Map& map, INodeDefManager* ndef, v3s16 pos, const unsigned char* func);
	void removeElement(v3s16 pos);
	void addWire(Map& map, INodeDefManager* ndef, v3s16 pos);
	void removeWire(Map& map, INodeDefManager* ndef, v3s16 pos, MapNode& node);
	void update(float dtime, Map& map,  INodeDefManager* ndef);
	void updateElement(MapNode& node, v3s16 pos, INodeDefManager* ndef, const unsigned char* func);
	void pushElementToQueue(v3s16 pos);
	void processElementsQueue(Map& map, INodeDefManager* ndef);
private:
	std::list <CircuitElement> elements;
	std::map <v3s16, std::list<CircuitElement>::iterator> pos_to_iterator;
	std::vector <v3s16> elements_queue;
	CircuitElementStates circuit_element_states;
	GameScripting* m_script;
	float m_min_update_delay;
	float m_since_last_update;
};

#endif