﻿// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/***********************************************************************************
**
** ConfigManager.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "stdafx.h"
//----------------------------------------------------------------------------------
CConfigManager g_ConfigManager;
CConfigManager g_OptionsConfig;
//----------------------------------------------------------------------------------
CConfigManager::CConfigManager()
{
	WISPFUN_DEBUG("c138_f1");
	Init();
}
//----------------------------------------------------------------------------------
/*!
Инициализация
@return 
*/
void CConfigManager::Init()
{
	WISPFUN_DEBUG("c138_f2");
	DefaultPage1();

	DefaultPage2();
	
	DefaultPage3();

	DefaultPage4();

	DefaultPage6();

	DefaultPage7();
	
	DefaultPage8();
	
	DefaultPage9();

	g_CircleOfTransparency.Create(CircleTransRadius);

	FilterPWOn = false;
	ObscenityFilter = false;
	FilterPassword = "";
	
	ToggleBufficonWindow = true;

	GameWindowX = 0;
	GameWindowY = 0;

	if (g_PacketManager.GetClientVersion() >= CV_70331)
		g_MaxViewRange = MAX_VIEW_RANGE_NEW;
	else
		g_MaxViewRange = MAX_VIEW_RANGE_OLD;

	UpdateRange = g_MaxViewRange;
}
//---------------------------------------------------------------------------
void CConfigManager::DefaultPage1()
{
	WISPFUN_DEBUG("c138_f3");
	m_Sound = true;
	m_Music = true;
	FootstepsSound = true;
	CombatMusic = true;
	m_SoundVolume = 255;
	m_MusicVolume = 255;
	BackgroundSound = true;
}
//---------------------------------------------------------------------------
void CConfigManager::DefaultPage2()
{
	WISPFUN_DEBUG("c138_f4");
	m_ClientFPS = 60;
	StandartCharactersAnimationDelay = false;
	StandartItemsAnimationDelay = true;
	RemoveTextWithBlending = true;
	m_DrawStatusState = DCSS_NO_DRAW;
	DrawStatusConditionState = DCSCS_LOWER;
	DrawStatusConditionValue = 70;
	m_DrawStumps = false;
	m_MarkingCaves = false;
	m_NoVegetation = false;
	m_NoAnimateFields = false;
	LockGumpsMoving = true;
	m_ConsoleNeedEnter = false;
	HiddenCharactersRenderMode = 0;
	HiddenAlpha = 0x7F;
	UseHiddenModeOnlyForSelf = true;
	TransparentSpellIcons = true;
	m_SpellIconAlpha = 0x7F;
	m_OldStyleStatusbar = false;
	m_ApplyStateColorOnCharacters = false;
	m_OriginalPartyStatusbar = false;
	m_ChangeFieldsGraphic = false;
	m_PaperdollSlots = true;
	RemoveStatusbarsWithoutObjects = false;
	ShowDefaultConsoleEntryMode = true;
	m_DrawAuraState = DAS_NEVER;
	DrawAuraWithCtrlPressed = true;
	ScreenshotFormat = SF_PNG;
	m_ScaleImagesInPaperdollSlots = true;
	RemoveOrCreateObjectsWithBlending = true;
	DrawHelmetsOnShroud = false;
	m_UseGlobalMapLayer = false;
	m_NoDrawRoofs = false;
	HighlightTargetByType = true;
	AutoDisplayWorldMap = false;
	m_UseGLListsForInterface = false;
	CheckPing = true;
	m_PingTimer = 10;
	CancelNewTargetSystemOnShiftEsc = false;
	DrawStatusForHumanoids = true;
}
//---------------------------------------------------------------------------
void CConfigManager::DefaultPage3()
{
	WISPFUN_DEBUG("c138_f5");
	UseToolTips = true;
	ToolTipsTextColor = 0xFFFF;
	ToolTipsTextFont = 0;
	ToolTipsDelay = 200;
}
//---------------------------------------------------------------------------
void CConfigManager::DefaultPage4()
{
	WISPFUN_DEBUG("c138_f6");
	ChatColorInputText = 0xFFFF;
	ChatColorMenuOption = 0xFFFF;
	ChatColorPlayerInMemberList = 0xFFFF;
	ChatColorText = 0xFFFF;
	ChatColorPlayerNameWithout = 0xFFFF;
	ChatColorMuted = 0xFFFF;
	ChatColorChannelModeratorName = 0xFFFF;
	ChatColorChannelModeratorText = 0xFFFF;
	ChatColorMyName = 0xFFFF;
	ChatColorMyText = 0xFFFF;
	ChatColorSystemMessage = 0xFFFF;
	ChatColorBGOutputText = 0xFFFF;
	ChatColorBGInputText = 0xFFFF;
	ChatColorBGUserList = 0xFFFF;
	ChatColorBGConfList = 0xFFFF;
	ChatColorBGCommandList = 0xFFFF;
	
	ChatFont = 0;
}
//---------------------------------------------------------------------------
void CConfigManager::DefaultPage6()
{
	WISPFUN_DEBUG("c138_f7");
	EnablePathfind = true;
	HoldTabForCombat = true;
	OffsetInterfaceWindows = true;
	AutoArrange = true;
	AlwaysRun = false;
	DisableMenubar = false;
	GrayOutOfRangeObjects = false;
	DisableNewTargetSystem = true;
	m_ItemPropertiesMode = OPM_FOLLOW_MOUSE;
	m_ItemPropertiesIcon = false;
	HoldShiftForContextMenus = false;
	HoldShiftForEnablePathfind = false;
	m_CharacterBackpackStyle = CBS_DEFAULT;
}
//---------------------------------------------------------------------------
void CConfigManager::DefaultPage7()
{
	WISPFUN_DEBUG("c138_f8");
	GameWindowWidth = 800;
	GameWindowHeight = 600;
	SpeechDelay = 500;
	ScaleSpeechDelay = true;
	SpeechColor = 0x02B2;
	EmoteColor = 0x0021;
	PartyMessageColor = 0x0044;
	GuildMessageColor = 0x0044;
	AllianceMessageColor = 0x0057;
	IgnoreGuildMessage = false;
	IgnoreAllianceMessage = false;
	DarkNights = false;
	ColoredLighting = true;
	LockResizingGameWindow = false;
}
//---------------------------------------------------------------------------
void CConfigManager::DefaultPage8()
{
	WISPFUN_DEBUG("c138_f9");
	InnocentColor = 0x005A;
	FriendlyColor = 0x0044;
	SomeoneColor = 0x03B2;
	CriminalColor = 0x03B2;
	EnemyColor = 0x0031;
	MurdererColor = 0x0023;
	CriminalActionsQuery = true;
}
//---------------------------------------------------------------------------
void CConfigManager::DefaultPage9()
{
	WISPFUN_DEBUG("c138_f10");
	ShowIncomingNames = true;
	UseCircleTrans = false;
	StatReport = true;
	CircleTransRadius = 64;
	SkillReport = 1;
	SpeechFont = 0;
}
//---------------------------------------------------------------------------
void CConfigManager::UpdateFeatures()
{
	SetDrawStatusState(m_DrawStatusState);
	SetDrawStumps(m_DrawStumps);
	SetMarkingCaves(m_MarkingCaves);
	SetNoVegetation(m_NoVegetation);
	SetNoAnimateFields(m_NoAnimateFields);
	SetApplyStateColorOnCharacters(m_ApplyStateColorOnCharacters);
	SetChangeFieldsGraphic(m_ChangeFieldsGraphic);
	SetDrawAuraState(m_DrawAuraState);
	SetNoDrawRoofs(m_NoDrawRoofs);
}
//---------------------------------------------------------------------------
void CConfigManager::SetSound(bool val)
{
	WISPFUN_DEBUG("c138_f11");

	m_Sound = val;

	if (this == &g_ConfigManager && !val)
		g_Orion.AdjustSoundEffects(g_Ticks + 100000);
}
//---------------------------------------------------------------------------
void CConfigManager::SetMusic(bool val)
{
	WISPFUN_DEBUG("c138_f12");

	m_Music = val;

	if (this == &g_ConfigManager && !val)
	{
		g_SoundManager.StopMusic();
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetSoundVolume(uchar val)
{
	WISPFUN_DEBUG("c138_f13");
	if (this == &g_ConfigManager && m_SoundVolume != val)
		g_Orion.AdjustSoundEffects(g_Ticks + 100000, val);

	m_SoundVolume = val;
}
//---------------------------------------------------------------------------
void CConfigManager::SetMusicVolume(uchar val)
{
	WISPFUN_DEBUG("c138_f14");

	if (this == &g_ConfigManager && m_MusicVolume != val)
	{
		m_MusicVolume = val;
		g_SoundManager.SetMusicVolume(g_SoundManager.GetVolumeValue(-1, true));
	}
	else
		m_MusicVolume = val;
}
//---------------------------------------------------------------------------
void CConfigManager::SetClientFPS(uchar val)
{
	WISPFUN_DEBUG("c138_f15");
	m_ClientFPS = val;

	if (this == &g_ConfigManager)
	{
		if (m_ClientFPS < MIN_FPS_LIMIT)
			m_ClientFPS = MIN_FPS_LIMIT;
		else if (m_ClientFPS > MAX_FPS_LIMIT)
			m_ClientFPS = MAX_FPS_LIMIT;

		g_FrameDelay = 1000 / m_ClientFPS;

		g_OrionWindow.SetRenderTimerDelay(g_FrameDelay);
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetDrawStatusState(uchar val)
{
	WISPFUN_DEBUG("c138_f17");
	uchar state = val;

	if (!(g_OrionFeaturesFlags & OFF_DRAW_CHARACTERS_STATUS_IN_WORLD))
		state = DCSS_NO_DRAW;

	if (this == &g_ConfigManager)
	{
		if (state && !m_DrawStatusState)
		{
			QFOR(item, g_World->m_Items, CGameObject*)
			{
				if (item->NPC)
					CPacketStatusRequest(item->Serial).Send();
			}
		}
	}

	m_DrawStatusState = state;
}
//---------------------------------------------------------------------------
void CConfigManager::SetDrawStumps(bool val)
{
	WISPFUN_DEBUG("c138_f18");
	bool state = val;

	if (!(g_OrionFeaturesFlags & OFF_CHANGE_TREES_TO_STUMPS))
		state = false;

	if (m_DrawStumps != state && this == &g_ConfigManager)
		g_Orion.ClearTreesTextures();

	m_DrawStumps = state;
}
//---------------------------------------------------------------------------
void CConfigManager::SetMarkingCaves(bool val)
{
	WISPFUN_DEBUG("c138_f19");
	bool state = val;

	if (!(g_OrionFeaturesFlags & OFF_MARKING_CAVES))
		state = false;

	if (m_MarkingCaves != state && this == &g_ConfigManager)
		g_Orion.ClearCaveTextures();

	m_MarkingCaves = state;
}
//---------------------------------------------------------------------------
void CConfigManager::SetNoVegetation(bool val)
{
	WISPFUN_DEBUG("c138_f19");
	bool state = val;

	if (!(g_OrionFeaturesFlags & OFF_NO_VEGETATION))
		state = false;

	m_NoVegetation = state;
}
//---------------------------------------------------------------------------
void CConfigManager::SetNoAnimateFields(bool val)
{
	WISPFUN_DEBUG("c138_f19");
	bool state = val;

	if (!(g_OrionFeaturesFlags & OFF_NO_FIELDS_ANIMATION))
		state = false;

	m_NoAnimateFields = state;
}
//---------------------------------------------------------------------------
void CConfigManager::SetApplyStateColorOnCharacters(bool val)
{
	WISPFUN_DEBUG("c138_f19");
	bool state = val;

	if (!(g_OrionFeaturesFlags & OFF_COLORED_CHARACTERS_STATE))
		state = false;

	m_ApplyStateColorOnCharacters = state;
}
//---------------------------------------------------------------------------
void CConfigManager::SetDrawAuraState(uchar val)
{
	WISPFUN_DEBUG("c138_f19");
	uchar state = val;

	if (!(g_OrionFeaturesFlags & OFF_DRAW_AURA))
		state = DAS_NEVER;

	m_DrawAuraState = state;
}
//---------------------------------------------------------------------------
void CConfigManager::SetConsoleNeedEnter(bool val)
{
	WISPFUN_DEBUG("c138_f21");
	if (this == &g_ConfigManager && val && g_EntryPointer == &g_GameConsole)
		g_EntryPointer = NULL;

	m_ConsoleNeedEnter = val;
}
//---------------------------------------------------------------------------
void CConfigManager::SetSpellIconAlpha(uchar val)
{
	WISPFUN_DEBUG("c138_f22");
	if (this == &g_ConfigManager && val != m_SpellIconAlpha)
	{
		float alpha = val / 255.0f;
		bool redraw = g_ConfigManager.TransparentSpellIcons;

		QFOR(gump, g_GumpManager.m_Items, CGump*)
		{
			if (gump->GumpType == GT_SPELL)
			{
				((CGumpSpell*)gump)->m_Blender->Alpha = alpha;

				if (redraw)
					gump->WantRedraw = true;
			}
		}
	}

	m_SpellIconAlpha = val;
}
//---------------------------------------------------------------------------
void CConfigManager::SetOldStyleStatusbar(bool val)
{
	WISPFUN_DEBUG("c138_f23");

	m_OldStyleStatusbar = val;

	if (this == &g_ConfigManager)
	{
		CGump *gump = g_GumpManager.UpdateGump(g_PlayerSerial, 0, GT_STATUSBAR);

		if (gump != NULL && !gump->Minimized)
			gump->WantUpdateContent = true;
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetOriginalPartyStatusbar(bool val)
{
	WISPFUN_DEBUG("c138_f24");
	m_OriginalPartyStatusbar = val;

	if (this == &g_ConfigManager)
	{
		if (g_Party.Leader != 0)
		{
			QFOR(gump, g_GumpManager.m_Items, CGump*)
			{
				if (gump->GumpType == GT_STATUSBAR && (g_Party.Leader == gump->Serial || g_Party.Contains(gump->Serial)))
				{
					gump->WantRedraw = true;
					gump->WantUpdateContent = true;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetChangeFieldsGraphic(bool val)
{
	WISPFUN_DEBUG("c138_f25");
	m_ChangeFieldsGraphic = val;

	if (!(g_OrionFeaturesFlags & OFF_TILED_FIELDS))
		m_ChangeFieldsGraphic = false;

	if (this == &g_ConfigManager && g_World != NULL)
	{
		QFOR(item, g_World->m_Items, CGameObject*)
		{
			if (!item->NPC)
				((CGameItem*)item)->CalculateFieldColor();
		}
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetPaperdollSlots(bool val)
{
	WISPFUN_DEBUG("c138_f26");

	m_PaperdollSlots = val;

	if (this == &g_ConfigManager && g_World != NULL)
	{
		QFOR(gump, g_GumpManager.m_Items, CGump*)
		{
			if (gump->GumpType == GT_PAPERDOLL)
			{
				gump->WantRedraw = true;
				gump->WantUpdateContent = true;
			}
		}
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetScaleImagesInPaperdollSlots(bool val)
{
	WISPFUN_DEBUG("c138_f27");

	m_ScaleImagesInPaperdollSlots = val;

	if (this == &g_ConfigManager && g_World != NULL)
	{
		QFOR(gump, g_GumpManager.m_Items, CGump*)
		{
			if (gump->GumpType == GT_PAPERDOLL)
			{
				gump->WantRedraw = true;
				gump->WantUpdateContent = true;
			}
		}
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetUseGlobalMapLayer(bool val)
{
	WISPFUN_DEBUG("c138_f28");

	m_UseGlobalMapLayer = val;

	if (this == &g_ConfigManager && val)
	{
		QFOR(gump, g_GumpManager.m_Items, CGump*)
		{
			if (gump->GumpType == GT_WORLD_MAP)
				g_GumpManager.MoveToFront(gump);
		}
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetNoDrawRoofs(bool val)
{
	WISPFUN_DEBUG("c138_f28");
	m_NoDrawRoofs = val;

	if (!(g_OrionFeaturesFlags & OFF_TILED_FIELDS))
		m_NoDrawRoofs = false;

	if (this == &g_ConfigManager && g_Player != NULL)
	{
		g_Player->OldX = 0;
		g_Player->OldY = 0;
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetUseGLListsForInterface(bool val)
{
	WISPFUN_DEBUG("c138_f26");

	bool old = m_UseGLListsForInterface;
	m_UseGLListsForInterface = (val || !g_GL.CanUseFrameBuffer);

	if (this == &g_ConfigManager && g_World != NULL && old != m_UseGLListsForInterface)
	{
		QFOR(gump, g_GumpManager.m_Items, CGump*)
		{
			gump->WantRedraw = true;
			gump->WantUpdateContent = true;
		}
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetPingTimer(uchar val)
{
	WISPFUN_DEBUG("c138_f26");

	m_PingTimer = max(min(val, 120), 10);
	g_PingTimer = 0;
}
//---------------------------------------------------------------------------
void CConfigManager::SetItemPropertiesMode(uchar val)
{
	WISPFUN_DEBUG("c138_f26_1");

	m_ItemPropertiesMode = val;

	if (this == &g_ConfigManager && g_World != NULL)
	{
		CGumpPropertyIcon *gump = (CGumpPropertyIcon*)g_GumpManager.UpdateContent(0, 0, GT_PROPERTY_ICON);

		if (gump != NULL && (val == OPM_AT_ICON || val == OPM_ALWAYS_UP))
			gump->SetText(gump->GetText());

		g_ObjectPropertiesManager.Reset();
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetItemPropertiesIcon(bool val)
{
	WISPFUN_DEBUG("c138_f26_2");

	m_ItemPropertiesIcon = val;

	if (this == &g_ConfigManager && g_World != NULL)
	{
		if (val)
		{
			CGump *gump = g_GumpManager.UpdateContent(0, 0, GT_PROPERTY_ICON);

			if (gump == NULL)
			{
				WISP_GEOMETRY::CSize windowSize = g_OrionWindow.GetSize();

				int x = GameWindowX + (int)(GameWindowWidth * 0.9f);
				int y = GameWindowY + GameWindowHeight;

				if (x + 100 >= windowSize.Width)
					x = windowSize.Width - 100;

				if (y + 60 >= windowSize.Height)
					y = windowSize.Height - 60;

				g_GumpManager.AddGump(new CGumpPropertyIcon(x, y));
			}
		}
		else
		{
			g_GumpManager.CloseGump(0, 0, GT_PROPERTY_ICON);
			g_ObjectPropertiesManager.Reset();
		}
	}
}
//---------------------------------------------------------------------------
void CConfigManager::SetCharacterBackpackStyle(uchar val)
{
	WISPFUN_DEBUG("c138_f26_3");

	m_CharacterBackpackStyle = val;

	if (this == &g_ConfigManager && g_World != NULL)
	{
		g_GumpManager.UpdateContent(g_PlayerSerial, 0, GT_PAPERDOLL);

		CGameItem *backpack = g_Player->FindLayer(OL_BACKPACK);

		if (backpack != NULL)
			g_GumpManager.UpdateContent(backpack->Serial, 0, GT_CONTAINER);
	}
}
//---------------------------------------------------------------------------
/*!
Получить цвет исходя из "злобности"
@param [__in] notoriety Злобность
@return Индекс цвета
*/
ushort CConfigManager::GetColorByNotoriety(uchar notoriety)
{
	WISPFUN_DEBUG("c138_f29");
	ushort color = 0;

	switch ((NOTORIETY_TYPE)notoriety)
	{
		case NT_INNOCENT: //Blue
		{
			color = InnocentColor;
			break;
		}
		case NT_FRIENDLY: //Green
		{
			color = FriendlyColor;
			break;
		}
		case NT_SOMEONE_GRAY: //Someone gray
		{
			color = SomeoneColor;
			break;
		}
		case NT_CRIMINAL: //Criminal
		{
			color = CriminalColor;
			break;
		}
		case NT_ENEMY: //Orange
		{
			color = EnemyColor;
			break;
		}
		case NT_MURDERER: //Red*
		{
			color = MurdererColor;
			break;
		}
		case NT_INVULNERABLE:
		{
			color = 0x0034;
			break;
		}
		default: break;
	}

	return color;
}
//---------------------------------------------------------------------------
int CConfigManager::GetConfigKeyCode(const string &key)
{
	WISPFUN_DEBUG("");

	static const string keys[CMKC_COUNT] =
	{
		"Sound",
		"SoundVolume",
		"Music",
		"MusicVolume",
		"FootstepsSound",
		"CombatMusic",
		"BackgroundSound",
		"ClientFPS",
		"RemoveTextWithBlending",
		"DrawStatusState",
		"DrawStumps",
		"MarkingCaves",
		"NoAnimateFields",
		"NoVegetation",
		"HiddenCharactersRenderMode",
		"HiddenAlpha",
		"UseHiddenModeOnlyForSelf",
		"TransparentSpellIcons",
		"SpellIconAlpha",
		"OldStyleStatusbar",
		"OriginalPartyStatusbar",
		"ApplyStateColorOnCharacters",
		"ChangeFieldsGraphic",
		"PaperdollSlots",
		"DrawStatusConditionState",
		"DrawStatusConditionValue",
		"RemoveStatusbarsWithoutObjects",
		"ShowDefaultConsoleEntryMode",
		"DrawAuraState",
		"DrawAuraWithCtrlPressed",
		"ScreenshotFormat",
		"ScaleImagesInPaperdollSlots",
		"RemoveOrCreateObjectsWithBlending",
		"DrawHelmetsOnShroud",
		"UseGlobalMapLayer",
		"NoDrawRoofs",
		"HighlightTargetByType",
		"AutoDisplayWorldMap",
		"UseGLListsForInterface",
		"UseToolTips",
		"ToolTipsTextColor",
		"ToolTipsTextFont",
		"ToolTipsDelay",
		"ChatColorInputText",
		"ChatColorMenuOption",
		"ChatColorPlayerInMemberList",
		"ChatColorText",
		"ChatColorPlayerNameWithout",
		"ChatColorMuted",
		"ChatColorChannelModeratorName",
		"ChatColorChannelModeratorText",
		"ChatColorMyName",
		"ChatColorMyText",
		"ChatColorSystemMessage",
		"ChatFont",
		"ChatColorBGOutputText",
		"ChatColorBGInputText",
		"ChatColorBGUserList",
		"ChatColorBGConfList",
		"ChatColorBGCommandList",
		"EnablePathfind",
		"HoldTabForCombat",
		"OffsetInterfaceWindows",
		"AutoArrange",
		"AlwaysRun",
		"DisableMenubar",
		"GrayOutOfRangeObjects",
		"DisableNewTargetSystem",
		"ItemPropertiesMode",
		"ItemPropertiesIcon",
		"HoldShiftForContextMenus",
		"HoldShiftForEnablePathfind",
		"ContainerDefaultX",
		"ContainerDefaultY",
		"GameWindowWidth",
		"GameWindowHeight",
		"SpeechDelay",
		"ScaleSpeechDelay",
		"SpeechColor",
		"EmoteColor",
		"PartyMessageColor",
		"GuildMessageColor",
		"AllianceMessageColor",
		"IgnoreGuildMessage",
		"IgnoreAllianceMessage",
		"DarkNights",
		"ColoredLighting",
		"StandartCharactersAnimationDelay",
		"StandartItemsAnimationDelay",
		"LockResizingGameWindow",
		"LockGumpsMoving",
		"InnocentColor",
		"FriendlyColor",
		"SomeoneColor",
		"CriminalColor",
		"EnemyColor",
		"MurdererColor",
		"CriminalActionsQuery",
		"ShowIncomingNames",
		"UseCircleTrans",
		"StatReport",
		"ConsoleNeedEnter",
		"CircleTransRadius",
		"SkillReport",
		"SpeechFont",
		"GameWindowX",
		"GameWindowY",
		"Zoomed",
		"RealX",
		"RealY",
		"RealWidth",
		"RealHeight",
		"ToggleBufficonWindow",
		"DeveloperMode",
		"LastServer",
		"LastCharacter",
		"CharacterBackpackStyle",
		"CheckPing",
		"PingTimer",
		"CancelNewTargetSystemOnShiftEsc",
		"DrawStatusForHumanoids"
	};

	string str = ToLowerA(key);

	IFOR(i, 0, CMKC_COUNT)
	{
		if (str == ToLowerA(keys[i]))
			return (int)i;
	}

	return -1;
}
//---------------------------------------------------------------------------
bool CConfigManager::Load(const string &path)
{
	WISP_FILE::CTextFileParser file(path, "=", "#;", "");

	bool zoomed = false;
	int windowX = -1;
	int windowY = -1;
	int windowWidth = -1;
	int windowHeight = -1;
	UpdateRange = g_MaxViewRange;

	while (!file.IsEOF())
	{
		std::vector<std::string> strings = file.ReadTokens();

		if (strings.size() >= 2)
		{
			int code = GetConfigKeyCode(strings[0]);

			if (code == -1)
				continue;

			switch (code)
			{
				//Page 1
				case CMKC_SOUND:
					SetSound(ToBool(strings[1]));
					break;
				case CMKC_SOUND_VOLUME:
					m_SoundVolume = atoi(strings[1].c_str());
					break;
				case CMKC_MUSIC:
					SetMusic(ToBool(strings[1]));
					break;
				case CMKC_MUSIC_VOLUME:
					m_MusicVolume = atoi(strings[1].c_str());
					break;
				case CMKC_FOOTSTEPS_SOUND:
					FootstepsSound = ToBool(strings[1]);
					break;
				case CMKC_COMBAT_MUSIC:
					CombatMusic = ToBool(strings[1]);
					break;
				case CMKC_BACKGROUND_SOUND:
					BackgroundSound = ToBool(strings[1]);
					break;

				//Page 2
				case CMKC_CLIENT_FPS:
					SetClientFPS(atoi(strings[1].c_str()));
					break;
				case CMKC_REMOVE_TEXT_WITH_BLENDING:
					RemoveTextWithBlending = ToBool(strings[1]);
					break;
				case CMKC_DRAW_STATUS_STATE:
					m_DrawStatusState = atoi(strings[1].c_str());
					break;
				case CMKC_DRAW_STUMPS:
					SetDrawStumps(ToBool(strings[1]));
					break;
				case CMKC_MARKING_CAVES:
					SetMarkingCaves(ToBool(strings[1]));
					break;
				case CMKC_NO_ANIMATE_FIELDS:
					SetNoAnimateFields(ToBool(strings[1]));
					break;
				case CMKC_NO_VEGETATION:
					SetNoVegetation(ToBool(strings[1]));
					break;
				case CMKC_HIDDEN_CHARACTERS_RENDER_MODE:
					HiddenCharactersRenderMode = atoi(strings[1].c_str());
					break;
				case CMKC_HIDDEN_ALPHA:
					HiddenAlpha = atoi(strings[1].c_str());
					break;
				case CMKC_USE_HIDDEN_MODE_ONLY_FOR_SELF:
					UseHiddenModeOnlyForSelf = ToBool(strings[1]);
					break;
				case CMKC_TRANSPARENT_SPELL_ICONS:
					TransparentSpellIcons = atoi(strings[1].c_str());
					break;
				case CMKC_SPELL_ICON_ALPHA:
					m_SpellIconAlpha = atoi(strings[1].c_str());
					break;
				case CMKC_OLD_STYLE_STATUSBAR:
					m_OldStyleStatusbar = ToBool(strings[1]);
					break;
				case CMKC_ORIGINAL_PARTY_STATUSBAR:
					m_OriginalPartyStatusbar = ToBool(strings[1]);
					break;
				case CMKC_APPLY_STATE_COLOR_ON_CHARACTERS:
					SetApplyStateColorOnCharacters(ToBool(strings[1]));
					break;
				case CMKC_CHANGE_FIELDS_GRAPHIC:
					SetChangeFieldsGraphic(ToBool(strings[1]));
					break;
				case CMKC_PAPERDOLL_SLOTS:
					SetPaperdollSlots(ToBool(strings[1]));
					break;
				case CMKC_DRAW_STATUS_CONDITION_STATE:
					DrawStatusConditionState = atoi(strings[1].c_str());
					break;
				case CMKC_DRAW_STATUS_CONDITION_VALUE:
					DrawStatusConditionValue = atoi(strings[1].c_str());
					break;
				case CMKC_REMOVE_STATUSBARS_WITHOUT_OBJECTS:
					RemoveStatusbarsWithoutObjects = ToBool(strings[1]);
					break;
				case CMKC_SHOW_DEFAULT_CONSOLE_ENTRY_MODE:
					ShowDefaultConsoleEntryMode = ToBool(strings[1]);
					break;
				case CMKC_DRAW_AURA_STATE:
					SetDrawAuraState(atoi(strings[1].c_str()));
					break;
				case CMKC_DRAW_AURA_WITH_CTRL_PRESSED:
					DrawAuraWithCtrlPressed = ToBool(strings[1]);
					break;
				case CMKC_SCREENSHOT_FORMAT:
					ScreenshotFormat = atoi(strings[1].c_str());
					break;
				case CMKC_SCALE_IMAGES_IN_PAPERDOLL_SLOTS:
					SetScaleImagesInPaperdollSlots(ToBool(strings[1]));
					break;
				case CMKC_REMOVE_OR_CREATE_OBJECTS_WITH_BLENDING:
					RemoveOrCreateObjectsWithBlending = ToBool(strings[1]);
					break;
				case CMKC_DRAW_HELMETS_ON_SHROUD:
					DrawHelmetsOnShroud = ToBool(strings[1]);
					break;
				case CMKC_USE_GLOBAL_MAP_LAYER:
					SetUseGlobalMapLayer(ToBool(strings[1]));
					break;
				case CMKC_NO_DRAW_ROOFS:
					SetNoDrawRoofs(ToBool(strings[1]));
					break;
				case CMKC_HIGHLIGHT_TARGET_BY_TYPE:
					HighlightTargetByType = ToBool(strings[1]);
					break;
				case CMKC_AUTO_DISPLAY_WORLD_MAP:
					AutoDisplayWorldMap = ToBool(strings[1]);
					break;
				case CMKC_USE_GL_LISTS_FOR_INTERFACE:
					SetUseGLListsForInterface(ToBool(strings[1]));
					break;
				case CMKC_CHECK_PING:
					CheckPing = ToBool(strings[1]);
					break;
				case CMKC_PING_TIMER:
					SetPingTimer(atoi(strings[1].c_str()));
					break;
				case CMKC_CANCEL_NEW_TARGET_SYSTEM_ON_SHIFT_ESC:
					CancelNewTargetSystemOnShiftEsc = ToBool(strings[1]);
					break;
				case CMKC_DRAW_STATUS_FOR_HUMANOIDS:
					DrawStatusForHumanoids = ToBool(strings[1]);
					break;

				//Page 3
				case CMKC_USE_TOOLTIPS:
					UseToolTips = ToBool(strings[1]);
					break;
				case CMKC_TOOLTIPS_TEXT_COLOR:
					ToolTipsTextColor = atoi(strings[1].c_str());
					break;
				case CMKC_TOOLTIPS_TEXT_FONT:
					ToolTipsTextFont = atoi(strings[1].c_str());
					break;
				case CMKC_TOOLTIPS_DELAY:
					ToolTipsDelay = atoi(strings[1].c_str());
					break;

				//Page 4
				case CMKC_CHAT_COLOR_INPUT_TEXT:
					ChatColorInputText = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_MENU_OPTION:
					ChatColorMenuOption = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_PLAYER_IN_MEMBER_LIST:
					ChatColorPlayerInMemberList = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_TEXT:
					ChatColorText = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_PLAYER_NAME_WITHOUT:
					ChatColorPlayerNameWithout = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_MUTED:
					ChatColorMuted = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_CHANNEL_MODERATOR_NAME:
					ChatColorChannelModeratorName = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_CHANNEL_MODERATOR_TEXT:
					ChatColorChannelModeratorText = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_MY_NAME:
					ChatColorMyName = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_MY_TEXT:
					ChatColorMyText = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_SYSTEM_MESSAGE:
					ChatColorSystemMessage = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_FONT:
					ChatFont = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_BG_OUTPUT_TEXT:
					ChatColorBGOutputText = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_BG_INPUT_TEXT:
					ChatColorBGInputText = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_BG_USER_LIST:
					ChatColorBGUserList = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_BG_CONF_LIST:
					ChatColorBGConfList = atoi(strings[1].c_str());
					break;
				case CMKC_CHAT_COLOR_BG_COMMAND_LIST:
					ChatColorBGCommandList = atoi(strings[1].c_str());
					break;

				//Page 6
				case CMKC_ENABLE_PATHFIND:
					EnablePathfind = ToBool(strings[1]);
					break;
				case CMKC_HOLD_TAB_FOR_COMBAT:
					HoldTabForCombat = ToBool(strings[1]);
					break;
				case CMKC_OFFSET_INTERFACE_WINDOWS:
					OffsetInterfaceWindows = ToBool(strings[1]);
					break;
				case CMKC_AUTO_ARRANGE:
					AutoArrange = ToBool(strings[1]);
					break;
				case CMKC_ALWAYS_RUN:
					AlwaysRun = ToBool(strings[1]);
					break;
				case CMKC_DISABLE_MENUBAR:
					DisableMenubar = ToBool(strings[1]);
					break;
				case CMKC_GRAY_OUT_OF_RANGE_OBJECTS:
					GrayOutOfRangeObjects = ToBool(strings[1]);
					break;
				case CMKC_DISABLE_NEW_TARGET_SYSTEM:
					DisableNewTargetSystem = ToBool(strings[1]);
					break;
				case CMKC_ITEMP_ROPERTIES_MODE:
					m_ItemPropertiesMode = atoi(strings[1].c_str());
					break;
				case CMKC_ITEMP_ROPERTIES_ICON:
					m_ItemPropertiesIcon = ToBool(strings[1]);
					break;
				case CMKC_HOLD_SHIFT_FOR_CONTEXT_MENUS:
					HoldShiftForContextMenus = ToBool(strings[1]);
					break;
				case CMKC_HOLD_SHIFT_FOR_ENABLE_PATHFIND:
					HoldShiftForEnablePathfind = ToBool(strings[1]);
					break;
				case CMKC_CONTAINER_DEFAULT_X:
					g_ContainerRect.DefaultX = atoi(strings[1].c_str());
					break;
				case CMKC_CONTAINER_DEFAULT_Y:
					g_ContainerRect.DefaultY = atoi(strings[1].c_str());
					break;

				//Page 7
				case CMKC_GAME_WINDOW_WIDTH:
					GameWindowWidth = atoi(strings[1].c_str());
					break;
				case CMKC_GAME_WINDOW_HEIGHT:
					GameWindowHeight = atoi(strings[1].c_str());
					break;
				case CMKC_SPEECH_DELAY:
					SpeechDelay = atoi(strings[1].c_str());
					break;
				case CMKC_SCALE_SPEECH_DELAY:
					ScaleSpeechDelay = ToBool(strings[1]);
					break;
				case CMKC_SPEECH_COLOR:
					SpeechColor = atoi(strings[1].c_str());
					break;
				case CMKC_EMOTE_COLOR:
					EmoteColor = atoi(strings[1].c_str());
					break;
				case CMKC_PARTY_MESSAGE_COLOR:
					PartyMessageColor = atoi(strings[1].c_str());
					break;
				case CMKC_GUILD_MESSAGE_COLOR:
					GuildMessageColor = atoi(strings[1].c_str());
					break;
				case CMKC_ALLIANCE_MESSAGE_COLOR:
					AllianceMessageColor = atoi(strings[1].c_str());
					break;
				case CMKC_IGNORE_GUILD_MESSAGE:
					IgnoreGuildMessage = ToBool(strings[1]);
					break;
				case CMKC_IGNORE_ALLIANCE_MESSAGE:
					IgnoreAllianceMessage = ToBool(strings[1]);
					break;
				case CMKC_DARK_NIGHTS:
					DarkNights = ToBool(strings[1]);
					break;
				case CMKC_COLORED_LIGHTING:
					ColoredLighting = ToBool(strings[1]);
					break;
				case CMKC_STANDART_CHARACTERS_ANIMATION_DELAY:
					StandartCharactersAnimationDelay = ToBool(strings[1]);
					break;
				case CMKC_STANDART_ITEMS_ANIMATION_DELAY:
					StandartItemsAnimationDelay = ToBool(strings[1]);
					break;
				case CMKC_LOCK_RESIZING_GAME_WINDOW:
					LockResizingGameWindow = ToBool(strings[1]);
					break;
				case CMKC_LOCK_GUMPS_MOVING:
					LockGumpsMoving = ToBool(strings[1]);
					break;

				//Page 8
				case CMKC_INNOCENT_COLOR:
					InnocentColor = atoi(strings[1].c_str());
					break;
				case CMKC_FRIENDLY_COLOR:
					FriendlyColor = atoi(strings[1].c_str());
					break;
				case CMKC_SOMEONE_COLOR:
					SomeoneColor = atoi(strings[1].c_str());
					break;
				case CMKC_CRIMINAL_COLOR:
					CriminalColor = atoi(strings[1].c_str());
					break;
				case CMKC_ENEMY_COLOR:
					EnemyColor = atoi(strings[1].c_str());
					break;
				case CMKC_MURDERER_COLOR:
					MurdererColor = atoi(strings[1].c_str());
					break;
				case CMKC_CRIMINAL_ACTIONS_QUERY:
					CriminalActionsQuery = ToBool(strings[1]);
					break;

				//Page 9
				case CMKC_SHOW_INCOMING_NAMES:
					ShowIncomingNames = ToBool(strings[1]);
					break;
				case CMKC_USE_CIRCLE_TRANS:
					UseCircleTrans = ToBool(strings[1]);
					break;
				case CMKC_STAT_REPORT:
					StatReport = ToBool(strings[1]);
					break;
				case CMKC_CONSOLE_NEED_ENTER:
					SetConsoleNeedEnter(ToBool(strings[1]));
					break;
				case CMKC_CIRCLE_TRANS_RADIUS:
					CircleTransRadius = atoi(strings[1].c_str());
					g_CircleOfTransparency.Create(CircleTransRadius);
					break;
				case CMKC_SKILL_REPORT:
					SkillReport = atoi(strings[1].c_str());
					break;
				case CMKC_SPEECH_FONT:
					SpeechFont = atoi(strings[1].c_str());
					break;

				//No page
				case CMKC_GAME_WINDOW_X:
					GameWindowX = atoi(strings[1].c_str());
					break;
				case CMKC_GAME_WINDOW_Y:
					GameWindowY = atoi(strings[1].c_str());
					break;
				case CMKC_ZOOMED:
					zoomed = ToBool(strings[1]);
					break;
				case CMKC_REAL_X:
					windowX = atoi(strings[1].c_str());
					break;
				case CMKC_REAL_Y:
					windowY = atoi(strings[1].c_str());
					break;
				case CMKC_REAL_WIDTH:
					windowWidth = atoi(strings[1].c_str());
					break;
				case CMKC_REAL_HEIGHT:
					windowHeight = atoi(strings[1].c_str());
					break;
				case CMKC_TOGGLE_BUFFICON_WINDOW:
					ToggleBufficonWindow = ToBool(strings[1]);
					break;
				case CMKC_DEVELOPER_MODE:
					g_DeveloperMode = (DEVELOPER_MODE)atoi(strings[1].c_str());
					break;
				case CMKC_LAST_SERVER:
					if (g_World == NULL)
						g_ServerList.LastServerName = strings[1];
					break;
				case CMKC_LAST_CHARACTER:
					if (g_World == NULL)
						g_CharacterList.LastCharacterName = strings[1];
					break;
				case CMKC_CHARACTER_BACKPACK_STYLE:
					m_CharacterBackpackStyle = atoi(strings[1].c_str());
					break;
				default:
					break;
			}
		}
	}

	if (GameWindowX < 0)
		GameWindowX = 0;

	if (GameWindowY < 0)
		GameWindowY = 0;

	if (windowX != -1 && windowY != -1 && windowWidth != -1 && windowHeight != -1)
	{
		if (windowX < 0)
			windowX = 0;

		if (windowY < 0)
			windowY = 0;

		if (g_GameState >= GS_GAME)
		{
			if (windowWidth < 640)
				windowWidth = 640;

			if (windowWidth >= GetSystemMetrics(SM_CXSCREEN) - 20)
				windowWidth = GetSystemMetrics(SM_CXSCREEN) - 20;

			if (windowHeight < 480)
				windowHeight = 480;

			if (windowHeight >= GetSystemMetrics(SM_CYSCREEN) - 60)
				windowHeight = GetSystemMetrics(SM_CYSCREEN) - 60;
		}
		else
		{
			windowWidth = 640;
			windowHeight = 480;
		}

		SendMessage(g_OrionWindow.Handle, WM_SYSCOMMAND, SC_RESTORE, 0);

		if (zoomed)
			SendMessage(g_OrionWindow.Handle, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
		else
			SetWindowPos(g_OrionWindow.Handle, NULL, windowX, windowY, windowWidth, windowHeight, 0);

		g_GL.UpdateRect();
	}
	else
	{
		SendMessage(g_OrionWindow.Handle, WM_SYSCOMMAND, SC_RESTORE, 0);
		SendMessage(g_OrionWindow.Handle, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	}

	return PathFileExistsA(path.c_str());
}
//---------------------------------------------------------------------------
void CConfigManager::Save(const string &path)
{
	WISPFUN_DEBUG("");
	WISP_FILE::CTextFileWritter writter(path);

	if (writter.Opened())
	{
		//Page 1
		writter.WriteBool("Sound", m_Sound);
		writter.WriteInt("SoundVolume", m_SoundVolume);
		writter.WriteBool("Music", m_Music);
		writter.WriteInt("MusicVolume", m_MusicVolume);
		writter.WriteBool("FootstepsSound", FootstepsSound);
		writter.WriteBool("CombatMusic", CombatMusic);
		writter.WriteBool("BackgroundSound", BackgroundSound);

		//Page 2
		writter.WriteInt("ClientFPS", m_ClientFPS);
		writter.WriteBool("RemoveTextWithBlending", RemoveTextWithBlending);
		writter.WriteInt("DrawStatusState", m_DrawStatusState);
		writter.WriteBool("DrawStumps", m_DrawStumps);
		writter.WriteBool("MarkingCaves", m_MarkingCaves);
		writter.WriteBool("NoAnimateFields", m_NoAnimateFields);
		writter.WriteBool("NoVegetation", m_NoVegetation);
		writter.WriteInt("HiddenCharactersRenderMode", HiddenCharactersRenderMode);
		writter.WriteInt("HiddenAlpha", HiddenAlpha);
		writter.WriteBool("UseHiddenModeOnlyForSelf", UseHiddenModeOnlyForSelf);
		writter.WriteInt("TransparentSpellIcons", TransparentSpellIcons);
		writter.WriteInt("SpellIconAlpha", m_SpellIconAlpha);
		writter.WriteBool("OldStyleStatusbar", m_OldStyleStatusbar);
		writter.WriteBool("OriginalPartyStatusbar", m_OriginalPartyStatusbar);
		writter.WriteBool("ApplyStateColorOnCharacters", m_ApplyStateColorOnCharacters);
		writter.WriteBool("ChangeFieldsGraphic", m_ChangeFieldsGraphic);
		writter.WriteBool("PaperdollSlots", m_PaperdollSlots);
		writter.WriteInt("DrawStatusConditionState", DrawStatusConditionState);
		writter.WriteInt("DrawStatusConditionValue", DrawStatusConditionValue);
		writter.WriteBool("RemoveStatusbarsWithoutObjects", RemoveStatusbarsWithoutObjects);
		writter.WriteBool("ShowDefaultConsoleEntryMode", ShowDefaultConsoleEntryMode);
		writter.WriteInt("DrawAuraState", m_DrawAuraState);
		writter.WriteBool("DrawAuraWithCtrlPressed", DrawAuraWithCtrlPressed);
		writter.WriteInt("ScreenshotFormat", ScreenshotFormat);
		writter.WriteBool("ScaleImagesInPaperdollSlots", m_ScaleImagesInPaperdollSlots);
		writter.WriteBool("RemoveOrCreateObjectsWithBlending", RemoveOrCreateObjectsWithBlending);
		writter.WriteBool("DrawHelmetsOnShroud", DrawHelmetsOnShroud);
		writter.WriteBool("UseGlobalMapLayer", m_UseGlobalMapLayer);
		writter.WriteBool("NoDrawRoofs", m_NoDrawRoofs);
		writter.WriteBool("HighlightTargetByType", HighlightTargetByType);
		writter.WriteBool("AutoDisplayWorldMap", AutoDisplayWorldMap);
		writter.WriteBool("UseGLListsForInterface", m_UseGLListsForInterface);
		writter.WriteBool("CheckPing", CheckPing);
		writter.WriteInt("PingTimer", m_PingTimer);
		writter.WriteBool("CancelNewTargetSystemOnShiftEsc", CancelNewTargetSystemOnShiftEsc);
		writter.WriteBool("DrawStatusForHumanoids", DrawStatusForHumanoids);

		//Page 3
		writter.WriteBool("UseToolTips", UseToolTips);
		writter.WriteInt("ToolTipsTextColor", ToolTipsTextColor);
		writter.WriteInt("ToolTipsTextFont", ToolTipsTextFont);
		writter.WriteInt("ToolTipsDelay", ToolTipsDelay);

		//Page 4
		writter.WriteInt("ChatColorInputText", ChatColorInputText);
		writter.WriteInt("ChatColorMenuOption", ChatColorMenuOption);
		writter.WriteInt("ChatColorPlayerInMemberList", ChatColorPlayerInMemberList);
		writter.WriteInt("ChatColorText", ChatColorText);
		writter.WriteInt("ChatColorPlayerNameWithout", ChatColorPlayerNameWithout);
		writter.WriteInt("ChatColorMuted", ChatColorMuted);
		writter.WriteInt("ChatColorChannelModeratorName", ChatColorChannelModeratorName);
		writter.WriteInt("ChatColorChannelModeratorText", ChatColorChannelModeratorText);
		writter.WriteInt("ChatColorMyName", ChatColorMyName);
		writter.WriteInt("ChatColorMyText", ChatColorMyText);
		writter.WriteInt("ChatColorSystemMessage", ChatColorSystemMessage);
		writter.WriteInt("ChatFont", ChatFont);
		writter.WriteInt("ChatColorBGOutputText", ChatColorBGOutputText);
		writter.WriteInt("ChatColorBGInputText", ChatColorBGInputText);
		writter.WriteInt("ChatColorBGUserList", ChatColorBGUserList);
		writter.WriteInt("ChatColorBGConfList", ChatColorBGConfList);
		writter.WriteInt("ChatColorBGCommandList", ChatColorBGCommandList);

		//Page 6
		writter.WriteBool("EnablePathfind", EnablePathfind);
		writter.WriteBool("HoldTabForCombat", HoldTabForCombat);
		writter.WriteBool("OffsetInterfaceWindows", OffsetInterfaceWindows);
		writter.WriteBool("AutoArrange", AutoArrange);
		writter.WriteBool("AlwaysRun", AlwaysRun);
		writter.WriteBool("DisableMenubar", DisableMenubar);
		writter.WriteBool("GrayOutOfRangeObjects", GrayOutOfRangeObjects);
		writter.WriteBool("DisableNewTargetSystem", DisableNewTargetSystem);
		writter.WriteInt("ItemPropertiesMode", m_ItemPropertiesMode);
		writter.WriteBool("ItemPropertiesIcon", m_ItemPropertiesIcon);
		writter.WriteBool("HoldShiftForContextMenus", HoldShiftForContextMenus);
		writter.WriteBool("HoldShiftForEnablePathfind", HoldShiftForEnablePathfind);
		writter.WriteInt("ContainerDefaultX", g_ContainerRect.DefaultX);
		writter.WriteInt("ContainerDefaultY", g_ContainerRect.DefaultY);
		writter.WriteInt("CharacterBackpackStyle", GetCharacterBackpackStyle());

		//Page 7
		writter.WriteInt("GameWindowWidth", GameWindowWidth);
		writter.WriteInt("GameWindowHeight", GameWindowHeight);
		writter.WriteInt("SpeechDelay", SpeechDelay);
		writter.WriteBool("ScaleSpeechDelay", ScaleSpeechDelay);
		writter.WriteInt("SpeechColor", SpeechColor);
		writter.WriteInt("EmoteColor", EmoteColor);
		writter.WriteInt("PartyMessageColor", PartyMessageColor);
		writter.WriteInt("GuildMessageColor", GuildMessageColor);
		writter.WriteInt("AllianceMessageColor", AllianceMessageColor);
		writter.WriteBool("IgnoreGuildMessage", IgnoreGuildMessage);
		writter.WriteBool("IgnoreAllianceMessage", IgnoreAllianceMessage);
		writter.WriteBool("DarkNights", DarkNights);
		writter.WriteBool("ColoredLighting", ColoredLighting);
		writter.WriteBool("StandartCharactersAnimationDelay", StandartCharactersAnimationDelay);
		writter.WriteBool("StandartItemsAnimationDelay", StandartItemsAnimationDelay);
		writter.WriteBool("LockResizingGameWindow", LockResizingGameWindow);
		writter.WriteBool("LockGumpsMoving", LockGumpsMoving);

		//Page 8
		writter.WriteInt("InnocentColor", InnocentColor);
		writter.WriteInt("FriendlyColor", FriendlyColor);
		writter.WriteInt("SomeoneColor", SomeoneColor);
		writter.WriteInt("CriminalColor", CriminalColor);
		writter.WriteInt("EnemyColor", EnemyColor);
		writter.WriteInt("MurdererColor", MurdererColor);
		writter.WriteBool("CriminalActionsQuery", CriminalActionsQuery);

		//Page 9
		writter.WriteBool("ShowIncomingNames", ShowIncomingNames);
		writter.WriteBool("UseCircleTrans", UseCircleTrans);
		writter.WriteBool("StatReport", StatReport);
		writter.WriteBool("ConsoleNeedEnter", m_ConsoleNeedEnter);
		writter.WriteInt("CircleTransRadius", CircleTransRadius);
		writter.WriteInt("SkillReport", SkillReport);
		writter.WriteInt("SpeechFont", SpeechFont);

		//No page
		writter.WriteInt("GameWindowX", GameWindowX);
		writter.WriteInt("GameWindowY", GameWindowY);

		writter.WriteBool("Zoomed", g_OrionWindow.Zoomed());

		RECT rect = { 0 };
		GetWindowRect(g_OrionWindow.Handle, &rect);

		writter.WriteInt("RealX", rect.left);
		writter.WriteInt("RealY", rect.top);
		writter.WriteInt("RealWidth", (rect.right - rect.left));
		writter.WriteInt("RealHeight", (rect.bottom - rect.top));

		writter.WriteBool("ToggleBufficonWindow", ToggleBufficonWindow);
		writter.WriteInt("DeveloperMode", g_DeveloperMode);

		writter.WriteString("LastServer", g_ServerList.LastServerName);
		writter.WriteString("LastCharacter", g_CharacterList.LastCharacterName);

		writter.Close();
	}
}
//---------------------------------------------------------------------------