

#include "stdafx.h"

CMacroManager g_MacroManager;

uchar CMacroManager::m_SkillIndexTable[24] = { 1,  2, 35, 4, 6,  12, 14, 15, 16, 19, 21, 0xFF,
                                               23, 3, 46, 9, 30, 22, 48, 32, 33, 47, 36, 38 };

CMacroManager::CMacroManager()
    : CBaseQueue()
{
}

CMacroManager::~CMacroManager()
{
}

ushort CMacroManager::ConvertStringToKeyCode(const STRING_LIST &strings)
{
    WISPFUN_DEBUG("c145_f1");
    string str = strings[0];

    for (int i = 1; i < (int)strings.size() - 3; i++)
        str += " " + strings[i];

    ushort key = 0;

    if (str.length() == 1)
        key = *str.c_str();
    else if (str.length())
    {
        str = ToUpperA(str);

        if (str == "ESC")
            key = VK_ESCAPE;
        else if (str == "BACKSPACE")
            key = VK_BACK;
        else if (str == "TAB")
            key = VK_TAB;
        else if (str == "ENTER")
            key = VK_RETURN;
        else if (str == "CTRL")
            key = VK_CONTROL;
        else if (str == "ALT")
            key = VK_MENU;
        else if (str == "SHIFT")
            key = VK_SHIFT;
        else if (str == "SPACE")
            key = VK_SPACE;
        else if (str == "CAPS LOCK")
            key = VK_CAPITAL;
        else if (str == "F1")
            key = VK_F1;
        else if (str == "F2")
            key = VK_F2;
        else if (str == "F3")
            key = VK_F3;
        else if (str == "F4")
            key = VK_F4;
        else if (str == "F5")
            key = VK_F5;
        else if (str == "F6")
            key = VK_F6;
        else if (str == "F7")
            key = VK_F7;
        else if (str == "F8")
            key = VK_F8;
        else if (str == "F9")
            key = VK_F9;
        else if (str == "F10")
            key = VK_F10;
        else if (str == "F11")
            key = VK_F11;
        else if (str == "F12")
            key = VK_F12;
        else if (str == "PAUSE")
            key = VK_PAUSE;
        else if (str == "SCROLL LOCK")
            key = VK_SCROLL;
        else if (str == "NUM 0")
            key = VK_NUMPAD0;
        else if (str == "NUM 1")
            key = VK_NUMPAD1;
        else if (str == "NUM 2")
            key = VK_NUMPAD2;
        else if (str == "NUM 3")
            key = VK_NUMPAD3;
        else if (str == "NUM 4")
            key = VK_NUMPAD4;
        else if (str == "NUM 5")
            key = VK_NUMPAD5;
        else if (str == "NUM 6")
            key = VK_NUMPAD6;
        else if (str == "NUM 7")
            key = VK_NUMPAD7;
        else if (str == "NUM 8")
            key = VK_NUMPAD8;
        else if (str == "NUM 9")
            key = VK_NUMPAD9;
        else if (str == "NUM *")
            key = 42;
        else if (str == "NUM -")
            key = 45;
        else if (str == "NUM +")
            key = 43;
        else if (str == "NUM DEL")
            key = 46;
    }

    return key;
}

