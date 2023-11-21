#include "freeze.h"

// Most of them are unimportant But because I'm lazy, I copy them the same every time LMAO!
#include <engine/graphics.h>
#include <engine/shared/config.h>

#include <game/client/animstate.h>
#include <game/client/render.h>
#include <game/generated/client_data.h>
#include <game/generated/protocol.h>
#include <game/client/gameclient.h>

void CFreezeDetector::OnRender()
{
	static bool aWasFrozen[MAX_CLIENTS] = {false};

	int localTeam = m_pClient->m_aClients[m_pClient->m_Snap.m_LocalClientID].m_Team;

	for(int i = 0; i < MAX_CLIENTS; ++i)
	{
		if(!g_Config.m_ClDetectFreezeAllPlayers && (!g_Config.m_ClDetectFreezeTeamPlayers || m_pClient->m_aClients[i].m_Team != localTeam))
			continue;

		bool isFrozen = m_pClient->m_aClients[i].m_FreezeEnd != 0;

		if(isFrozen && !aWasFrozen[i])
		{
			Console()->ExecuteLine("cl_message_client_color red");
			char aBuf[256];
			str_format(aBuf, sizeof(aBuf), "echo %s is frozen", m_pClient->m_aClients[i].m_aName);
			Console()->ExecuteLine(aBuf);
		}
		else if(!isFrozen && aWasFrozen[i])
		{
			Console()->ExecuteLine("cl_message_client_color green");
			char aBuf[256];
			str_format(aBuf, sizeof(aBuf), "echo %s is unfrozen", m_pClient->m_aClients[i].m_aName);
			Console()->ExecuteLine(aBuf);
		}

		aWasFrozen[i] = isFrozen;
	}
}
