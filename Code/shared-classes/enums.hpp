#pragma once

enum RenderLayer {
    BackgroundLayer ,
    EditingSpaceBackgroundLayer,
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
    ReplaceFile ,
    Exit
};

enum BlockType {
    normal ,
    breakable ,
    item
};