bool CMacroManager::Convert(const string &path)
{
    WISPFUN_DEBUG("c145_f2");
    WISP_FILE::CTextFileParser file(path, "", "", "");
    WISP_FILE::CTextFileParser unicodeParser("", " ", "", "");

    const int MACRO_POSITION_ALT = 2;
    const int MACRO_POSITION_CTRL = 3;
    const int MACRO_POSITION_SHIFT = 1;

    while (!file.IsEOF())
    {
        vector<string> strings = file.ReadTokens();
        strings = unicodeParser.GetTokens(file.RawLine.c_str(), false);
        size_t size = strings.size();

        if (!size)
            continue;

        if (size < 4 || size > 5)
        {
            LOG("Error!!! Macros converter. Unwaited start args count = %i!!!\n", size);
            continue;
        }

        bool macroAdded = false;

        CMacro *macro = new CMacro(
            ConvertStringToKeyCode(strings),
            atoi(strings[size - MACRO_POSITION_ALT].c_str()),
            atoi(strings[size - MACRO_POSITION_CTRL].c_str()),
            atoi(strings[size - MACRO_POSITION_SHIFT].c_str()));

        string TestLine = "";
        while (!file.IsEOF())
        {
            vector<string> datas = file.ReadTokens();
            TestLine.append(file.RawLine);
            if ((*file.RawLine.c_str() != '\n') && (*file.RawLine.c_str() != '\r') &&
                (file.RawLine != "") && (*file.RawLine.c_str() != '#'))
                continue;
            vector<string> data = unicodeParser.GetTokens(TestLine.c_str(), false);
            TestLine = "";
            if (!data.size())
                continue;

            if (*data[0].c_str() == '#')
            {
                macroAdded = true;

                Add(macro);

                break;
            }
            else if (*data[0].c_str() == '+')
            {
                string raw = data[0].c_str() + 1;
                data[0] = raw;
            }

            string upData = ToUpperA(data[0]);
            MACRO_CODE code = MC_NONE;

            IFOR (i, 0, CMacro::MACRO_ACTION_NAME_COUNT)
            {
                if (upData == ToUpperA(CMacro::m_MacroActionName[i]))
                {
                    code = (MACRO_CODE)i;

                    break;
                }
            }

            if (code != MC_NONE)
            {
                CMacroObject *obj = CMacro::CreateMacro(code);
                if (obj->HaveString())
                {
                    if (data.size() > 1)
                    {
                        string args = data[1];

                        IFOR (i, 2, (int)data.size())
                            args += " " + data[i];

                        ((CMacroObjectString *)obj)->String = args;
                    }
                }
                else if (data.size() > 1)
                {
                    upData = data[1];

                    IFOR (i, 2, (int)data.size())
                        upData += " " + data[i];

                    upData = ToUpperA(upData);

                    IFOR (i, 0, CMacro::MACRO_ACTION_COUNT)
                    {
                        if (upData == ToUpperA(CMacro::m_MacroAction[i]))
                        {
                            obj->SubCode = (MACRO_SUB_CODE)i;

                            break;
                        }
                    }
                }
                macro->Add(obj);
            }
        }

        if (!macroAdded)
            Add(macro);
    }

    return PathFileExistsA(path.c_str());
}

bool CMacroManager::Load(const string &path, const string &originalPath)
{
    WISPFUN_DEBUG("c145_f3");
    bool result = false;
    Clear();

    WISP_FILE::CMappedFile file;

    if (file.Load(path) && file.Size)
    {
        uchar version = file.ReadUInt8();

        short count = file.ReadInt16LE();

        IFOR (i, 0, count)
            Add(CMacro::Load(file));

        result = true;
    }
    else
        result = Convert(originalPath);

    file.Unload();

    return result;
}

void CMacroManager::Save(const string &path)
{
    WISPFUN_DEBUG("c145_f4");
    WISP_FILE::CBinaryFileWriter writer;
    writer.Open(path);

    writer.WriteUInt8(0);

    short count = GetItemsCount();

    writer.WriteInt16LE(count);
    writer.WriteBuffer();

    QFOR(obj, m_Items, CMacro *)
    obj->Save(writer);

    writer.WriteUInt32LE(0);
    writer.WriteBuffer();

    writer.Close();
}

CMacro *CMacroManager::FindMacro(ushort key, bool alt, bool ctrl, bool shift)
{
    WISPFUN_DEBUG("c145_f5");
    CMacro *obj = (CMacro *)m_Items;

    while (obj != NULL)
    {
        if (obj->Key == key && obj->Alt == alt && obj->Ctrl == ctrl && obj->Shift == shift)
            break;

        obj = (CMacro *)obj->m_Next;
    }

    return obj;
}

void CMacroManager::LoadFromOptions()
{
    WISPFUN_DEBUG("c145_f6");
    Clear();
    ChangePointer(NULL);

    QFOR(obj, g_OptionsMacroManager.m_Items, CMacro *)
    Add(obj->GetCopy());
}

void CMacroManager::ChangePointer(CMacroObject *macro)
{
    g_MacroPointer = macro;
}

void CMacroManager::Execute()
{
    WISPFUN_DEBUG("c145_f7");
    while (g_MacroPointer != NULL)
    {
        switch (Process())
        {
            case MRC_STOP:
            {
                ChangePointer(NULL);
                return;
            }
            case MRC_BREAK_PARSER:
                return;
            case MRC_PARSE_NEXT:
            {
                ChangePointer((CMacroObject *)g_MacroPointer->m_Next);
                break;
            }
            default:
                break;
        }
    }
}

