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
    SaveFileOperation ,
    ReplaceFileOperation ,
    Exit
};

enum BlockType {
    normal ,
    breakable ,
    item
};
