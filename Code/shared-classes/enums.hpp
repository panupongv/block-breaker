#pragma once

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
    SaveFile ,
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