void CMacroManager::ProcessSubMenu()
{
    WISPFUN_DEBUG("c145_f8");
    switch (g_MacroPointer->Code)
    {
        case MC_OPEN:
        {
            switch (g_MacroPointer->SubCode)
            {
                case MSC_G2_CONFIGURATION:
                {
                    g_Orion.OpenConfiguration();

                    break;
                }
                case MSC_G2_PAPERDOLL:
                {
                    g_Orion.PaperdollReq(g_PlayerSerial);

                    break;
                }
                case MSC_G2_STATUS:
                {
                    g_Orion.OpenStatus(g_PlayerSerial);

                    break;
                }
                case MSC_G2_JOURNAL:
                {
                    g_Orion.OpenJournal();

                    break;
                }
                case MSC_G2_SKILLS:
                {
                    g_Orion.OpenSkills();

                    break;
                }
                case MSC_G2_MAGE_SPELLBOOK:
                {
                    CPacketOpenSpellbook().Send();

                    break;
                }
                case MSC_G2_CHAT:
                {
                    break;
                }
                case MSC_G2_BACKPACK:
                {
                    CGameItem *backpack = g_Player->FindLayer(OL_BACKPACK);

                    if (backpack != NULL)
                        g_Orion.DoubleClick(backpack->Serial);

                    break;
                }
                case MSC_G2_OWERVIEW:
                {
                    g_Orion.OpenMinimap();

                    break;
                }
                case MSC_G2_WORLD_MAP:
                {
                    g_Orion.OpenWorldMap();

                    break;
                }
                case MSC_G2_MAIL:
                case MSC_G2_PARTY_MANIFEST:
                {
                    g_Orion.OpenPartyManifest();

                    break;
                }
                case MSC_G2_GUILD:
                {
                    CPacketGuildMenuRequest().Send();

                    break;
                }
                case MSC_G2_PARTY_CHAT:
                {
                    break;
                }
                default:
                    break;
            }

            break;
        }
        case MC_CLOSE:
        case MC_MINIMIZE:
        case MC_MAXIMIZE:
        {
            CGump *gump = NULL;

            switch (g_MacroPointer->SubCode)
            {
                case MSC_G2_CONFIGURATION:
                {
                    gump = g_GumpManager.GetGump(0, 0, GT_OPTIONS);

                    g_OptionsMacroManager.Clear();

                    break;
                }
                case MSC_G2_PAPERDOLL:
                {
                    gump = g_GumpManager.GetGump(g_PlayerSerial, 0, GT_PAPERDOLL);

                    break;
                }
                case MSC_G2_STATUS:
                {
                    gump = g_GumpManager.GetGump(g_PlayerSerial, 0, GT_STATUSBAR);

                    break;
                }
                case MSC_G2_JOURNAL:
                {
                    gump = g_GumpManager.GetGump(0, 0, GT_JOURNAL);

                    break;
                }
                case MSC_G2_SKILLS:
                {
                    gump = g_GumpManager.GetGump(0, 0, GT_SKILLS);

                    break;
                }
                case MSC_G2_MAGE_SPELLBOOK:
                {
                    QFOR(item, g_GumpManager.m_Items, CGump *)
                    {
                        if (item->GumpType == GT_SPELLBOOK)
                        {
                            CGameItem *gi = g_World->FindWorldItem(item->Serial);

                            if (gi != NULL)
                            {
                                if (gi->Graphic == 0x0EFA)
                                    gump = item;
                            }

                            if (gump != NULL)
                                break;
                        }
                    }

                    break;
                }
                case MSC_G2_CHAT:
                {
                    gump = g_GumpManager.GetGump(0, 0, GT_CHAT);

                    break;
                }
                case MSC_G2_BACKPACK:
                {
                    CGameItem *backpack = g_Player->FindLayer(OL_BACKPACK);

                    if (backpack != NULL)
                        g_GumpManager.CloseGump(backpack->Serial, 0, GT_SPELLBOOK);

                    break;
                }
                case MSC_G2_OWERVIEW:
                {
                    gump = g_GumpManager.GetGump(0, 0, GT_MINIMAP);

                    break;
                }
                case MSC_G2_MAIL:
                {
                    gump = g_GumpManager.GetGump(0, 0, GT_MAIL);

                    break;
                }
                case MSC_G2_PARTY_MANIFEST:
                {
                    gump = g_GumpManager.GetGump(0, 0, GT_PARTY_MANIFEST);

                    break;
                }
                case MSC_G2_PARTY_CHAT:
                case MSC_G2_GUILD:
                {
                    break;
                }
                default:
                    break;
            }

            if (gump != NULL)
            {
                if (g_MacroPointer->Code == MC_CLOSE)
                    g_GumpManager.RemoveGump(gump);
                else
                {
                    gump->Minimized = (g_MacroPointer->Code == MC_MINIMIZE);

                    gump->WantRedraw = true;
                }
            }

            break;
        }
        default:
            break;
    }
}

