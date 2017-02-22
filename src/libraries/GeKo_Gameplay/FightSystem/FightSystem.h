#pragma once

#include"GeKo_Gameplay/Object/Object.h"
#include"GeKo_Gameplay/Object/Geko.h"
#include"GeKo_Gameplay/Object/AI.h"

#include "GeKo_Graphics/ParticleSystem/ParticleSystem.h"


class FightSystem : public Subject<FightSystem, Quest_Event>
{
public:
	FightSystem();
	FightSystem(ParticleSystem* ps);
	~FightSystem();

	void setParticle(ParticleSystem* ps);
	ParticleSystem* getParticle();

	///Two objects will fight against each other
	/**The two objects should have a healt-attribute and a strenght-attribute. 
	The healt- attribute will be changed with this method*/
	void objectVSobject(Object* o1, Object* o2);

protected:
	ParticleSystem* m_fightParticle;

};