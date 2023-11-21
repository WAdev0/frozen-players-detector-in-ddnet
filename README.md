# Frozen Players Detector in DDNet

This project implements a frozen players detector in the DDNet game. It allows you to detect when a player is frozen or unfrozen. The detector can be configured to detect all frozen players or only the players on the same team.

## Prerequisites

Before you begin, make sure you have a clone of DDNet. You can get it from the DDNet GitHub repository.

## Installation

1. Open your command prompt and navigate to the components directory in the DDNet source code:
    ```
    cd src\game\client\components
    ```
2. Clone this repository:
    ```
    git clone https://github.com/WAdev0/frozen-players-detector-in-ddnet
    ```

## Usage

After cloning the repository, the `freeze.cpp` and `freeze.h` files will be in your `src\game\client\components` directory. 

1. Include `components/freeze.h` in `gameclient.cpp` and `gameclient.h`.
2. In `gameclient.h`, add `CFreezeDetector m_FreezeDetector;` in the `CGameClient` class.
3. In `gameclient.cpp`, add `&m_FreezeDetector,` to the list of components.
4. Add the following configurations in `config_variables.h`:
    ```
    MACRO_CONFIG_INT(ClDetectFreezeTeamPlayers, cl_detect_freeze_team_players, 0, 0, 1, CFGFLAG_CLIENT, "Enable or disable freeze detection for team players")
    MACRO_CONFIG_INT(ClDetectFreezeAllPlayers, cl_detect_freeze_all_players, 0, 0, 1, CFGFLAG_CLIENT, "Enable or disable freeze detection for all players")
    ```

You can now use the frozen players detector in DDNet. Use the `ClDetectFreezeTeamPlayers` configuration to enable or disable freeze detection for team players. Use the `ClDetectFreezeAllPlayers` configuration to enable or disable freeze detection for all players.
