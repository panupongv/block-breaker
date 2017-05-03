/*
 helper/enum.hpp
*/

#pragma once

enum MenuChoice {ENDLESS, CUSTOM, HIGHSCORE};

enum RenderLayer {
    BackgroundLayer ,
    EditingSpaceBackgroundLayer,
    EditingSpaceElementLayer,
    EditingSpaceAuraLayer,
    EditingSpacePinLayer,
    DraftBlockLayer,
    BlockLayer,
    PinLayer,
    PanelBackgroundLayer,
    PanelElementLayer,
    TitleLayer
};

enum PositioningMode {
    TopLeft ,
    Center
};

enum UpdateOperation {
    None,
    NewStage ,
    LoadStage ,
    SaveFileOperation ,
    ReplaceFileOperation ,
    Exit,
    ChangeColor,
    ChangeType
};

enum BlockType {
    normal ,
    breakable ,
    item
};

enum ItemType { ADDBALL, MARIOBALL, ROCKETITEM, EXPLOSIVE, FASTFORWARD, BEER };

