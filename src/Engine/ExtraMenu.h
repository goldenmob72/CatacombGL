// Copyright (C) 2018 Arno Ansems
// 
// This program is free software: you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published by 
// the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version. 
// 
// This program is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
// 
// You should have received a copy of the GNU General Public License 
// along with this program.  If not, see http://www.gnu.org/licenses/ 

//
// ExtraMenu
//
// Offers menu functionality that is not present in the original game, but required
// for setting the various new graphics and controls options.
//
#pragma once

#include <stdint.h>
#include "PlayerInput.h"
#include "AudioPlayer.h"
#include "ConfigurationSettings.h"
#include "IRenderer.h"
#include "EgaGraph.h"
#include "IMenu.h"

class ExtraMenu: public IMenu
{
public:
    ExtraMenu(ConfigurationSettings& configurationSettings, AudioPlayer& audioPlayer, std::vector<std::string>& savedGames);
    bool IsActive() const override;
    void SetActive(bool active) override;
    MenuCommand ProcessInput(const PlayerInput& playerInput) override;
    void Draw(IRenderer& renderer, EgaGraph* const egaGraph, const uint16_t menuCursorPic, const uint32_t timeStamp) override;
    void SetSaveGameEnabled(const bool enabled) override;
    const std::string& GetNewSaveGameName() const override;
    void OpenRestoreGameMenu() override;
    void OpenSaveGameMenu() override;
    void OpenSoundMenu() override;
    void CheckHighScore(const uint16_t level, const uint32_t score) override;

private:
    void MenuDown();
    void MenuUp();
    void MenuLeft();
    void MenuRight();
    MenuCommand EnterKeyPressed();
    static bool KeyIsSuitableForSaveGameName(const SDL_Keycode keyCode);
    bool IsNewSaveGameNameAlreadyInUse() const;

    bool m_menuActive;
    uint8_t m_menuItemSelected;
    uint8_t m_subMenuSelected;
    uint8_t m_menuItemOffset;
	bool m_waitingForKeyToBind;
    bool m_waitingForNewSaveGameName;
    bool m_saveGameEnabled;

    ConfigurationSettings& m_configurationSettings;
    AudioPlayer& m_audioPlayer;
    std::vector<std::string>& m_savedGames;
    std::string m_newSaveGameName;
    bool m_askForOverwrite;
};