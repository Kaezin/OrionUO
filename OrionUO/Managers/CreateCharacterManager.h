

#ifndef CREATECHARACTERMANAGER_H
#define CREATECHARACTERMANAGER_H

struct CC_HAIR_STYLE
{
    ushort GumpID;

    ushort GraphicID;

    string Name;
};

class CCreateCharacterManager
{
protected:
    bool m_Female = false;

public:
    bool GetFemale() { return m_Female; };
    void SetFemale(bool val);

protected:
    RACE_TYPE m_Race = RT_HUMAN;

public:
    RACE_TYPE GetRace() { return m_Race; };
    void SetRace(RACE_TYPE val);
    uchar HairStyle = 1;
    uchar BeardStyle = 0;
    ushort SkinTone = 0x03EA;
    ushort ShirtColor = 0x0084;
    ushort PantsColor = 0x035F;
    ushort HairColor = 0x044E;
    ushort BeardColor = 0x044E;

public:
    static const int HUMAN_MALE_HAIR_COUNT = 10;
    static const int HUMAN_FEMALE_HAIR_COUNT = 11;
    static const int HUMAN_MALE_FACIAL_HAIR_COUNT = 8;

    static const int HUMAN_SKIN_TONE_COUNT = 64;

    static const int HUMAN_HAIR_COLOR_COUNT = 48;

private:
    static const CC_HAIR_STYLE m_HumanMaleHairStyleTable[HUMAN_MALE_HAIR_COUNT];
    static const CC_HAIR_STYLE m_HumanFemaleHairStyleTable[HUMAN_FEMALE_HAIR_COUNT];
    static const CC_HAIR_STYLE m_HumanBeardStyleTable[HUMAN_MALE_FACIAL_HAIR_COUNT];

    static const ushort m_HumanSkinTone[HUMAN_SKIN_TONE_COUNT];

    static const ushort m_HumanHairColor[HUMAN_HAIR_COLOR_COUNT];

public:
    CCreateCharacterManager();
    ~CCreateCharacterManager();

    void Init();

    void Clear();

    int GetCurrentHairCount();

    int GetCurrentFacialHairCount();

    ushort GetBodyGump();

    ushort GetShirtGump();

    ushort GetPantsGump();

    ushort GetBootsGump();

    pushort GetSkinTonePtr();

    pushort GetHairColorPtr();

    CC_HAIR_STYLE GetHair(uchar pos) const;

    CC_HAIR_STYLE GetBeard(uchar pos) const;
};

extern CCreateCharacterManager g_CreateCharacterManager;

#endif