MACRO_RETURN_CODE CMacroManager::Process()
{
    MACRO_RETURN_CODE result = MRC_PARSE_NEXT;

    if (g_MacroPointer == NULL)
        result = MRC_STOP;
    else if (m_NextTimer <= g_Ticks)
        result = Process(g_MacroPointer);
    else
        result = MRC_BREAK_PARSER;

    return result;
}

MACRO_RETURN_CODE CMacroManager::Process(CMacroObject *macro)
{
    WISPFUN_DEBUG("c145_f9");
    MACRO_RETURN_CODE result = MRC_PARSE_NEXT;
    static DWORD itemInHand[2] = { 0, 0 };

    switch (macro->Code)
    {
        case MC_SAY:
        case MC_EMOTE:
        case MC_WHISPER:
        case MC_YELL:
        {
            CMacroObjectString *mos = (CMacroObjectString *)macro;

            if (mos->String.length())
            {
                SPEECH_TYPE st = ST_NORMAL;

                switch (macro->Code)
                {
                    case MC_EMOTE:
                    {
                        st = ST_EMOTE;
                        break;
                    }
                    case MC_WHISPER:
                    {
                        st = ST_WHISPER;
                        break;
                    }
                    case MC_YELL:
                    {
                        st = ST_YELL;
                        break;
                    }
                    default:
                        break;
                }

                CPacketUnicodeSpeechRequest(
                    ToWString(mos->String).c_str(),
                    st,
                    3,
                    g_ConfigManager.SpeechColor,
                    (puchar)g_Language.c_str())
                    .Send();
            }

            break;
        }
        case MC_WALK:
        {
            Direction dt = (Direction)DT_NW;

            if (macro->SubCode != MSC_G1_NW)
            {
                dt = (Direction)(macro->Code - 2);

                if (dt >= DIR_INVALID)
                    dt = DIR_NORTH;
            }

            if (!g_PathFinder.AutoWalking)
                g_Player->Walk(dt, false);

            break;
        }
        case MC_WAR_PEACE:
        {
            g_Player->RequestWarMode(WarModeState::Toggle);

            break;
        }
        case MC_PASTE:
        {
            if (g_EntryPointer != NULL)
            {
                if (OpenClipboard(g_OrionWindow.Handle))
                {
                    HANDLE cb = GetClipboardData(CF_TEXT);

                    if (cb != NULL)
                    {
                        char *chBuffer = (char *)GlobalLock(cb);

                        if (chBuffer != NULL && strlen(chBuffer))
                        {
                            wstring str = g_EntryPointer->Data() + ToWString(chBuffer);
                            g_EntryPointer->SetText(str);
                        }

                        GlobalUnlock(cb);
                    }

                    CloseClipboard();
                }
            }

            break;
        }
        case MC_OPEN:
        case MC_CLOSE:
        case MC_MINIMIZE:
        case MC_MAXIMIZE:
        {
            ProcessSubMenu();

            break;
        }
        case MC_OPEN_DOOR:
        {
            g_Orion.OpenDoor();

            break;
        }
        case MC_USE_SKILL:
        {
            int skill = (macro->SubCode - MSC_G3_ANATOMY);

            if (skill >= 0 && skill < 24)
            {
                skill = m_SkillIndexTable[skill];

                if (skill != 0xFF)
                    g_Orion.UseSkill(skill);
            }

            break;
        }
        case MC_LAST_SKILL:
        {
            g_Orion.UseSkill(g_LastSkillIndex);

            break;
        }
        case MC_CAST_SPELL:
        {
            int spell = (macro->SubCode - MSC_G6_CLUMSY) + 1;

            if (spell > 0 && spell <= 151)
            {
                g_Orion.CastSpell(spell);
            }

            break;
        }
        case MC_LAST_SPELL:
        {
            g_Orion.CastSpell(g_LastSpellIndex);

            break;
        }
        case MC_LAST_OBJECT:
        {
            if (g_World->FindWorldObject(g_LastUseObject))
                g_Orion.DoubleClick(g_LastUseObject);

            break;
        }
        case MC_BOW:
        case MC_SALUTE:
        {
            const char *emote[2] = { "bow", "salute" };

            int index = macro->Code - MC_BOW;

            g_Orion.EmoteAction(emote[index]);

            break;
        }
        case MC_QUIT_GAME:
        {
            g_Orion.OpenLogOut();

            break;
        }
        case MC_ALL_NAMES:
        {
            g_Orion.AllNames();

            break;
        }
        case MC_LAST_TARGET:
        {
            if (WaitForTargetTimer == 0)
                WaitForTargetTimer = g_Ticks + WAIT_FOR_TARGET_DELAY;

            if (g_Target.IsTargeting())
            {
                if (g_Target.Type)
                    g_Target.SendLastTarget();
                else
                    g_Target.SendTargetObject(g_LastTargetObject);

                WaitForTargetTimer = 0;
            }
            else if (WaitForTargetTimer < g_Ticks)
                WaitForTargetTimer = 0;
            else
                result = MRC_BREAK_PARSER;

            break;
        }
        case MC_TARGET_SELF:
        {
            if (WaitForTargetTimer == 0)
                WaitForTargetTimer = g_Ticks + WAIT_FOR_TARGET_DELAY;

            if (g_Target.IsTargeting())
            {
                g_Target.SendTargetObject(g_PlayerSerial);

                WaitForTargetTimer = 0;
            }
            else if (WaitForTargetTimer < g_Ticks)
                WaitForTargetTimer = 0;
            else
                result = MRC_BREAK_PARSER;

            break;
        }
        case MC_ARM_DISARM:
        {
            int handIndex = 1 - (macro->SubCode - MSC_G4_LEFT_HAND);

            if (handIndex < 0 || handIndex > 1 || g_ObjectInHand.Enabled)
                break;

            if (itemInHand[handIndex])
            {
                CGameItem *objHand = g_World->FindWorldItem(itemInHand[handIndex]);

                if (objHand != NULL)
                {
                    g_Orion.PickupItem(objHand, 1, false);
                    g_Orion.EquipItem(g_PlayerSerial);
                }

                itemInHand[handIndex] = 0;
            }
            else
            {
                uint backpack = 0;
                CGameItem *objBackpack = g_Player->FindLayer(OL_BACKPACK);

                if (objBackpack != NULL)
                    backpack = objBackpack->Serial;

                if (!backpack)
                    break;

                CGameItem *objHand = g_Player->FindLayer(OL_1_HAND + handIndex);

                if (objHand != NULL)
                {
                    itemInHand[handIndex] = objHand->Serial;

                    g_Orion.PickupItem(objHand, 1, false);
                    g_Orion.DropItem(backpack, 0xFFFF, 0xFFFF, 0);

                    g_GumpManager.UpdateGump(g_PlayerSerial, 0, GT_PAPERDOLL);
                }
            }

            break;
        }
        case MC_WAIT_FOR_TARGET:
        {
            if (WaitForTargetTimer == 0)
                WaitForTargetTimer = g_Ticks + WAIT_FOR_TARGET_DELAY;

            if (g_Target.IsTargeting() || WaitForTargetTimer < g_Ticks)
                WaitForTargetTimer = 0;
            else
                result = MRC_BREAK_PARSER;

            break;
        }
        case MC_TARGET_NEXT:
        {
            CGameObject *obj =
                g_World->SearchWorldObject(g_LastTargetObject, 30, STO_MOBILES, SMO_NEXT);

            if (obj != NULL)
            {
                if (obj->NPC && !((CGameCharacter *)obj)->MaxHits)
                    CPacketStatusRequest(obj->Serial).Send();

                g_LastTargetObject = obj->Serial;
                g_LastAttackObject = obj->Serial;
            }

            break;
        }
        case MC_ATTACK_LAST:
        {
            g_Orion.Attack(g_LastAttackObject);

            break;
        }
        case MC_DELAY:
        {
            CMacroObjectString *mos = (CMacroObjectString *)macro;

            string str = mos->String;

            if (str.length())
                m_NextTimer = g_Ticks + std::atoi(str.c_str());

            break;
        }
        case MC_CIRCLE_TRANS:
        {
            g_ConfigManager.UseCircleTrans = !g_ConfigManager.UseCircleTrans;

            break;
        }
        case MC_CLOSE_GUMPS:
        {
            CGump *gump = (CGump *)g_GumpManager.m_Items;

            while (gump != NULL)
            {
                CGump *next = (CGump *)gump->m_Next;

                if (gump->GumpType == GT_OPTIONS)
                    g_OptionsMacroManager.Clear();

                if (gump->GumpType != GT_MENUBAR && gump->GumpType != GT_BUFF &&
                    (gump->GumpType != GT_GENERIC && !gump->NoClose))
                    g_GumpManager.RemoveGump(gump);

                gump = next;
            }

            break;
        }
        case MC_ALWAYS_RUN:
        {
            g_ConfigManager.AlwaysRun = !g_ConfigManager.AlwaysRun;

            break;
        }
        case MC_ENABLE_RANGE_COLOR:
        {
            g_ConfigManager.GrayOutOfRangeObjects = true;

            break;
        }
        case MC_DISABLE_RANGE_COLOR:
        {
            g_ConfigManager.GrayOutOfRangeObjects = false;

            break;
        }
        case MC_TOGGLE_RANGE_COLOR:
        {
            g_ConfigManager.GrayOutOfRangeObjects = !g_ConfigManager.GrayOutOfRangeObjects;

            break;
        }
        case MC_ATTACK_SELECTED_TARGET:
        {
            if (!g_ConfigManager.DisableNewTargetSystem && g_NewTargetSystem.Serial &&
                g_NewTargetSystem.Serial < 0x40000000)
                g_Orion.Attack(g_NewTargetSystem.Serial);

            break;
        }
        case MC_USE_SELECTED_TARGET:
        {
            if (!g_ConfigManager.DisableNewTargetSystem && g_NewTargetSystem.Serial)
                g_Orion.DoubleClick(g_NewTargetSystem.Serial);

            break;
        }
        case MC_CURRENT_TARGET:
        {
            if (!g_ConfigManager.DisableNewTargetSystem && g_NewTargetSystem.Serial)
            {
                if (WaitForTargetTimer == 0)
                    WaitForTargetTimer = g_Ticks + WAIT_FOR_TARGET_DELAY;

                if (g_Target.IsTargeting())
                {
                    g_Target.SendTargetObject(g_NewTargetSystem.Serial);

                    WaitForTargetTimer = 0;
                }
                else if (WaitForTargetTimer < g_Ticks)
                    WaitForTargetTimer = 0;
                else
                    result = MRC_BREAK_PARSER;
            }

            break;
        }
        case MC_TARGET_SYSTEM_ON_OFF:
        {
            g_ConfigManager.DisableNewTargetSystem = !g_ConfigManager.DisableNewTargetSystem;

            break;
        }
        case MC_BANDAGE_SELF:
        case MC_BANDAGE_TARGET:
        {
            CGameItem *bandage = g_Player->FindBandage();

            if (bandage != NULL)
            {
                if (macro->Code == MC_BANDAGE_SELF)
                    CPacketTargetSelectedObject(bandage->Serial, g_PlayerSerial).Send();
                else if (
                    !g_ConfigManager.DisableNewTargetSystem && g_NewTargetSystem.Serial &&
                    g_NewTargetSystem.Serial < 0x40000000)
                    CPacketTargetSelectedObject(bandage->Serial, g_NewTargetSystem.Serial).Send();
            }

            break;
        }
        case MC_SET_UPDATE_RANGE:
        case MC_MODIFY_UPDATE_RANGE:
        {
            CMacroObjectString *mos = (CMacroObjectString *)macro;

            string str = mos->String;

            if (str.length())
            {
                g_ConfigManager.UpdateRange = std::atoi(str.c_str());

                if (g_ConfigManager.UpdateRange < MIN_VIEW_RANGE)
                    g_ConfigManager.UpdateRange = MIN_VIEW_RANGE;
                else if (g_ConfigManager.UpdateRange > g_MaxViewRange)
                    g_ConfigManager.UpdateRange = g_MaxViewRange;
            }

            break;
        }
        case MC_INCREASE_UPDATE_RANGE:
        {
            g_ConfigManager.UpdateRange += 1;

            if (g_ConfigManager.UpdateRange > g_MaxViewRange)
                g_ConfigManager.UpdateRange = g_MaxViewRange;

            break;
        }
        case MC_DECREASE_UPDATE_RANGE:
        {
            g_ConfigManager.UpdateRange -= 1;

            if (g_ConfigManager.UpdateRange < MIN_VIEW_RANGE)
                g_ConfigManager.UpdateRange = MIN_VIEW_RANGE;

            break;
        }
        case MC_MAX_UPDATE_RANGE:
        {
            g_ConfigManager.UpdateRange = g_MaxViewRange;

            break;
        }
        case MC_MIN_UPDATE_RANGE:
        {
            g_ConfigManager.UpdateRange = MIN_VIEW_RANGE;

            break;
        }
        case MC_DEFAULT_UPDATE_RANGE:
        {
            g_ConfigManager.UpdateRange = g_MaxViewRange;

            break;
        }
        case MC_UPDATE_RANGE_INFO:
        {
            g_Orion.CreateTextMessageF(
                3, 0, "Current update range is %i", g_ConfigManager.UpdateRange);

            break;
        }
        case MC_SELECT_NEXT:
        case MC_SELECT_PREVEOUS:
        case MC_SELECT_NEAREST:
        {
            if (g_ConfigManager.DisableNewTargetSystem)
                break;

            SCAN_TYPE_OBJECT scanType = (SCAN_TYPE_OBJECT)(macro->SubCode - MSC_G7_HOSTILE);

            CGameObject *obj = g_World->SearchWorldObject(
                g_NewTargetSystem.Serial,
                10,
                scanType,
                (SCAN_MODE_OBJECT)(macro->Code - MC_SELECT_NEXT));

            if (obj != NULL)
            {
                g_GumpManager.CloseGump(g_NewTargetSystem.Serial, 0, GT_TARGET_SYSTEM);

                g_NewTargetSystem.Serial = obj->Serial;

                if (g_GumpManager.UpdateContent(g_NewTargetSystem.Serial, 0, GT_TARGET_SYSTEM) ==
                    NULL)
                {
                    if (g_NewTargetSystem.Serial < 0x40000000)
                        CPacketStatusRequest(g_NewTargetSystem.Serial).Send();

                    g_GumpManager.AddGump(new CGumpTargetSystem(
                        g_NewTargetSystem.Serial,
                        g_NewTargetSystem.GumpX,
                        g_NewTargetSystem.GumpY));
                }
            }
            else
            {
                const char *resultNames[5] = {
                    "Hostiles", "Party Members", "Followers", "Objects", "Mobiles"
                };

                g_Orion.CreateUnicodeTextMessageF(
                    g_ConfigManager.ChatFont,
                    0x038A,
                    "There are no %s on the screen to select.",
                    resultNames[scanType]);
            }

            break;
        }
        case MC_TOGGLE_BUICON_WINDOW:
        {
            g_ConfigManager.ToggleBufficonWindow = !g_ConfigManager.ToggleBufficonWindow;

            break;
        }
        case MC_INVOKE_VIRTURE:
        {
            uchar id = macro->SubCode - MSC_G5_HONOR + 31;

            CPacketInvokeVirtureRequest(id).Send();

            break;
        }
        case MC_PRIMARY_ABILITY:
        {
            CGumpAbility::OnAbilityUse(0);

            break;
        }
        case MC_SECONDARY_ABILITY:
        {
            CGumpAbility::OnAbilityUse(1);

            break;
        }
        case MC_EQUIP_LAST_WEAPON:
        {
            CPacketEquipLastWeapon().Send();
            break;
        }
        case MC_KILL_GUMP_OPEN:
        {
            g_Orion.CreateTextMessage(TT_SYSTEM, 0xFFFFFFFF, 3, 0x77, "That macro is not work now");

            break;
        }
        case MC_RESYNCHRONIZE:
        {
            CPacketResend().Send();
            break;
        }
        default:
            break;
    }

    return result;
}
