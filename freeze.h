#ifndef GAME_CLIENT_COMPONENTS_FREEZE_H
#define GAME_CLIENT_COMPONENTS_FREEZE_H
#include <game/client/component.h>

class CFreezeDetector : public CComponent
{
public:
	virtual int Sizeof() const override { return sizeof(*this); }
	virtual void OnRender() override;
};

#endif
